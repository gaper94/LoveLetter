#include "TCPClientConnection.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

TCPClientConnection::TCPClientConnection( const std::string& address,
                                          uint16_t port)
 : m_address(address), m_port(port)
{
}

TCPClientConnection::~TCPClientConnection()
{
    _onServerDisconnect();
}

bool TCPClientConnection::Run()
{
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    std::string strPort = std::to_string(m_port);
    if ((rv = getaddrinfo(m_address.c_str(), strPort.c_str(), &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for(p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((m_fd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1)
        {
            continue;
        }
        //
        if (connect(m_fd, p->ai_addr, p->ai_addrlen) == -1)
        {
            _shutDownSocket();
            continue;
        }
        break;
    }

    if(m_fd < 0)
    {
        return false;
    }

    fcntl(m_fd, F_SETFL, O_NONBLOCK);
    if(m_ctx.onConnect != nullptr)
    {
        m_ctx.onConnect(0);
    }

    return true;
}

void TCPClientConnection::SendMsg(ConnectionId, const Msg& msg)
{
    if(m_fd < 0)
    {
        return;
    }

    // First send size of message
    Serializer os;
    os << msg;
    uint32_t msgSize = os.GetBuffer().size();
    uint32_t sendItems = write(m_fd, &msgSize, sizeof(msgSize));

    if(sendItems == 0)
    {
        // Can't write to socket
        return;
    }

    uint32_t currentPos = 0;
    while (msgSize > 0)
    {
        sendItems = write(m_fd, os.GetBuffer().data() + currentPos, msgSize);
        if(sendItems == 0)
        {
            break;
        }
        currentPos += sendItems;
        msgSize -= sendItems;
    }
}

void TCPClientConnection::Update()
{
    if(m_fd < 0)
    {
        return;
    }

    if(m_pendingMessage == false)
    {
        auto receivedItems = read(m_fd, &m_msgSize, sizeof(m_msgSize));
        if(receivedItems > 0)
        {
            m_rawMsg.resize(m_msgSize);
            m_pendingMessage = true;
        }
        else if(receivedItems == 0)
        {
            _onServerDisconnect();
        }
    }
    else
    {
        auto bytesToReceive = m_msgSize;
        uint32_t currentPos = 0;
        auto receivedItems = read(m_fd, m_rawMsg.data() + currentPos, m_msgSize);
        if(receivedItems > 0)
        {
            bytesToReceive -= receivedItems;
            currentPos += receivedItems;
            while (bytesToReceive > 0)
            {
                receivedItems = read(m_fd, m_rawMsg.data() + currentPos, m_msgSize);
                currentPos += receivedItems;
                bytesToReceive -= receivedItems;
            }
            if(m_ctx.onMsg != nullptr)
            {
                Deserializer is;
                is.Load(m_rawMsg);
                Msg msg;
                is >> msg;
                m_ctx.onMsg(0, msg);
            }
            m_pendingMessage = false;
        }
        else if(receivedItems == 0)
        {
            _onServerDisconnect();
        }
    }
}

void TCPClientConnection::_shutDownSocket()
{
    if(m_fd > 0)
    {
        close(m_fd);
        m_fd = -1;
    }
}

void TCPClientConnection::_onServerDisconnect()
{
    _shutDownSocket();
    //
    if(m_ctx.onDisconnect != nullptr)
    {
        m_ctx.onDisconnect(0);
    }
}
