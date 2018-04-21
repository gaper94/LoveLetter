#include "Presentation.h"
#include <iostream>

ViewPresentation::ViewPresentation(int argc, char** argv)
 : m_argc(argc), m_argv(argv), m_application(m_argc, m_argv), m_mainWindow()
{
}

void ViewPresentation::Init(MsgSender msgSender)
{
    m_controllerSender = msgSender;
    m_mainWindow.show();
    m_mainWindow.SetMsgSender(msgSender);
}

void ViewPresentation::OnMsgReceived(const Msg& msg)
{
    m_mainWindow.OnMsgReceived(msg);
}

void ViewPresentation::Update()
{
    m_application.processEvents();
}

void ViewPresentation::OnControllerConnected()
{
    m_mainWindow.OnControllerConnect();
}

void ViewPresentation::OnControllerDisconnected()
{
        m_mainWindow.OnControllerDisconnect();
}

void ViewPresentation::_sendMsgToController(const Msg& msg)
{
    if(m_controllerSender != nullptr)
    {
        m_controllerSender(msg);
    }
}
