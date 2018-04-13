#ifndef BOT_H
#define BOT_H

#include <string>
#include <vector>
#include "Joueur.h"

class Bot_Random: public Joueur
{
 public:
    Bot_Random(const std::string& name);
    Card ChoisirCarte();
    Card RandomCarte();
    Card DevinerCarte();
    void DevinerRandom(Card c);
	std::string ChoisirJoueur(std::vector<Joueur*> vectorPlayer , int nbPlayers);
};

#endif



