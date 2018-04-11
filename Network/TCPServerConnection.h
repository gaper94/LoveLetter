#ifndef TCP_SERVER_CONNECTION_H
#define TCP_SERVER_CONNECTION_H

#include "IConnection.h"

class TCPServerConnectionImpl;

class TCPServerConnection : public IConnection
{
public:
    TCPServerConnection(uint16_t port);
    ~TCPServerConnection();
    bool Run() final;
    void SendMsg(ConnectionId id, const Msg& msg) final;
    void Update() final;
    void Init(const ClientContext& ctx) final;
private:
    std::shared_ptr<TCPServerConnectionImpl> m_pImpl = nullptr;
};

#endif // TCP_SERVER_CONNECTION_H
