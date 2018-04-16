#include "GameController.h"
#include "../Network/Network.h"
#include "../Network/NetworkDefines.h"
#include <algorithm>
#include <iostream>

bool GameController::Init(const Arguments& args)
{
    bool result = true;

    // Init view connection
    m_viewConnection = Network::CreateTCPServer(VIEW_TO_BACK_END_PORT);
    if(m_viewConnection != nullptr)
    {
        IConnection::ClientContext ctx;
        ctx.onConnect = [this](IConnection::ConnectionId id)
        {
            _onViewConnect(id);
        };

        ctx.onDisconnect = [this](IConnection::ConnectionId id)
        {
            _onViewDisconnect(id);
        };

        ctx.onMsg = [this](IConnection::ConnectionId id, const IConnection::Msg& msg)
        {
            _onViewMsgReceived(id, msg);
        };

        m_viewConnection->Init(ctx);
        if(m_viewConnection->Run() == false)
        {
            result = false;
        }
    }

    // Init server connection
    auto networkArg = std::find_if(args.begin(), args.end(), [](const Argument& arg)
    {
        if(arg.first == "addr")
        {
            return true;
        }
        return false;
    });

    auto portArg = std::find_if(args.begin(), args.end(), [](const Argument& arg)
    {
        if(arg.first == "port")
        {
            return true;
        }
        return false;
    });

    if(networkArg != args.end() && portArg != args.end())
    {
        auto address = (*networkArg).first;
        auto port = atoi((*portArg).first.c_str());
        m_serverConnection = Network::CreateTCPClient(address, port);
    }
    else
    {
        // Use default network
        m_serverConnection = Network::CreateTCPClient("localhost", BACK_END_TO_SERVER_PORT);
    }

    if(m_serverConnection != nullptr)
    {
        IConnection::ClientContext ctx;

        ctx.onConnect = [this](IConnection::ConnectionId id)
        {
            _onServerConnect(id);
        };

        ctx.onDisconnect = [this](IConnection::ConnectionId id)
        {
            _onServerDisconnect(id);
        };

        ctx.onMsg = [this](IConnection::ConnectionId id, const IConnection::Msg& msg)
        {
            _onServerMsgReceived(id, msg);
        };

        m_serverConnection->Init(ctx);

        // Add retry mechanism ?
        if(m_serverConnection->Run() == false)
        {
            result = false;
        }
    }
    //
    auto serverSender = [this](const IConnection::Msg& msg)
    {
        _sendToServer(msg);
    };
    auto viewSender = [this](const IConnection::Msg& msg)
    {
        _sendToView(msg);
    };
    m_clientGame.Init(serverSender, viewSender);

    return result;
}


void GameController::Update()
{
    if(m_serverConnection != nullptr)
    {
        m_serverConnection->Update();
    }
    //
    if(m_viewConnection != nullptr)
    {
        m_viewConnection->Update();
    }
}

void GameController::_onViewConnect(IConnection::ConnectionId id)
{
    m_viewConnectionId = id;
    m_clientGame.RequestCredentials();
}

void GameController::_onServerConnect(IConnection::ConnectionId id)
{
    m_serverConnectionId = id;
}

void GameController::_onViewDisconnect(IConnection::ConnectionId id)
{
    m_viewConnectionId = IConnection::InvalidConnectionId;
}

void GameController::_onServerDisconnect(IConnection::ConnectionId)
{
    m_serverConnectionId = IConnection::InvalidConnectionId;
}

void GameController::_onViewMsgReceived(IConnection::ConnectionId,
                                        const IConnection::Msg& msg)
{
    m_clientGame.OnMsgReceived(msg);
}

void GameController::_onServerMsgReceived(IConnection::ConnectionId,
                                          const IConnection::Msg& msg)
{
    m_clientGame.OnMsgReceived(msg);
}

void GameController::_sendToView(const IConnection::Msg& msg)
{
    if(m_viewConnection != nullptr && m_viewConnectionId != -1)
    {
        m_viewConnection->SendMsg(m_viewConnectionId, msg);
    }
}

void GameController::_sendToServer(const IConnection::Msg& msg)
{
    if(m_serverConnection != nullptr && m_serverConnectionId != -1)
    {
        m_serverConnection->SendMsg(m_serverConnectionId, msg);
    }
}
