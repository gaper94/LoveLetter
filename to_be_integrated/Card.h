#ifndef CARD_H
#define CARD_H

#include <string>
#include "GameDefinitions.h"

std::string CardTypeToString(CardType);
CardType CardTypeFromString(const std::string&);
std::string GetCardStrength(CardType);

struct Card
{
    typedef unsigned char Strength;

    CardType type ;      //1 2 3.. guard baron handmaid etc
    Strength strength;  // which one is the stronger card
};

#endif // CARD_H
