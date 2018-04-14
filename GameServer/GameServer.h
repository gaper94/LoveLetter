#ifndef GAME_SERVER_H
#define GAME_SERVER_H

#include "../App/Application.h"
#include "../Network/IConnection.h"
#include <vector>
#include "Game.h"

class GameServer : public Application
{
public:

    bool Init(const Arguments& args) final;
    void Update() final;

//private:

    void _onGameControllerConnect(IConnection::ConnectionId id);
    void _onGameControllerDisconnect(IConnection::ConnectionId id);
    void _onGameControllerMsgReceived(IConnection::ConnectionId id,
                                      const IConnection::Msg& msg);
    void _sendMsgToGameController(IConnection::ConnectionId id,
                                  const IConnection::Msg& msg);

    IConnection::Ptr m_gameControllerConnection = nullptr;
    std::vector<IConnection::ConnectionId> m_activeConnections;
    ServerGame m_serverGame;
};

#endif // GAME_SERVER_H
