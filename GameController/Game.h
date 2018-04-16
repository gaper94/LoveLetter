 #ifndef CLIENT_GAME_H
#define CLIENT_GAME_H

#include "../Network/IConnection.h"
#include <functional>

class ClientGame
{
public:

    enum class State
    {
        Invalid,
        Initing,
        WaitingForCredentials,
        Playing,
    };

    using Msg = IConnection::Msg;
    using MsgSender = std::function<void(const Msg&)>;

    void Init(MsgSender serverMsgSender, MsgSender viewMsgSender);
    void Update();
    void OnMsgReceived(const Msg& msg);
    void RequestCredentials();
private:
    void _sendInitPlayersMsg();
    void _startGame();
    void _sendMsgToServer(const Msg& msg);
    void _sendMsgToView(const Msg& msg);
    //
    MsgSender m_serverMsgSender = nullptr;
    MsgSender m_viewMsgSender = nullptr;
    State m_eState = State::Invalid;
    std::string m_playerName;
};

#endif // CLIENT_GAME_H
