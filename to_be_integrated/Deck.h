#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck
{
public:
    using DeckStorage = std::vector<Card>;

    int SizeDeck() const;
    void InitDeck();
    Card PickCard();
    bool IsEmpty() const;
private:
    void ShuffleDeck();
    DeckStorage m_deck;
};

#endif // DECK_H
