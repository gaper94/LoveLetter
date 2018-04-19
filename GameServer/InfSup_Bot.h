#ifndef INFSUP_BOT_H
#define INFSUP_BOT_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include "Joueur.h"

struct PlayedCards
{
    Joueur* j;
    std::vector<Card> cards;
};

class InfSup_Bot: public Joueur
{
public:
	InfSup_Bot(const std::string& name); //constructeur
	Card ChoisirCarte(); //methode pour choisir la carte à jouer
	std::string ChoisirJoueur(PlayersContainer& vectorPlayer , int nbPlayers);
	Card DevinerCarte(); //methode pour deviner une carte
	int CartesRestantes(Card c);//methode pour compter les cartes et retourner le nombre des cartes c restantes
	void DevinerInfSup(Card c);// afficher la carte devinée
	std::vector<PlayedCards> playedCard;
	bool firstRound = true;
};

#endif //INFSUP_BOT_H
