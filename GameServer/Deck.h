#ifndef DECK_H
#define DECK_H

#include "../GameCommon/Card.h"
#include <vector>

class Deck
{
public:
    using DeckStorage = std::vector<Card>;

    Deck();
    int SizeDeck() const;
    Card PickCard();
    bool IsEmpty() const;
private:
    void _initDeck();
    void ShuffleDeck();
    DeckStorage m_deck;
};

#endif // DECK_H
