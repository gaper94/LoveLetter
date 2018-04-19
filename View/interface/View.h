#ifndef VIEW_H
#define VIEW_H

#include <chrono>
#include "../../App/Application.h"
#include "../../Network/IConnection.h"
#include "Presentation.h"

class View : public Application
{
public:
    View(int argc, char** argv);
    bool Init(const Arguments& args) final;
    void Update() final;
private:

    void _onControllerConnect(IConnection::ConnectionId id);
    void _onControllerDisconnect(IConnection::ConnectionId id);
    void _onControllerMsgReceived(IConnection::ConnectionId id, const IConnection::Msg& msg);

    void _sendMsgToController(const IConnection::Msg& msg);

    IConnection::Ptr m_controllerConnection = nullptr;
    IConnection::ConnectionId m_controllerConnectionId = IConnection::InvalidConnectionId;
    std::chrono::steady_clock::time_point m_lastConnectionRetry;
    //
    ViewPresentation m_presentation;
};

#endif // VIEW_H
