#include "Game.h"
#include <iostream>
#include "../GameCommon/GameUtils.h"
#include "ServerDebug.h"
#include <memory>
#include <algorithm>

void ServerGame::Init(MsgSender msgSender)
{
    m_msgSender = msgSender;
}

void ServerGame::StartGame()
{
    m_gameState = GameState::InProcess;
    _startGame();
}

void ServerGame::ForceStopGame()
{
}

void ServerGame::InitPlayers(const Msg& msg)
{
    if(msg.name != "players_config")
    {
        return;
    }

    m_numberOfPlayers = 0;
    msg.GetValue("number_of_players", m_numberOfPlayers);
    if(m_numberOfPlayers < 2)
    {
        LOG("Invalid number of players");
        return;
    }
    //
    std::string playerName;
    if(msg.GetValue("player_name", playerName) == false)
    {
        LOG("Missing player name");
        return;
    }
    //
    m_players.clear();
    m_players.push_back(std::make_shared<Player>(playerName));
    m_playedCards.push_back({m_players.back(), {}});
    //
    _addAIPlayers();
}

bool ServerGame::CanStartGame()
{
    if(m_players.size() == 0 || m_gameState != GameState::Waiting)
    {
        return false;
    }
    return true;
}

void ServerGame::Update()
{

}

void ServerGame::_startGame()
{
    bool gameIsRunning = true;
    while (gameIsRunning == true)
    {
        Deck deck;
        deck.InitDeck();
        _playRound(deck);
        //
        bool hasWinner = _checkForWinner();
        gameIsRunning = hasWinner == true ? false : true;
        _prepareForNextRound();
    }

    auto winner = _getWinner();
    std::cout << "The winner is ";
    winner->PrintName();
    std::cout << std::endl;
    std::cout << "The final results are :" << std::endl;
    for(auto player : m_players)
    {
        std::cout << player->GetName() << " have " << player->GetNumberOfPoints() << " point(s) " << std::endl;
    }
}

void ServerGame::_playRound(const Deck& _deck)
{
    Deck deck = _deck;
    Card c;
    bool playerExist;
    m_defausse = deck.PickCard();
    _printDefausse();

    // When game is with two players, remove some cards
    std::vector<Card> discartedCards;
    if(_playersAlive() == 2)
    {
        for(size_t i = 0; i < 3; i++)
        {
            auto discartedCard = deck.PickCard();
            discartedCards.push_back(discartedCard);
            std::string logMsg = "Discarted card ";
            logMsg += Utils::CardTypeToString(discartedCard.type);
            LOG(logMsg);
        }
    }
    //
    Msg msg;
    msg.name = "discarted_cards";
    msg.AddValue("cards", discartedCards);
    _sendMsg(msg);

    // First deal one card for every player
    for(int i = 0; i <m_numberOfPlayers; i++)
    {
        auto pickedCard1 = deck.PickCard();
        m_players.at(i)->AddCard(pickedCard1);
    }

    while(deck.SizeDeck() > 0)
    {
        if( _playersAlive() <= 1)
        {
           break;
        }

        for(int i =0  ; i <m_numberOfPlayers; i++)
        {
            if(m_players.at(i)->isDead == false)
            {
                // Protection last only 1 tour
                if(m_players.at(i)->GetPlayerProtection() == true)
                {
                    std::cout<< "No longer protected" <<std::endl;
                    m_players.at(i)->RemovePlayerProtection();
                }

                m_players.at(i)->PrintName();
                Card inHand = m_players.at(i)->TakeCardTop();
                Card pick = deck.PickCard();
                if(Utils::CardTypeToString(pick.type) == "Countess" && (Utils::CardTypeToString(inHand.type) =="Prince" || Utils::CardTypeToString(inHand.type)=="King"))
                {
                    m_players.at(i)->AddCard(pick);
                    std::cout << "Your cards " << std::endl;
                    m_players.at(i)->PrintHand();
                    std::cout <<"You have no choice" << std::endl;
                    m_players.at(i)->PlayACard(pick);
                }
                else
                {
                    if (Utils::CardTypeToString(inHand.type) == "Countess" && (Utils::CardTypeToString(pick.type) =="Prince" || Utils::CardTypeToString(pick.type)=="King"))
                    {
                        m_players.at(i)->AddCard(pick);
                        std::cout << "Your cards " << std::endl;
                        m_players.at(i)->PrintHand();
                        std::cout <<"You have no choice" << std::endl;
                        m_players.at(i)->PlayACard(inHand);
                    }
                    else
                    {
                        m_players.at(i)->AddCard(pick);
                        std::cout << "Your cards " << std::endl;
                        m_players.at(i)->PrintHand();

                        do
                        {
                            c = m_players.at(i)->ChoisirCarte();
                            m_playedCards.at(i).cards.push_back(c);
                            playerExist = m_players.at(i)->PlayACard(c);
                        } while( playerExist == false);

                        _cardEffectCheck(c, deck, m_players.at(i) ,i);
                        std::cout << "========= Cartes deja jouees ==========" <<std::endl;
                        for (unsigned int k = 0; k< m_playedCards.at(i).cards.size(); k++)
                        {
                            std::string s = Utils::CardTypeToString(m_playedCards.at(i).cards.at(k).type);
                            std::cout << s << std::endl;
                        }
                        std::cout << "=======================================" <<std::endl;
                    }
                }

                if( _playersAlive() <= 1)//check if more than 1 player if not exit
                {
                    break;
                }
                std::cout <<"" <<std::endl;
                std::cout << "===============================" <<std::endl;
            }
            if (deck.SizeDeck() == 0)
            {
                break;
            }
        }
    }

    if (_playersAlive() <= 1)
    {
        for(auto player : m_players)
        {
            if(player->isDead == false)
            {
                player->WinAPoint();
                std::cout << "The winner of this round is : " << std::endl;
                player->PrintName();
                std::cout << player->GetNumberOfPoints() << " point(s)" << std::endl;
            }
        }
    }
    // When more than one player is alive, find the one with the highest strength
    else
    {
        int winner = 0;
        Card win;
        win.type = CardType::None;
        for(unsigned int i = 0 ; i < m_players.size() ; i++ )
        {
            if(m_players.at(i)->isDead == false )
            {
                if(m_players.at(i)->TakeCardTop().type > win.type)
                {
                    win.type = m_players.at(i)->TakeCardTop().type;
                    winner = i;
                }
            }
        }
        m_players.at(winner)->WinAPoint();
        std::cout << "The winner of this round is : " << std::endl;
        m_players.at(winner)->PrintName();
        std::cout <<m_players.at(winner)->GetNumberOfPoints() << " point(s)" << std::endl;
    }
}

bool ServerGame::_checkForWinner()
{
    auto winnerPos = _getWinnerPos();
    if(winnerPos != m_players.end())
    {
        return true;
    }
    return false;
}

ServerGame::PlayersContainer::iterator ServerGame::_getWinnerPos()
{
    int8_t maxPoints = -1;
    if(m_numberOfPlayers == 2)
    {
        maxPoints = 7;
    }
    else if(m_numberOfPlayers == 3)
    {
        maxPoints = 5;
    }
    else if(m_numberOfPlayers == 4)
    {
        maxPoints = 4;
    }

    auto it = std::find_if(std::begin(m_players), std::end(m_players), [maxPoints](const PlayerPtr player)
    {
        return player->GetNumberOfPoints() == maxPoints;
    });

    return it;
}

ServerGame::PlayerPtr ServerGame::_getWinner()
{
    auto it = _getWinnerPos();
    if(it != m_players.end())
    {
        return *it;
    }
    return nullptr;
}

void ServerGame::_prepareForNextRound()
{
    for(auto player : m_players)
    {
        player->isDead = false;
        player->RemovePlayerProtection();
        player->EmptyPlayerDeck();
    }
    //
    for(auto& playCards : m_playedCards)
    {
        playCards.cards.clear();
    }
}

void ServerGame::_addAIPlayers()
{
    int32_t numberOfAIPlayers = (m_numberOfPlayers - 1);
    if(numberOfAIPlayers < 1)
    {
        // No AI players needs to be added
        return;
    }

    std::string playerName;
    if(numberOfAIPlayers < 2)
    {
        playerName = "BotAnne";
        m_players.push_back(std::make_shared<AIPlayer>(playerName));
        m_playedCards.push_back({m_players.back(), {}});
    }
    //
    if(numberOfAIPlayers < 3)
    {
        playerName = "BotGeorges";
        m_players.push_back(std::make_shared<AIPlayer>(playerName));
        m_playedCards.push_back({m_players.back(), {}});
    }
    //
    if(numberOfAIPlayers < 4)
    {
        playerName = "BotMaria";
        m_players.push_back(std::make_shared<AIPlayer>(playerName));
        m_playedCards.push_back({m_players.back(), {}});
    }
}

int ServerGame::_playersAlive() const
{
    int alivePlayers = 0;
    for(auto player : m_players)
    {
        if(player->IsDead() == false)
        {
            alivePlayers++;
        }
    }
    return alivePlayers;
}

int ServerGame::_getPlayerPosition(PlayerPtr player)
{
    int i = 0;
    while (player->GetName() != m_players.at(i)->GetName())
    {
       i++;
    }
    return i;
}

bool ServerGame::_allProtected(PlayerPtr _player)
{
    for(auto player : m_players)
    {
        if(player->GetName() != _player->GetName())
        {
            if(player->GetPlayerProtection() == false && player->isDead == false)
            {
                return false;
            }
        }
    }
    return true;
}


void ServerGame::_cardEffectCheck(const Card& c, Deck& deck ,PlayerPtr player,int pos)
{
    bool present = false;
    std::string input;

    // When it's priest try guess on of opponents card
    if( Utils::CardTypeToString(c.type) == "Guard")
    {
        if(_allProtected(player))
        {
        }
        else
        {
            do
            {
                input = player->ChoisirJoueur(m_players, m_players.size());
                while (player->GetName() == input)
                {
                    input = player->ChoisirJoueur(m_players, m_players.size());
                }
                for (auto p : m_players)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false )
                    {
                        int i = _getPlayerPosition(p);
                        Card input = m_players.at(pos)->DevinerCarte();
                        Card c = p->TakeCardTop();
                        if( Utils::CardTypeToString(input.type) ==  Utils::CardTypeToString(c.type) )
                        {
                            std::cout << "You guessed it! : " <<std::endl;
                            m_players.at(i)->isDead = true;
                            m_playedCards.at(i).cards.push_back(c);
                        }
                        else
                        {
                            std::cout << "NOPE : \n";
                        }
                        present = true;
                    }
                }
            } while (present == false);
        }
    }

    // When princess is player, player dies automatically
    if ( Utils::CardTypeToString(c.type) == "Princess" )
    {
        std::cout << "You lose"  <<std::endl ;
        m_players.at(pos)->isDead = true;
        std::cout << _playersAlive() <<std::endl;
    }

    // When Baron is played, player chooses oponent and compares their cards
    // the one with lower strength, dies
    if( Utils::CardTypeToString(c.type) == "Baron" )
    {
        if(_allProtected(player))
        {

        }
        else
        {
            do
            {
                input = player->ChoisirJoueur(m_players, m_players.size());
                while (player->GetName() == input)
                {
                    input = player->ChoisirJoueur(m_players, m_players.size());
                }
                for (auto p : m_players)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false )
                    {
                        int index = _getPlayerPosition(p);
                        Card otherCard = m_players.at(index)->TakeCardTop();
                        std::cout << Utils::CardTypeToString(otherCard.type) << std::endl;

                        Card myCard =  m_players.at(pos)->TakeCardTop();
                        std::cout << Utils::CardTypeToString(myCard.type) << std::endl;

                        if( otherCard.type > myCard.type)//my card is lower
                        {
                            std::cout << "You lose" <<std::endl ;
                            m_players.at(pos)->isDead = true;
                            m_playedCards.at(pos).cards.push_back(myCard);
                        }
                        else if(otherCard.type < myCard.type)
                        {
                            std::cout << "You win the battle"  <<std::endl ;
                            m_players.at(index)->isDead = true;
                            m_playedCards.at(index).cards.push_back(otherCard);
                        }
                        else{/*do nothing*/}
                        present = true;
                    }
                }
            } while (present == false );
        }
    }

    if( Utils::CardTypeToString(c.type) == "Prince" )
    {
        if(_allProtected(player))
        {
            std::cout << "All other players are protected, you've no choice" << std::endl;
            Card discard = m_players.at(pos)->TakeCardTop();
            if(Utils::CardTypeToString(discard.type) == "Princess")
            {
                m_players.at(pos)->isDead = true;
                std::cout <<"You lose !" << std::endl;
            }
            else
            {
                Card newcard;
                m_players.at(pos)->PlayACard(discard);
                if (deck.SizeDeck() == 0)
                {
                    newcard = m_defausse;
                }
                else
                {
                    newcard = deck.PickCard();
                }
                m_players.at(pos)->AddCard(newcard);
            }
        }
        else
        {
            do
            {
                input = player->ChoisirJoueur(m_players, m_players.size());
                for (auto p : m_players)
                {
                    if (p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false)
                    {
                        int i= _getPlayerPosition(p);
                        Card discard = m_players.at(i)->TakeCardTop();
                        if(Utils::CardTypeToString(discard.type) == "Princess")
                        {
                            m_players.at(i)->isDead = true;
                            std::cout <<"You lose !" << std::endl;
                        }
                        else
                        {
                            m_players.at(i)->PlayACard(discard);
                            Card newcard = deck.PickCard();
                            m_players.at(i)->AddCard(newcard);
                        }
                        present = true;
                    }
                }
            } while (present == false);
        }
    }

    if( Utils::CardTypeToString(c.type) == "Handmaid" )
    {
        player->ProtectPlayer();
        std::cout<< "You are protected this tour" <<std::endl;
    }

    if( Utils::CardTypeToString(c.type) == "King" )
    {
        if(_allProtected(player))
        {}
        else
        {
            do
            {
                input = player->ChoisirJoueur(m_players, m_players.size());
                while (player->GetName() == input)
                {
                    input = player->ChoisirJoueur(m_players, m_players.size());
                }
                for (auto p : m_players)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false)
                    {
                        int i = _getPlayerPosition(p);
                        std::swap(m_players[i]->playerDeck[0],m_players[pos]->playerDeck[0]);     // /!\ playerDeck is private
                        present = true;
                    }
                }
            } while (present == false);
        }
    }

    if( Utils::CardTypeToString(c.type) == "Priest" )
    {
        if(_allProtected(player))
        {
            int a = 5;
            a++;
        }
        else
        {
            do
            {
                input = player->ChoisirJoueur(m_players, m_players.size());
                while (player->GetName() == input)
                {
                    input = player->ChoisirJoueur(m_players, m_players.size());
                }
                for (auto p : m_players)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false)
                    {
                        p->PrintHand();
                        present = true;
                    }
                }
            } while (present == false);
        }
    }
}

void ServerGame::_printDefausse()
{
    std::cout << Utils::CardTypeToString(m_defausse.type) << std::endl;
}

void ServerGame::_sendMsg(const IConnection::Msg& msg)
{
    if(m_msgSender != nullptr)
    {
        m_msgSender(msg);
    }
}
