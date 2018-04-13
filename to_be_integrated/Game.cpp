#include "Game.h"
#include <algorithm>


int Game::NbPlayerProtected()
{
    int i;
	for(auto j : vectorPlayers)
    {
        if(j->GetPlayerProtection() == true)
        {
            i++;
        }
    }
    return i;
}


bool Game::AllProtected(Joueur * moi)
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

void Game::PrintPlayers()
{
    for (auto j : vectorPlayers)
    j->PrintName();
}


void Game::PlayersShowHands()
{
    for (auto j : vectorPlayers)
    {
        if(j->isDead == false)
        {
            j->PrintName();
            j->PrintHand(); 
        }
    }
}

//nPlayer vector array of all the Players(Joueur.cpp)
void Game::InitPlayers(int nbPlayers)
{
    std::string in;
    std::string player;
    while(nbPlayers < 2 || nbPlayers > 4)
    {
        std::cout << "Choose un number between 2 and 4 : " << std::endl;
        getline(std::cin, in); 
        nbPlayers = std::stoi(in);
    }
    std::string input = "";
    vectorPlayers.clear();
    int num = 1;
    for(int i = 0 ; i < nbPlayers; i++)
    {
        std::cout <<"What kind of player ? h for Human, t for terminator, r for random bot or i for inf_sup bot " << std::endl;
        getline(std::cin, player);
        if (player == "h")
        {
            printf("Enter your name: "); //change here according to different input modes
            getline(std::cin, input);    //====
            Joueur* joueur = new Joueur(input);
            vectorPlayers.insert(vectorPlayers.begin(), 1, joueur); //array players with names from ->//input method
            std::vector<Card> c;
            PlayedCards p = {joueur, c};
            playedCard.insert(playedCard.begin(),1,p);
        }
        if (player == "t")
        {
            //vectorPlayers.insert(vectorPlayers.begin(), 1, Terminator("Anne")); NOT IMPLEMENTED YET
        }
        if (player == "r")
        {
            std::string n;
            if(num == 1)
                n = "BotAnne";
            if(num == 2)
                n = "BotGeorges";
            if(num == 3)
                n = "BotMaria";
            if(num == 4)
                n = "BotAmadou";
            Bot_Random* Bot = new Bot_Random(n);
            vectorPlayers.insert(vectorPlayers.begin(), 1,Bot);
            std::vector<Card> c;
            PlayedCards p = {Bot, c};
            playedCard.insert(playedCard.begin(),1,p);
            num++;
        }
        if (player == "i")
        {
           // vectorPlayers.insert(vectorPlayers.begin(), 1, InfSup_Bot("Georges")); NOT IMPLEMENTED YET
        }
    }
    numbreOfPlayers = nbPlayers;
}

int Game::PlayersAlive() const
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


int Game::GetPlayerPosition(Joueur* j)//return position inside the array
{
	int i = 0;
   	while (j->GetName() != vectorPlayers.at(i)->GetName())
	   i++;
	return i;

}   

Joueur* Game::TakePlayer(int n)
{
    if(n > PlayersAlive()) //if n bigger than players available in the vector
    {
        exit (EXIT_FAILURE);
    }
    Joueur* j= vectorPlayers.at(n-1);
    return j;
}


void Game::ErasePlayer(int n)
{
    vectorPlayers.erase(vectorPlayers.begin() + n);
}


Card Game::CardComppare(const Card& a,const Card& b)
{
    if(a.type > b.type)
    {
        return b;
    }
  return a;
}

Card Game::GetDefausse()
{
    return defausse;
}

void Game::PrintDefausse()
{
    std::string card = CardTypeToString(defausse.type);
    std::cout << card << std::endl;
}

void Game::CardEffectCheck(const Card& c, Deck * deck ,Joueur * j,int pos)// int pos current player position
{
    bool present = false;
	std::string input;
    if( CardTypeToString(c.type) == "Guard")
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
                        if( CardTypeToString(input.type) ==  CardTypeToString(c.type) )
                        {
                            std::cout << "You guessed it! : " <<std::endl;
                            vectorPlayers.at(i)->isDead = true;
                            playedCard.at(i).cards.push_back(c);
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

    if ( CardTypeToString(c.type) == "Princess" )
    {
        std::cout << "You lose"  <<std::endl ;
        vectorPlayers.at(pos)->isDead = true;
        std::cout << PlayersAlive() <<std::endl;
    }


    if( CardTypeToString(c.type) == "Baron" )
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
                        std::cout << CardTypeToString(otherCard.type) << std::endl;

                        Card myCard =  vectorPlayers.at(pos)->TakeCardTop();
                        std::cout << CardTypeToString(myCard.type) << std::endl;

                        if( otherCard.type > myCard.type)//my caard is lower
                        {    
                            std::cout << "You lose" <<std::endl ;
                            vectorPlayers.at(pos)->isDead = true;
                            playedCard.at(pos).cards.push_back(myCard);
                        }
                        else if(otherCard.type < myCard.type)
                        {
                            std::cout << "You win the battle"  <<std::endl ;
                            vectorPlayers.at(index)->isDead = true;
                            playedCard.at(index).cards.push_back(otherCard);
                        }
                        else{/*do nothing*/}
                        present = true;
                    }
                }
            } while (present == false );
        }		
    }

    if( CardTypeToString(c.type) == "Prince" )
    {
        if(AllProtected(j))
        {
            std::cout << "All other players are protected, you've no choice" << std::endl;
            Card discard = vectorPlayers.at(pos)->TakeCardTop();
            if(CardTypeToString(discard.type) == "Princess")
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
                        if(CardTypeToString(discard.type) == "Princess")
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

    if( CardTypeToString(c.type) == "Handmaid" )
    {
        j->ProtecdPlayer();
        std::cout<< "You are protected this tour" <<std::endl;
    }

    if( CardTypeToString(c.type) == "King" )
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

    if( CardTypeToString(c.type) == "Priest" )
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


void Game::PlayRound(Deck deck)
{
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
        std::cout << CardTypeToString(discard.type) << std::endl;
        discard = deck.PickCard();
        std::cout << CardTypeToString(discard.type) << std::endl;
        discard = deck.PickCard();
        std::cout << CardTypeToString(discard.type) << std::endl;
        std::cout << "================" << std::endl;
    }

    //EVERYONE RECIEVE ONE CARD //GAME RULE3
    for(int i = 0; i <numbreOfPlayers; i++)
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

        for(int i =0  ; i <numbreOfPlayers; i++)
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
            if(CardTypeToString(pick.type) == "Countess" && (CardTypeToString(inHand.type) =="Prince" || CardTypeToString(inHand.type)=="King"))
            {
                vectorPlayers.at(i)->AddCard(pick);
                std::cout << "Your cards " << std::endl;
                vectorPlayers.at(i)->PrintHand();
                std::cout <<"You have no choice" << std::endl;
                vectorPlayers.at(i)->PlayACard(pick);
            }
            else
            {
                if (CardTypeToString(inHand.type) == "Countess" && (CardTypeToString(pick.type) =="Prince" || CardTypeToString(pick.type)=="King"))
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
                        playedCard.at(i).cards.push_back(c);
                        /*std::cout << "which one do u want to play:  ";
                        std::string userChoice;
                        getline(std::cin, userChoice); //respect Case letters
                        c = vectorPlayers.at(i)->TakeCardByName(userChoice);*/
                        playerExist = vectorPlayers.at(i)->PlayACard(c);
                    } while( playerExist == false);
                    CardEffectCheck(c, &deck , vectorPlayers.at(i) ,i);
                    std::cout << "========= Cartes deja jouees ==========" <<std::endl;
                    for (unsigned int k = 0; k< playedCard.at(i).cards.size(); k++)
                    {
                        std::string s = CardTypeToString(playedCard.at(i).cards.at(k).type);
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
    //ALL PLAYERS SHOW HANDS
    PlayersShowHands();//testonly
    if (PlayersAlive() <= 1)
    {
        for(unsigned int i = 0 ; i < vectorPlayers.size() ; i++ )
        {
            
            if(vectorPlayers.at(i)->isDead == false)
            {
                vectorPlayers.at(i)->WinAPoint();
                std::cout << "The winner of this round is : " << std::endl;
                vectorPlayers.at(i)->PrintName();
                std::cout <<vectorPlayers.at(i)->GetNbPoints() << " point(s)" << std::endl;
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
        std::cout <<vectorPlayers.at(winner)->GetNbPoints() << " point(s)" << std::endl;
    }
}


void Game::PlayGame()
{
    std::string nombreJ;
    std::cout << "A combien de joueurs voulez-vous jouer ?" << std::endl;
    getline(std::cin, nombreJ);
    int nb = std::stoi(nombreJ);
    InitPlayers(nb);
    int i = -1;
    while (i== -1)
    {
        Deck deck;
        deck.InitDeck();
        PlayRound(deck);
        Between2Rounds();
        i = Winner(nb);
    }
    std::cout << "Le gagnant est ";
    vectorPlayers.at(i)->PrintName();
    std::cout << "Le resultat final est : " << std::endl;
    for(auto j : vectorPlayers)
    {
        j->PrintName();
        std::cout <<vectorPlayers.at(GetPlayerPosition(j))->GetNbPoints() << " point(s)" << std::endl;
    }

}

void Game::Between2Rounds()
{
    for(auto j : vectorPlayers)
    {
        int pos = GetPlayerPosition(j);
        vectorPlayers.at(pos)->isDead = false;
        vectorPlayers.at(pos)->RemovePlayerProtection();
        vectorPlayers.at(pos)->EmptyPlayerDeck();
        playedCard.at(pos).cards.clear();
    }
}

int Game::Winner(int nbJoueur)
{
    int maxPoints;
    if (nbJoueur == 2)
        maxPoints = 7;
    if (nbJoueur == 3)
        maxPoints = 5;
    if (nbJoueur == 4)
        maxPoints = 4;
    for (int i=0; i<nbJoueur; i++)
    {
        if (vectorPlayers.at(i)->GetNbPoints() == maxPoints)
            return i;
    }
    return -1;
}


int main()
{
    Game game;
    game.PlayGame();
    return 0;
}

