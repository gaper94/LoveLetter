#include "GameServer.h"
#include "../Network/Network.h"
#include "../Network/NetworkDefines.h"
#include <algorithm>
#include <cstdlib>

bool GameServer::Init(const Arguments& args)
{
    bool result = true;

    auto portArg = std::find_if(args.begin(), args.end(), [](const Argument& arg)
    {
        if(arg.first == "port")
        {
            return true;
        }
        return false;
    });

    if(portArg != args.end())
    {
        auto port = atoi((*portArg).second.c_str());
        m_gameControllerConnection = Network::CreateTCPServer(port);
    }
    else
    {
        m_gameControllerConnection = Network::CreateTCPServer(BACK_END_TO_SERVER_PORT);
    }

    if(m_gameControllerConnection != nullptr)
    {
        IConnection::ClientContext ctx;

        ctx.onConnect = [this](IConnection::ConnectionId id)
        {
            _onGameControllerConnect(id);
        };

        ctx.onDisconnect = [this](IConnection::ConnectionId id)
        {
            _onGameControllerDisconnect(id);
        };

        ctx.onMsg = [this](IConnection::ConnectionId id, const IConnection::Msg& msg)
        {
            _onGameControllerMsgReceived(id, msg);
        };

        m_gameControllerConnection->Init(ctx);

        if(m_gameControllerConnection->Run() == false)
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }
    //
    return result;
}

void GameServer::Update()
{
    if(m_gameControllerConnection != nullptr)
    {
        m_gameControllerConnection->Update();
    }
}

void GameServer::_onGameControllerConnect(IConnection::ConnectionId id)
{
    m_gameControllerConnectionId = id;
}

void GameServer::_onGameControllerDisconnect(IConnection::ConnectionId id)
{
    m_gameControllerConnectionId = IConnection::InvalidConnectionId;
}

void GameServer::_onGameControllerMsgReceived(IConnection::ConnectionId id,
                                              const IConnection::Msg& msg)
{
}

void GameServer::_sendMsgToGameController(IConnection::ConnectionId id,
                                          const IConnection::Msg& msg)
{
    if(m_gameControllerConnectionId != IConnection::InvalidConnectionId)
    {
        m_gameControllerConnection->SendMsg(id, msg);
    }
}
