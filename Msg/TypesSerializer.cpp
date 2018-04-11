#include "Serializer.h"
#include "Deserializer.h"
#include "TestStruct.h"
#include "GenericMsg.h"

template<>
Serializer& operator<<(Serializer& os, const Foo& data)
{
    os << data.a << data.b;
    return os;
}

template<>
Deserializer& operator>>(Deserializer& is, Foo& data)
{
    is >> data.a >> data.b;
    return is;
}
