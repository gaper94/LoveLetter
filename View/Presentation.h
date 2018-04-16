#ifndef VIEW_PRESENTATION_H
#define VIEW_PRESENTATION_H

#include <functional>
#include "../Network/IConnection.h"

class ViewPresentation
{
public:
    using Msg = IConnection::Msg;
    using MsgSender = std::function<void(const Msg&)>;

    void Init(MsgSender msgSender);
    void OnMsgReceived(const Msg& msg);
    void Update();

private:
    void _sendMsgToController(const Msg& msg);
    MsgSender m_controllerSender = nullptr;
};


#endif // VIEW_PRESENTATION_H
