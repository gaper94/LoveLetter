 #ifndef CLIENT_GAME_H
#define CLIENT_GAME_H

#include "../Network/IConnection.h"
#include <functional>

class ClientGame
{
public:

    using Msg = IConnection::Msg;
    using MsgSender = std::function<void(const Msg&)>;

    void Init(MsgSender serverMsgSender, MsgSender viewMsgSender);
    void Update();
    void OnMsgReceived(const Msg& msg);
private:
    void _sendMsgToServer(const Msg& msg);
    void _sendMsgToView(const Msg& msg);
    //
    MsgSender m_serverMsgSender = nullptr;
    MsgSender m_viewMsgSender = nullptr;
};

#endif // CLIENT_GAME_H
