#ifndef GAME_H
#define GAME_H

#include "Joueur.h"
#include "Bot_Random.h"
#include <vector>
#include <iterator>
#define WIN 7  //Number of win needed in order to win the game

struct PlayedCards
{
    Joueur* j;
    std::vector<Card> cards;
};

class Game
{
public:

    void PlayersShowHands();

    void PrintPlayers();

    /**
       Initialise les joueurs et les garde dans un vecteur (nPlayers)

        @param nbPlayers nombre de joueurs participant
        @return void
    */
    void InitPlayers(int nbPlayers);
    /**
       Retourne le nombre de joueurs restant dans la jeu

        @param
        @return int : nb de joueurs
    */
    int  PlayersAlive() const;

    /**
       Simulation dun round
       NOT IMPLEMENTED YET!!!
    */
    void PlayRound(Deck deck);

    /**
       Prend le joueur a la position N

        @param int n : La position
        @return Joueur 
    */
    Joueur* TakePlayer(int n);


    int Winner(int nbJoueur);
    void PlayGame();

    /**
        Supprime un joueur perdu NOT YETIMPLEMENTED

        @param int n : La position
        @return Joueur 
    */
    void ErasePlayer(int n);

    /**
       Compare 2 cartes return winning card

        @param Card a
        @param Card b
        @return Card : the winning card
    */
    Card CardComppare(const Card& a, const Card& b); 
    //toadd

    int GetPlayerPosition(Joueur* j);
    int NbPlayerProtected();
    bool AllProtected(Joueur * moi);

    void CardEffectCheck(const Card& c, Deck * deck ,Joueur * j,int pos);
    void Between2Rounds();
    Card GetDefausse();
    void PrintDefausse();
    int numbreOfPlayers=0;

private:
    std::vector <Joueur*> vectorPlayers;
    Card defausse;
    std::vector<PlayedCards> playedCard;
    //std::vector<Joueur> vectorBot;

};

#endif // GAME_H
