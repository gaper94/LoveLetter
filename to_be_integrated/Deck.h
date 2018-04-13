#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck
{
public:

    int SizeDeck() const;
    /**
        Print tous les cartes de deck

        @param none
        @return void
    */
    void PrintDeck();

    /**
        Initialise le tas avec 16 cartes et le melange a la fin

        @param non 
        @return void
    */
    void InitDeck();

    /**
        Prend un carte de tas

        @param none
        @return Card
    */
    Card PickCard();

    /**
        Teste si le tas est vide

        @param none
        @return Bool
    */
    bool IsEmpty() const;  // teste si vide
private:
    void ShuffleDeck();   // shuffleDeck fonction privée, utilisée par la fonctionne  initDeck
    std::vector<Card> m_deck;  // vector Card represente le tas
};

#endif // DECK_H
