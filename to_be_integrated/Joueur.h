#ifndef JOUEUR_H
#define JOUEUR_H
#include <iostream>
#include <string>
#include <vector>
#include "Deck.h"

class Joueur
{     
public: 
    Joueur(const std::string& name);  
    const std::string& GetName() const; //accesseur  (string& reference -> do not use a copy)
    void PrintName();
    int GetNbPoints() const; //accesseur
    void SetNbPoints(int); //modificateur
    bool IsDead() const;  // teste if you lose
    void PrintHand();
    std::string PrintNbPoints(); // nbr de points
    void AddCard(const Card& toAdd);//addd card in your deck
    Card TakeCard(size_t n); //take a card from your deck
    Card TakeCardByName(const std::string& name); //take a card from your deck
    bool PlayACard(Card& c); //retire la carte c de la main du joueur et affiche le pouvoir
    void ProtecdPlayer();
    bool GetPlayerProtection();
    void EmptyPlayerDeck();
    void RemovePlayerProtection();
    Card TakeCardTop();
    void WinAPoint();
    virtual Card ChoisirCarte();
    virtual Card DevinerCarte();
    virtual std::string ChoisirJoueur(std::vector<Joueur*> vectorPlayer, int nbPlayers);
    bool isDead = false;
    std::vector<Card> playerDeck;
public:    
    bool protect = false;//The default numeric value of true is 1 and false is 0.
   //la main du joueur = ses cartes
    int nbPoints = 0;  //nombre de points du joueur
    std::string name; //nom du joueur
};


#endif //JOUEUR_H
