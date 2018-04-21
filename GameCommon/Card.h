#ifndef CARD_H
#define CARD_H

#include <string>
#include <vector>
#include "../GameCommon/GameDefinitions.h"

struct Card
{
    using Strength = unsigned char;
    CardType type;
    Strength strength;
};

struct PlayerHand
{
    std::string name;
    std::vector<Card> cards;
};

#endif // CARD_H
