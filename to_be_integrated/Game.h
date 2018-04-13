#ifndef GAME_H
#define GAME_H

#include "Joueur.h"
#include <vector>

struct PlayedCards
{
    Joueur* j;
    std::vector<Card> cards;
};

class Game
{
public:
    void InitPlayers(int nbPlayers);
    int  PlayersAlive() const;
    void PlayRound(Deck deck);
    int Winner(int nbJoueur);
    void PlayGame();
    int GetPlayerPosition(Joueur* j);
    bool AllProtected(Joueur * moi);
    void CardEffectCheck(const Card& c, Deck * deck ,Joueur * j,int pos);
    void Between2Rounds();    
    void PrintDefausse();
    int numbreOfPlayers = 0;
private:
    std::vector <Joueur*> vectorPlayers;
    Card defausse;
    std::vector<PlayedCards> playedCard;
};

#endif // GAME_H
