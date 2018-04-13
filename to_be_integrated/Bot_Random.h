#ifndef BOT_H
#define BOT_H

#include <string>
#include <vector>
#include "Joueur.h"

class BotRandom: public Joueur
{
 public:
    BotRandom(const std::string& name);
    Card ChoisirCarte();
    Card RandomCarte();
    Card DevinerCarte();
    void DevinerRandom(Card c);
	std::string ChoisirJoueur(std::vector<Joueur*> vectorPlayer , int nbPlayers);
};

#endif



