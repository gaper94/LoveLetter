#include "Bot_Random.h"
#include <random>
#include <algorithm>
#include <iostream>
#include "../GameCommon/GameUtils.h"

BotRandom::BotRandom(const std::string& name)
    : Joueur(name)
{
}

void BotRandom::DevinerRandom(Card c)
{
    std::cout << "Vous avez la carte:" << Utils::CardTypeToString(c.type) << "?" << std::endl;
}

Card BotRandom::RandomCarte()
{
	Card c1 = playerDeck[0];
	Card c2 = playerDeck[1];
    int nombre;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,1);
    nombre = dis(gen);
    if (nombre == 0)
        return c1;
    else return c2;
}

Card BotRandom::ChoisirCarte()
{
	Card carte1 = playerDeck[0];
	Card carte2 = playerDeck[1];

    if ((Utils::CardTypeToString(carte1.type) != "") && (Utils::CardTypeToString(carte2.type) != ""))
    {
        if (carte1.type==CardType::Princess)
            return carte2;
        if (carte2.type==CardType::Princess)
            return carte1;
	}

	return RandomCarte();
}

Card BotRandom::DevinerCarte()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(2,8);
    int i = dis(gen);
    std::string s = std::to_string(i);
    Card c;
    c.type = Utils::CardTypeFromString(s);
    return c;
}

std::string BotRandom::ChoisirJoueur(PlayersContainer& vectorPlayers , int nbPlayers)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,nbPlayers-1);
    int  i = dis(gen);
    while(vectorPlayers[i]->GetPlayerProtection() == true || vectorPlayers[i]->isDead == true)
    {
         i = dis(gen);
    }
    std::cout << vectorPlayers[i]->GetName() << std::endl;
	return vectorPlayers[i]->GetName();
}
