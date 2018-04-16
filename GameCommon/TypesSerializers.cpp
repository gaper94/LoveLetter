#include "../Msg/Serializer.h"
#include "../Msg/Deserializer.h"
#include "../GameCommon/Card.h"

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

