#include "TCPServerConnection.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

class TCPServerConnectionImpl
{
public:
    TCPServerConnectionImpl(uint16_t port)
        : m_port(port)
    {
        FD_ZERO(&master);
        FD_ZERO(&read_fds);
    }

    bool Run()
    {
        struct addrinfo hints, *ai, *p;
        memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        int rv = 0;
        std::string strPort = std::to_string(m_port);
        if ((rv = getaddrinfo(nullptr, strPort.c_str(), &hints, &ai)) != 0)
        {
            return false;
        }

        int yes = 1;
        for(p = ai; p != nullptr ; p = p->ai_next)
        {
            listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
            if (listener < 0)
            {
                continue;
            }

            setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
            if (bind(listener, p->ai_addr, p->ai_addrlen) < 0)
            {
                close(listener);
                continue;
            }
            break;
        }

        if(p == nullptr)
        {
            return false;
        }

        freeaddrinfo(ai);

        if(listen(listener, 10) == -1)
        {
            return false;
        }

        FD_SET(listener, &master);

        // keep track of biggest fd
        fdmax = listener;

        return true;
    }

    void Update()
    {
        static IConnection::ConnectionId connections;
        read_fds = master;

        struct timeval wt;
        wt.tv_usec = 1000;
        if(select(fdmax + 1, &read_fds, nullptr, nullptr, &wt) == -1)
        {
            return;
        }

        socklen_t addrlen;
        struct sockaddr_storage remoteaddr;
        int newfd = -1;

        // Look into existings connections
        for(int i = 0; i <= fdmax ; i++)
        {
            if(FD_ISSET(i, &read_fds))
            {
                // New connection
                if(i == listener)
                {
                    addrlen = sizeof(remoteaddr);
                    newfd = accept(listener, (struct sockaddr*)&remoteaddr, &addrlen);

                    if(newfd == -1)
                    {
                        continue;
                    }
                    else
                    {
                        FD_SET(newfd, &master);
                        fdmax = std::max(fdmax, newfd);
                        m_connetions[newfd] = ++connections;

                        if(ctx.onConnect != nullptr)
                        {
                            ctx.onConnect(connections);
                        }
                    }
                }
                else
                {
                    if(pendingMessage == false)
                    {
                        _checkForMsgSize(i);
                    }
                    else
                    {
                        _checkForPendingMsg(i);
                    }
                }
            }
        }
    }

    void _checkForMsgSize(int fd)
    {
        int bytesReceived = -1;
        if((bytesReceived = recv(fd, &msgSize, sizeof(msgSize), 0)) <= 0)
        {
            // connection close by client
            close(fd);
            FD_CLR(fd, &master);
            auto clientId = m_connetions[fd];
            m_connetions.erase(fd);

            if(ctx.onDisconnect != nullptr)
            {
                ctx.onDisconnect(clientId);
            }
        }
        else
        {
            m_rawMsg.clear();
            m_rawMsg.resize(msgSize);
            pendingMessage = true;
        }
    }

    void _checkForPendingMsg(int fd)
    {
        int bytesReceived = -1;
        if((bytesReceived = recv(fd, m_rawMsg.data(), msgSize, 0)) <= 0)
        {
            // connection close by client
            close(fd);
            FD_CLR(fd, &master);
            auto clientId = m_connetions[fd];
            m_connetions.erase(fd);

            if(ctx.onDisconnect != nullptr)
            {
                ctx.onDisconnect(clientId);
            }
        }
        else
        {
            uint32_t bytesToReceive = msgSize - bytesReceived;
            uint32_t currentPos = bytesReceived;
            while(bytesToReceive > 0)
            {
                bytesReceived = recv(fd, m_rawMsg.data() + currentPos, bytesToReceive, 0);
                currentPos += bytesReceived;
                bytesToReceive -= bytesReceived;
            }
            Deserializer is;
            is.Load(m_rawMsg);
            IConnection::Msg msg;
            is >> msg;
            auto connectionId = m_connetions[fd];
            if(ctx.onMsg != nullptr)
            {
                ctx.onMsg(connectionId, msg);
            }
            pendingMessage = false;
        }
    }

    void _sendMsg(IConnection::ConnectionId id,
                  const std::vector<uint8_t>& msg)
    {
        int fdToSend = -1;
        for(auto& connection : m_connetions)
        {
            if(connection.second == id)
            {
                fdToSend = connection.first;
                break;
            }
        }

        uint32_t msgSize = msg.size();
        uint32_t sendItems = write(fdToSend, &msgSize, sizeof(msgSize));

        if(sendItems == 0)
        {
            // Can't write to socket
            return;
        }

        uint32_t currentPos = 0;
        while (msgSize > 0)
        {
            sendItems = write(fdToSend, msg.data() + currentPos, msgSize);
            if(sendItems == 0)
            {
                break;
            }
            currentPos += sendItems;
            msgSize -= sendItems;
        }
    }

    uint16_t m_port;
    IConnection::ClientContext ctx;
    fd_set master;
    fd_set read_fds;
    int fdmax;
    int listener;
    bool pendingMessage = false;
    std::vector<uint8_t> m_rawMsg;
    uint32_t msgSize{};

    std::map<int, IConnection::ConnectionId> m_connetions;
};

TCPServerConnection::TCPServerConnection(uint16_t port)
{
    m_pImpl = std::make_shared<TCPServerConnectionImpl>(port);
}

TCPServerConnection::~TCPServerConnection()
{
}

void TCPServerConnection::Init(const ClientContext& ctx)
{
    IConnection::Init(ctx);
    if(m_pImpl != nullptr)
    {
        m_pImpl->ctx = ctx;
    }
}

bool TCPServerConnection::Run()
{
    m_pImpl->ctx = m_ctx;
    return m_pImpl->Run();
}

void TCPServerConnection::SendMsg(ConnectionId id, const Msg& msg)
{
    Serializer os;
    os << msg;
    m_pImpl->_sendMsg(id, os.GetBuffer());
}

void TCPServerConnection::Update()
{
    m_pImpl->Update();
}
