#include "GenericMsg.h"

bool GenericMsg::HasValue(const std::string& valueName) const
{
    auto it = m_valuesContainer.find(valueName);
    if(it != m_valuesContainer.end())
    {
        return true;
    }
    return false;
}

template<>
Serializer& operator<<(Serializer& os, const GenericMsg& data)
{
    os << data.name << data.m_valuesContainer;
    return os;
}

template<>
Deserializer& operator>>(Deserializer& is, GenericMsg& data)
{
    is >> data.name >> data.m_valuesContainer;
    return is;
}
