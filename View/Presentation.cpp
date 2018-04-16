#include "Presentation.h"
#include <iostream>

void ViewPresentation::Init(MsgSender msgSender)
{
    m_controllerSender = msgSender;
}

void ViewPresentation::OnMsgReceived(const Msg& msg)
{
    if(msg.name == "input_request")
    {
        std::string requestMsg;
        msg.GetValue("request_msg", requestMsg);
        std::cout << requestMsg;
        std::string input;
        std::cin >> input;
        //
        Msg response;
        response.name = "input_response";
        response.AddValue("input", input);
        _sendMsgToController(response);
    }
    else if(msg.name == "info_message")
    {
        std::string infoMsg;
        msg.GetValue("info_msg", infoMsg);
        std::cout << infoMsg;
    }
}

void ViewPresentation::Update()
{
}

void ViewPresentation::_sendMsgToController(const Msg& msg)
{
    if(m_controllerSender != nullptr)
    {
        m_controllerSender(msg);
    }
}
