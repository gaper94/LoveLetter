#ifndef TCP_CLIENT_CONNECTION
#define TCP_CLIENT_CONNECTION

#include "IConnection.h"
#include <stdint.h>

class TCPClientConnection : public IConnection
{
public:
    TCPClientConnection(const std::string& address,
                        uint16_t port);
    ~TCPClientConnection();
    bool Run() final;
    void SendMsg(ConnectionId id, const Msg& msg) final;
    void Update() final;
private:
    void _shutDownSocket();
    void _onServerDisconnect();
    std::string m_address;
    uint16_t m_port;
    int32_t m_fd = -1;
    bool m_pendingMessage = false;
    std::vector<uint8_t> m_rawMsg;
    uint32_t m_msgSize{};
};

#endif // TCP_CLIENT_CONNECTION
