#include "Joueur.h"
#include <iostream>

Joueur::Joueur(const std::string& _name)
    : name(_name)
{
}

const std::string& Joueur::GetName() const
{
	return name;
}

void Joueur::PrintHand()
{
    for(const auto& current : playerDeck)
    {
        std::cout<<"   " << CardTypeToString(current.type) << std::endl;
    }
}

int Joueur::GetNbPoints() const
{
    return nbPoints;
}
	
void Joueur::PrintName()
{
	std::cout<<">>>" << name << std::endl;
}

void Joueur::AddCard(const Card& toAdd)
{
	playerDeck.push_back(toAdd);
}

void Joueur::EmptyPlayerDeck()
{
	playerDeck.clear();
}

void Joueur::WinAPoint()
{
	nbPoints++;
}

Card Joueur::TakeCardByName(const std::string& name)
{
	for(const auto & card : playerDeck)
	{
		if(CardTypeToString(card.type) == name)
		{
			return card;
		}
	}
	return {CardType::None, 0};
}

Card Joueur::TakeCardTop()
{
	return playerDeck.back();
}

bool Joueur::IsDead() const
{
    if (playerDeck.empty())
	{
	   return true;
	}
  return false;
}

void Joueur::ProtectPlayer()
{
    protect = true;
}

void Joueur::RemovePlayerProtection()
{
	protect = false;
}

bool Joueur::GetPlayerProtection()
{
	return protect;
}

bool Joueur::PlayACard(Card& c)
{
    Card toPlay = playerDeck.back();
    Card first = playerDeck.front();
	if (c.type == toPlay.type)
	{
		std::cout << CardTypeToString(toPlay.type) << std::endl; //print  it 
		playerDeck.pop_back();	
		return true;			   					 // remove it from the deck
	}
	else // inverse cards then pop back
	{
		if (c.type == first.type)
		{
	    	Card buf;
			buf = playerDeck[1];
			playerDeck[0] = buf;
			playerDeck.pop_back();
			std::cout << CardTypeToString(c.type) << std::endl;
			return true;
		}
		else
		{
			std::cout << "Vous n'avez pas cette carte dans votre main" << std::endl;
			return false;
		}
		if(IsDead())
		{
			std::cout << "You lost this round" << std::endl;
			return true;
		}
	}
}

Card Joueur::ChoisirCarte()
{
    std::cout << "which one do u want to play:  ";
    std::string userChoice;
    getline(std::cin, userChoice);
    Card c = TakeCardByName(userChoice);
    return c;
}

Card Joueur::DevinerCarte()
{
	std::string input;
    std::cout << "Guess his card : ";
    getline(std::cin, input);
    while (input == "Guard") 
    {
        std::cout << "You can't choose the Guard ! Choose another card : ";//==
        getline(std::cin, input); 
    }
    Card c;
    c.type = CardTypeFromString(input);
    return c;
}

std::string Joueur::ChoisirJoueur(std::vector<Joueur*> vectorPlayer, int nbPlayers)
{
	std::string input;
    std::cout << "Choose a player : ";
    getline(std::cin, input); 
    return input;
}
