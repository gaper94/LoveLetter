#include "InfSup_Bot.h"
#include <random>
#include <algorithm>
#include <iostream>
#include "../GameCommon/GameUtils.h"


/*bot inf_sup: bot qui joue toujours la carte la plus petite et il peut deviner la carte d'un autre joueur */


InfSup_Bot::InfSup_Bot(const std::string& name)
	: Joueur(name) 
{
}



std::string InfSup_Bot::ChoisirJoueur(PlayersContainer& vectorPlayers , int nbPlayers)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,nbPlayers-1);
    int  i = dis(gen);
    while(vectorPlayers[i]->GetPlayerProtection() == true || vectorPlayers[i]->isDead == true)
    {
         i = dis(gen);
    }
	return vectorPlayers[i]->GetName();
}

Card InfSup_Bot::ChoisirCarte()
{
	Card carte1 = playerDeck[0];
	Card carte2 = playerDeck[1];
	int c1value, c2value;
    c1value = Utils::GetCardValue(carte1.type);
    c2value = Utils::GetCardValue(carte2.type);
	
	if (c2value < c1value)
		return carte2;
	else //s'il sont egales ou c1 < c2
		return carte1;
}

int InfSup_Bot::CartesRestantes(Card c)
{
	unsigned int i,j;

	Card c1 = playerDeck[0];
	Card c2 = playerDeck[1];
	int CartesRestantes = Utils::GetNumbCard(c.type);
	if (c.type == c1.type) //si on a la meme carte que la carte q'on teste alors on decremente le nombre restants
		CartesRestantes --;
	if (c.type == c2.type)
		CartesRestantes --;
	
	//si la carte est deja jouée on decremente les cartes restantes 
	for (i=0; i<playedCard.size();i++)
		for (j=0; j< playedCard.at(i).cards.size(); j++)
		{
			if (playedCard.at(i).cards.at(j).type==c.type)
			CartesRestantes --;
		}
	return CartesRestantes;
}

Card InfSup_Bot::DevinerCarte()
{
	int i;
	Card c;

	//on parcours toutes les cartes avec 2 iterations sauf le guard 
	for (i=4; i>1;i--)
	{
		std::string s = std::to_string(i);
    	c.type = Utils::CardTypeFromString(s);
		if (CartesRestantes(c) == 2)
			return c;
	}

//si on trouve pas une carte avec deux iterations on parcourt toutes les cartes sauf le guard
	for (i=7; i>1;i--)
	{
		std::string s = std::to_string(i);
    	c.type = Utils::CardTypeFromString(s);
		if (CartesRestantes(c) == 1)
			return c;
	}
	return c;		
}

