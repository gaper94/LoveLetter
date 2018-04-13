#include "GameUtils.h"

namespace Utils
{

std::string CardTypeToString(CardType cardType)
{
    switch(cardType)
    {
        case CardType::None:       return "None";
        case CardType::Guard:      return "Guard";
        case CardType::Priest:     return "Priest";
        case CardType::Baron:      return "Baron";
        case CardType::Handmaiden: return "Handmaid";
        case CardType::Prince:     return "Prince";
        case CardType::King:       return "King";
        case CardType::Countess:   return "Countess";
        case CardType::Princess:   return "Princess";
        default:                   return "";
    }
    return "";

}

CardType CardTypeFromString(const std::string& cardType)
{
    if(cardType == "Guard")
    {
        return CardType::Guard;
    }
    else if(cardType == "Priest")
    {
        return CardType::Priest;
    }
    else if(cardType == "Baron")
    {
        return CardType::Baron;
    }
    else if(cardType == "Handmaid")
    {
        return CardType::Handmaiden;
    }
    else if(cardType == "Prince")
    {
        return CardType::Prince;
    }
    else if(cardType == "King")
    {
        return CardType::King;
    }
    else if(cardType == "Countess")
    {
        return CardType::Countess;
    }
    else if(cardType == "Princess")
    {
        return CardType::Princess;
    }
    else
    {
        return CardType::None;
    }
}

}
