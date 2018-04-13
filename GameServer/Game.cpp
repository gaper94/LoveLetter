#include "Game.h"
#include "../to_be_integrated/Bot_Random.h"
#include <iostream>
#include "../GameCommon/GameUtils.h"
#include "ServerDebug.h"
#include <memory>
#include <algorithm>

bool ServerGame::AllProtected(Joueur * moi)
{
	for(auto j : vectorPlayers)
    {
        if(j->GetName() == moi->GetName())
        {
            
        }
        else
        {
            if(j->GetPlayerProtection() == false && j->isDead== false)
            {
               return false;
            }
        }   
    }
    return true;  
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

int ServerGame::PlayersAlive() const
{
    int nbAlive=0;
    for(Joueur* j : vectorPlayers)
    {
      if(j->isDead == false)
      {
        nbAlive ++ ;  
      }
    }
    return nbAlive;
}

int ServerGame::GetPlayerPosition(Joueur* j)//return position inside the array
{
	int i = 0;
   	while (j->GetName() != vectorPlayers.at(i)->GetName())
	   i++;
	return i;

}   

void ServerGame::PrintDefausse()
{
    std::string card = Utils::CardTypeToString(defausse.type);
    std::cout << card << std::endl;
}

void ServerGame::CardEffectCheck(const Card& c, Deck * deck ,Joueur * j,int pos)// int pos current player position
{
    bool present = false;
	std::string input;
    if( Utils::CardTypeToString(c.type) == "Guard")
    {
        if(AllProtected(j))
        {}
        else
        { 
            do
            {
                input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                while (j->GetName() == input) 
                {
                    input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                }
                for (auto p : vectorPlayers)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false )
                    {
                        int i = GetPlayerPosition(p);
                        Card input = vectorPlayers.at(pos)->DevinerCarte();
                        Card c = p->TakeCardTop(); 
                        if( Utils::CardTypeToString(input.type) ==  Utils::CardTypeToString(c.type) )
                        {
                            std::cout << "You guessed it! : " <<std::endl;
                            vectorPlayers.at(i)->isDead = true;
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

    if ( Utils::CardTypeToString(c.type) == "Princess" )
    {
        std::cout << "You lose"  <<std::endl ;
        vectorPlayers.at(pos)->isDead = true;
        std::cout << PlayersAlive() <<std::endl;
    }


    if( Utils::CardTypeToString(c.type) == "Baron" )
    {
        if(AllProtected(j))
        {}
        else
        {
            do
            {
                input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                while (j->GetName() == input) 
                {
                    input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                }
                for (auto p : vectorPlayers)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false )
                    {
                        int index = GetPlayerPosition(p);
                        Card otherCard = vectorPlayers.at(index)->TakeCardTop();
                        std::cout << Utils::CardTypeToString(otherCard.type) << std::endl;

                        Card myCard =  vectorPlayers.at(pos)->TakeCardTop();
                        std::cout << Utils::CardTypeToString(myCard.type) << std::endl;

                        if( otherCard.type > myCard.type)//my caard is lower
                        {    
                            std::cout << "You lose" <<std::endl ;
                            vectorPlayers.at(pos)->isDead = true;
                            m_playedCards.at(pos).cards.push_back(myCard);
                        }
                        else if(otherCard.type < myCard.type)
                        {
                            std::cout << "You win the battle"  <<std::endl ;
                            vectorPlayers.at(index)->isDead = true;
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
        if(AllProtected(j))
        {
            std::cout << "All other players are protected, you've no choice" << std::endl;
            Card discard = vectorPlayers.at(pos)->TakeCardTop();
            if(Utils::CardTypeToString(discard.type) == "Princess")
            {
                vectorPlayers.at(pos)->isDead = true;
                std::cout <<"You lose !" << std::endl;
            }
            else
            {
                Card newcard;
                vectorPlayers.at(pos)->PlayACard(discard);
                if (deck->SizeDeck() == 0)
                    newcard = defausse;
                else
                    newcard = deck->PickCard();
                vectorPlayers.at(pos)->AddCard(newcard);
            }
        }
        else
        {
            do
            {
                input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                for (Joueur* p : vectorPlayers)
                {
                    if (p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false)
                    {
                        int i= GetPlayerPosition(p);
                        Card discard = vectorPlayers.at(i)->TakeCardTop();
                        if(Utils::CardTypeToString(discard.type) == "Princess")
                        {
                            vectorPlayers.at(i)->isDead = true;
                            std::cout <<"You lose !" << std::endl;
                        }
                        else
                        {
                            vectorPlayers.at(i)->PlayACard(discard);
                            Card newcard = deck->PickCard();
                            vectorPlayers.at(i)->AddCard(newcard);
                        }
                        present = true;
                    }
                }
            } while (present == false);	
        }	
    }

    if( Utils::CardTypeToString(c.type) == "Handmaid" )
    {
        j->ProtectPlayer();
        std::cout<< "You are protected this tour" <<std::endl;
    }

    if( Utils::CardTypeToString(c.type) == "King" )
    {
        if(AllProtected(j))
        {}
        else
        {
            do
            {
                input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                while (j->GetName() == input) 
                {
                    input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                }
                for (auto p : vectorPlayers)
                {
                    if(p->GetName() == input && p->GetPlayerProtection() == false && p->isDead == false)
                    {
                        int i = GetPlayerPosition(p);
                        std::swap(vectorPlayers[i]->playerDeck[0],vectorPlayers[pos]->playerDeck[0]);     // /!\ playerDeck is private
                        present = true;
                    }
                }
            } while (present == false);
        }
    }

    if( Utils::CardTypeToString(c.type) == "Priest" )
    {
         if(AllProtected(j))
        {}
        else
        {
            do
            {
                input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                while (j->GetName() == input) 
                {
                    input = j->ChoisirJoueur(vectorPlayers, vectorPlayers.size());
                }
                for (auto p : vectorPlayers)
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

void ServerGame::StartGame()
{
    m_gameState = GameState::InProcess;
    _startGame();
}

void ServerGame::ForceStopGame()
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
        gameIsRunning = _checkForWinner();
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
    Card discard;
    Card c;
    bool playerExist;
    defausse = deck.PickCard();
    PrintDefausse();

    //si 2 joueurs => pioche trois cartes et les montre a tous le monde //GAME RULE2
    if(PlayersAlive() == 2)
    {
        std::cout << "DISCARTED CARDS"<< std::endl;
        discard = deck.PickCard();
        std::cout << Utils::CardTypeToString(discard.type) << std::endl;
        discard = deck.PickCard();
        std::cout << Utils::CardTypeToString(discard.type) << std::endl;
        discard = deck.PickCard();
        std::cout << Utils::CardTypeToString(discard.type) << std::endl;
        std::cout << "================" << std::endl;
    }

    //EVERYONE RECIEVE ONE CARD //GAME RULE3
    for(int i = 0; i <m_numberOfPlayers; i++)
    {
        auto pickedCard1 = deck.PickCard();
        vectorPlayers.at(i)->AddCard(pickedCard1);
        vectorPlayers.at(i)->PrintName();
        vectorPlayers.at(i)->PrintHand();
    }



    while(deck.SizeDeck() > 0)
    {
        //CHECK MORE THAN  PLAYER AVAILABLE
       if( PlayersAlive() <= 1)
       {
           break;
       }

        for(int i =0  ; i <m_numberOfPlayers; i++)
        {
            if(vectorPlayers.at(i)->isDead == false)
            {
            //GameRULE protection last only 1 tour
            if(vectorPlayers.at(i)->GetPlayerProtection() == true)
            {
                std::cout<< "No longer protected" <<std::endl;
                vectorPlayers.at(i)->RemovePlayerProtection();
            }

            vectorPlayers.at(i)->PrintName();
            Card inHand = vectorPlayers.at(i)->TakeCardTop();
            Card pick = deck.PickCard();
            if(Utils::CardTypeToString(pick.type) == "Countess" && (Utils::CardTypeToString(inHand.type) =="Prince" || Utils::CardTypeToString(inHand.type)=="King"))
            {
                vectorPlayers.at(i)->AddCard(pick);
                std::cout << "Your cards " << std::endl;
                vectorPlayers.at(i)->PrintHand();
                std::cout <<"You have no choice" << std::endl;
                vectorPlayers.at(i)->PlayACard(pick);
            }
            else
            {
                if (Utils::CardTypeToString(inHand.type) == "Countess" && (Utils::CardTypeToString(pick.type) =="Prince" || Utils::CardTypeToString(pick.type)=="King"))
                {
                    vectorPlayers.at(i)->AddCard(pick);
                    std::cout << "Your cards " << std::endl;
                    vectorPlayers.at(i)->PrintHand();
                    std::cout <<"You have no choice" << std::endl;
                    vectorPlayers.at(i)->PlayACard(inHand);
                }
                else
                {
                    vectorPlayers.at(i)->AddCard(pick);
                    std::cout << "Your cards " << std::endl;
                    vectorPlayers.at(i)->PrintHand();

                    do
                    {
                        c = vectorPlayers.at(i)->ChoisirCarte();
                        m_playedCards.at(i).cards.push_back(c);
                        /*std::cout << "which one do u want to play:  ";
                        std::string userChoice;
                        getline(std::cin, userChoice); //respect Case letters
                        c = vectorPlayers.at(i)->TakeCardByName(userChoice);*/
                        playerExist = vectorPlayers.at(i)->PlayACard(c);
                    } while( playerExist == false);
                    CardEffectCheck(c, &deck , vectorPlayers.at(i) ,i);
                    std::cout << "========= Cartes deja jouees ==========" <<std::endl;
                    for (unsigned int k = 0; k< m_playedCards.at(i).cards.size(); k++)
                    {
                        std::string s = Utils::CardTypeToString(m_playedCards.at(i).cards.at(k).type);
                        std::cout << s << std::endl;
                    }
                    std::cout << "=======================================" <<std::endl;
                }
            }

            if( PlayersAlive() <= 1)//check if more than 1 player if not exit
            {
                break;
            }
            std::cout <<"" <<std::endl;
            std::cout << "===============================" <<std::endl;
            }
            if (deck.SizeDeck() == 0)
            {break;}
        }
    }

    if (PlayersAlive() <= 1)
    {
        for(unsigned int i = 0 ; i < vectorPlayers.size() ; i++ )
        {

            if(vectorPlayers.at(i)->isDead == false)
            {
                vectorPlayers.at(i)->WinAPoint();
                std::cout << "The winner of this round is : " << std::endl;
                vectorPlayers.at(i)->PrintName();
                std::cout <<vectorPlayers.at(i)->GetNumberOfPoints() << " point(s)" << std::endl;
            }
        }
    }
    else//PlayerAlive > 1
    {
        int winner=0;
        Card win;
        win.type = CardType::None;
        for(unsigned int i = 0 ; i < vectorPlayers.size() ; i++ )
        {
            if(vectorPlayers.at(i)->isDead == false )
            {
                if(vectorPlayers.at(i)->TakeCardTop().type > win.type)
                {
                    win.type = vectorPlayers.at(i)->TakeCardTop().type;
                    winner = i;
                }
            }
        }
        vectorPlayers.at(winner)->WinAPoint();
        std::cout << "The winner of this round is : " << std::endl;
        vectorPlayers.at(winner)->PrintName();
        std::cout <<vectorPlayers.at(winner)->GetNumberOfPoints() << " point(s)" << std::endl;
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
    return m_players.end();
}

ServerGame::PlayerPtr ServerGame::_getWinner()
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
    std::string playerName;
    if(numberOfAIPlayers < 2)
    {
        playerName = "BotAnne";
        m_players.push_back(std::make_shared<AIPlayer>(playerName));
    }
    //
    if(numberOfAIPlayers < 3)
    {
        playerName = "BotGeorges";
        m_players.push_back(std::make_shared<AIPlayer>(playerName));
    }
    //
    if(numberOfAIPlayers < 4)
    {
        playerName = "BotMaria";
        m_players.push_back(std::make_shared<AIPlayer>(playerName));
    }
}
