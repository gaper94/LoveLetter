#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck
{
public:
    int SizeDeck() const;
    void InitDeck();
    Card PickCard();
    bool IsEmpty() const;
private:
    void ShuffleDeck();
    std::vector<Card> m_deck;
};

#endif // DECK_H
