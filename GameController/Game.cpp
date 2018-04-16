#include "Game.h"

void ClientGame::Init(MsgSender serverMsgSender, MsgSender viewMsgSender)
{
    m_serverMsgSender = serverMsgSender;
    m_viewMsgSender = viewMsgSender;
}

void ClientGame::Update()
{
}

void ClientGame::OnMsgReceived(const Msg& msg)
{
    // Relevant only to the view, just forward it
    if(msg.name == "discarted_cards")
    {
        _sendMsgToView(msg);
    }
    else if(msg.name == "defausse_card")
    {
        _sendMsgToView(msg);
    }
    else if(msg.name == "input_request")
    {
        _sendMsgToView(msg);
    }
    else if(msg.name == "input_response")
    {
        _sendMsgToServer(msg);
    }
}

void ClientGame::_sendMsgToServer(const Msg& msg)
{
    if(m_serverMsgSender != nullptr)
    {
        m_serverMsgSender(msg);
    }
}

void ClientGame::_sendMsgToView(const Msg& msg)
{
    if(m_viewMsgSender != nullptr)
    {
        m_viewMsgSender(msg);
    }
}
