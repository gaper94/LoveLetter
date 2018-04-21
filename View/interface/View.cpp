#include "View.h"
#include "../../Network/Network.h"
#include "../../Network/NetworkDefines.h"

View::View(int argc, char** argv)
    : m_presentation(argc, argv)
{
}

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
            m_presentation.OnControllerConnected();
        };

        ctx.onDisconnect = [this](IConnection::ConnectionId id)
        {
            _onControllerDisconnect(id);
            m_presentation.OnControllerConnected();
        };

        ctx.onMsg = [this](IConnection::ConnectionId id, const IConnection::Msg& msg)
        {
            _onControllerMsgReceived(id, msg);
        };

        m_controllerConnection->Init(ctx);

        if(m_controllerConnection->Run() == false)
        {
            m_lastConnectionRetry = std::chrono::steady_clock::now();
            m_controllerConnectionId = IConnection::InvalidConnectionId;
            result = true;
        }
    }
    //
    auto controllerSender = [this](const IConnection::Msg& msg)
    {
        _sendMsgToController(msg);
    };
    //
    m_presentation.Init(controllerSender);

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
    m_presentation.Update();
}

void View::_onControllerConnect(IConnection::ConnectionId id)
{
    m_controllerConnectionId = id;
    m_presentation.OnControllerConnected();
}

void View::_onControllerDisconnect(IConnection::ConnectionId)
{
    m_controllerConnectionId = IConnection::InvalidConnectionId;
}

void View::_onControllerMsgReceived(IConnection::ConnectionId, const IConnection::Msg& msg)
{
    m_presentation.OnMsgReceived(msg);
}

void View::_sendMsgToController(const IConnection::Msg& msg)
{
    if(m_controllerConnectionId != IConnection::InvalidConnectionId)
    {
        m_controllerConnection->SendMsg(m_controllerConnectionId, msg);
    }
}
