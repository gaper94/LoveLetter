#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include <vector>
#include <memory>
#include "Deck.h"

class Joueur
{     
public:
    using Player = Joueur;
    using PlayerPtr = std::shared_ptr<Joueur>;
    using PlayersContainer = std::vector<PlayerPtr>;

    Joueur(const std::string& name);  
    ~Joueur();
    const std::string& GetName() const;
    void PrintName();
    int GetNumberOfPoints() const;
    bool IsDead() const;
    void PrintHand();
    void AddCard(const Card& toAdd);
    Card TakeCardByName(const std::string& name);
    bool PlayACard(Card& c);
    void ProtectPlayer();
    bool GetPlayerProtection();
    void EmptyPlayerDeck();
    void RemovePlayerProtection();
    Card TakeCardTop();
    void WinAPoint();
    virtual Card ChoisirCarte();
    virtual Card DevinerCarte();
    virtual std::string ChoisirJoueur(PlayersContainer& vectorPlayer, int nbPlayers);
    virtual bool IsAIPlayer() { return false; }
    bool isDead = false;
    std::vector<Card> playerDeck;
public:    
    bool protect = false;
    int nbPoints = 0;
    std::string name;
};


#endif //JOUEUR_H
