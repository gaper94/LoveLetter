#ifndef GENERIC_MSG_H
#define GENERIC_MSG_H

#include <string>
#include <map>
#include "Serializer.h"
#include "Deserializer.h"

class GenericMsg
{
public:
    std::string name;

    template<typename T>
    void AddValue(const std::string& valueName, const T& value);
    template<typename T>
    bool GetValue(const std::string& valueName, T& value) const;
    bool HasValue(const std::string& valueName) const;

    std::map<std::string, Serializer> m_valuesContainer;
};

#include "GenericMsg.hpp"

#endif // GENERIC_MSG_H
