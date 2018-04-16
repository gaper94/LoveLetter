#ifndef CARD_H
#define CARD_H

#include <string>
#include "../GameCommon/GameDefinitions.h"

struct Card
{
    using Strength = unsigned char;
    CardType type;
    Strength strength;
};

#endif // CARD_H
