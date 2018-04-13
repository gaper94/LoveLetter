#ifndef BOT_H
#define BOT_H
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>
#include <map>
#include "Joueur.h"
#include "Game.h"

class Bot_Random: public Joueur
{
 public:
	Bot_Random(const std::string& name); //constructeur
	Card ChoisirCarte(); //methode pour choisir la carte à jouer
	Card RandomCarte(); // choisir une carte aléatoirement
	Card DevinerCarte(); // deviner une carte aléatoirement
	void DevinerRandom(Card c); // afficher la carte devinée
	std::string ChoisirJoueur(std::vector<Joueur*> vectorPlayer , int nbPlayers);

};



#endif



