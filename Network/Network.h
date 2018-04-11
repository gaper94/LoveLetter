#ifndef NETWORK_H
#define NETWORK_H

#include "IConnection.h"
#include <stdint.h>

namespace Network
{

IConnection::Ptr CreateTCPServer(uint16_t port);
IConnection::Ptr CreateTCPClient(const std::string& address, uint16_t port);

}

#endif // NETWORK_H
