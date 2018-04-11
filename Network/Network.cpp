#include "Network.h"
#include "TCPServerConnection.h"
#include "TCPClientConnection.h"

namespace Network
{

IConnection::Ptr CreateTCPServer(uint16_t port)
{
    return std::make_shared<TCPServerConnection>(port);
}

IConnection::Ptr CreateTCPClient(const std::string& address, uint16_t port)
{
    return std::make_shared<TCPClientConnection>(address, port);
}

}
