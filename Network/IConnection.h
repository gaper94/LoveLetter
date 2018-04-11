#ifndef ICONNECTION_H
#define ICONNECTION_H

#include "../Msg/GenericMsg.h"
#include <memory>

class IConnection
{
public:
    using Ptr = std::shared_ptr<IConnection>;
    using Msg = GenericMsg;
    using ConnectionId = int16_t;
    using OnConnect = std::function<void(ConnectionId)>;
    using OnDisconnect = OnConnect;
    using OnMsg = std::function<void(ConnectionId, const Msg&)>;

    static constexpr ConnectionId InvalidConnectionId = -1;

    struct ClientContext
    {
        OnConnect onConnect = nullptr;
        OnDisconnect onDisconnect = nullptr;
        OnMsg onMsg = nullptr;
    };

    ~IConnection(){}
    virtual void Init(const ClientContext& ctx);
    virtual bool Run() = 0;
    virtual void SendMsg(ConnectionId id, const Msg& msg) = 0;
    virtual void Update() = 0;
protected:
    ClientContext m_ctx;
};

#endif // ICONNECTION_H
