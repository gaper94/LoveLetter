#include "Card.h"

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


std::string GetCardStrength(CardType cardType)
{
    switch(cardType)
    {
        case CardType::Guard:      return "Choisissez un joueur et essayer de deviner sa carte";//
        case CardType::Priest:     return "Regardez la main d'un autre joueur";//
        case CardType::Baron:      return "Jusqu'au prochain tour, vous êtes protégé des effets des cartes des autres joueurs.";//done
        case CardType::Handmaiden: return "Comparez votre carte avec celle d'un autre joueur, celui qui a la carte avec la plus faible valeur est éliminé de la manche";//
        case CardType::Prince:     return "Choisissez un joueur (y comprisvous), celui-ci défausse la carte qu'il a en main pour en piocher une nouvelle.";//
        case CardType::King:       return "Échangez votre main avec un autre joueur de votre choix.";//
        case CardType::Countess:   return "En même temps que le King ou le Prince, alors vous devez défausser la carte de la Countess";
        case CardType::Princess:   return "Si vous défaussez cette carte,vous êtes éliminé de la manche.";//done
        default:                   return "";
    }
    return "";

}


