#include "View.h"
#include "../Network/Network.h"
#include "../Network/NetworkDefines.h"

bool View::Init(const Arguments&)
{
    bool result = true;

    m_controllerConnection = Network::CreateTCPClient("localhost", VIEW_TO_BACK_END_PORT);
    if(m_controllerConnection != nullptr)
    {
        IConnection::ClientContext ctx;

        ctx.onConnect = [this](IConnection::ConnectionId id)
        {
            _onControllerConnect(id);
        };

        ctx.onDisconnect = [this](IConnection::ConnectionId id)
        {
            _onControllerDisconnect(id);
        };

        ctx.onMsg = [this](IConnection::ConnectionId id, const IConnection::Msg& msg)
        {
            _onControllerMsgReceived(id, msg);
        };

        m_controllerConnection->Init(ctx);

        // Maybe add retry mechanism ?
        if(m_controllerConnection->Run() == false)
        {
            m_lastConnectionRetry = std::chrono::steady_clock::now();
            m_controllerConnectionId = IConnection::InvalidConnectionId;
            result = false;
        }
    }
    return result;
}

void View::Update()
{
    if(m_controllerConnectionId != IConnection::InvalidConnectionId)
    {
        m_controllerConnection->Update();
    }
    else
    {
        auto now = std::chrono::steady_clock::now();
        if((now - m_lastConnectionRetry) > std::chrono::seconds(10))
        {
            m_lastConnectionRetry = now;
            m_controllerConnection->Run();
        }
    }
}

void View::_onControllerConnect(IConnection::ConnectionId id)
{
    m_controllerConnectionId = id;
}

void View::_onControllerDisconnect(IConnection::ConnectionId id)
{
    m_controllerConnectionId = IConnection::InvalidConnectionId;
}

void View::_onControllerMsgReceived(IConnection::ConnectionId id, const IConnection::Msg& msg)
{
}

void View::_sendMsgToController(IConnection::ConnectionId id, const IConnection::Msg& msg)
{
    if(m_controllerConnection != nullptr)
    {
        m_controllerConnection->SendMsg(id, msg);
    }
}
