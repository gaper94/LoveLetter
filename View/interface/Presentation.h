#ifndef VIEW_PRESENTATION_H
#define VIEW_PRESENTATION_H

#include <functional>
#include "../../Network/IConnection.h"
#include <QApplication>
#include "mainwindow.h"

class ViewPresentation
{
public:
    using Msg = IConnection::Msg;
    using MsgSender = std::function<void(const Msg&)>;

    ViewPresentation(int argc, char** argv);
    void Init(MsgSender msgSender);
    void OnMsgReceived(const Msg& msg);
    void Update();
    void OnControllerConnected();
    void OnControllerDisconnected();

private:
    int m_argc = 0;
    char** m_argv = nullptr;
    QApplication m_application;
    MainWindow m_mainWindow;
    void _sendMsgToController(const Msg& msg);
    MsgSender m_controllerSender = nullptr;
};


#endif // VIEW_PRESENTATION_H
