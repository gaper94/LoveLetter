#include "../Msg/Serializer.h"
#include "../Msg/Deserializer.h"
#include "Card.h"
#include "GameDefinitions.h"

template<>
Serializer& operator<<(Serializer& os, const Card& data)
{
    os << static_cast<int32_t>(data.type) << data.strength;
    return os;
}

template<>
Deserializer& operator>>(Deserializer& is, Card& data)
{
    int32_t cardType;
    is >> cardType >> data.strength;
    data.type = static_cast<CardType>(cardType);
    return is;
}

template<>
Serializer& operator<<(Serializer& os, const AIPlayerCfg& data)
{
    os << data.name << static_cast<int32_t>(data.difficulty);
    return os;
}

template<>
Deserializer& operator>>(Deserializer& is, AIPlayerCfg& data)
{
    int32_t difficulty;
    is >> data.name >> difficulty;
    data.difficulty = static_cast<AIPlayerDifficulty>(difficulty);
    return is;
}

template<>
Serializer& operator<<(Serializer& os, const PlayerHand& data)
{
    os << data.name << data.cards;
    return os;
}

template<>
Deserializer& operator>>(Deserializer& is, PlayerHand& data)
{
    is >> data.name >> data.cards;
    return is;
}

