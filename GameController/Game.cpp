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
    else if(msg.name == "players_config")
    {
        _sendMsgToServer(msg);
    }
    else if(msg.name == "start_game")
    {
        _sendMsgToServer(msg);
    }
    else if(msg.name == "cards_info")
    {
        _sendMsgToView(msg);
    }
}

void ClientGame::RequestCredentials()
{
    Msg msg;
    msg.name = "input_request";
    std::string requestMsg = "Please, enter your name: ";
    msg.AddValue("request_msg", requestMsg);
    m_eState = State::WaitingForCredentials;
    _sendMsgToView(msg);
}

void ClientGame::_sendInitPlayersMsg()
{
    if(m_playerName.empty() ==  true)
    {
        RequestCredentials();
        return;
    }
    //
    Msg msg;
    msg.name = "players_config";

    int32_t numberOfPlayers = 4;
    msg.AddValue("number_of_players", numberOfPlayers);
    msg.AddValue("player_name", m_playerName);
    _sendMsgToServer(msg);
}

void ClientGame::_startGame()
{
    Msg msg;
    msg.name = "start_game";
    _sendMsgToServer(msg);
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
