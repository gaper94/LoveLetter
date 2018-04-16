#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "../App/Application.h"
#include "../Network/IConnection.h"
#include "Game.h"
#include <chrono>

class GameController : public Application
{
public:

    bool Init(const Arguments& args) final;
    void Update() final;
private:

    void _onViewConnect(IConnection::ConnectionId id);
    void _onServerConnect(IConnection::ConnectionId id);

    void _onViewDisconnect(IConnection::ConnectionId id);
    void _onServerDisconnect(IConnection::ConnectionId id);

    void _onViewMsgReceived(IConnection::ConnectionId id, const IConnection::Msg& msg);
    void _onServerMsgReceived(IConnection::ConnectionId id, const IConnection::Msg& msg);

    void _sendToView(const IConnection::Msg& msg);
    void _sendToServer(const IConnection::Msg& msg);

    IConnection::Ptr m_viewConnection = nullptr;
    IConnection::ConnectionId m_viewConnectionId = IConnection::InvalidConnectionId;
    IConnection::Ptr m_serverConnection = nullptr;
    IConnection::ConnectionId m_serverConnectionId = IConnection::InvalidConnectionId;
    //
    ClientGame m_clientGame;
};

#endif // GAME_CONTROLLER_H
