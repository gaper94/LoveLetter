#ifndef DESERIALIZER_H
#define DESERIALIZER_H

#include <vector>
#include <stdint.h>
#include <string>
#include "TypesTools.h"
#include "Serializer.h"

class Deserializer
{
public:

    void Load(const TypesTools::Storage& buffer);

    friend Deserializer& operator>>(Deserializer& is, uint8_t& data);
    friend Deserializer& operator>>(Deserializer& is, int8_t& data);
    friend Deserializer& operator>>(Deserializer& is, uint16_t& data);
    friend Deserializer& operator>>(Deserializer& is, int16_t& data);
    friend Deserializer& operator>>(Deserializer& is, uint32_t& data);
    friend Deserializer& operator>>(Deserializer& is, int32_t& data);
    friend Deserializer& operator>>(Deserializer& is, int64_t& data);
    friend Deserializer& operator>>(Deserializer& is, uint64_t& data);
    friend Deserializer& operator>>(Deserializer& is, float& data);
    friend Deserializer& operator>>(Deserializer& is, double& data);
    friend Deserializer& operator>>(Deserializer& is, std::string& data);
    friend Deserializer& operator>>(Deserializer& is, std::vector<uint8_t>& data);
    friend Deserializer& operator>>(Deserializer& is, Serializer& os);

    template<typename Key, typename Value>
    friend Deserializer& operator>>(Deserializer& is, std::map<Key, Value>& data)
    {
        uint16_t numberOfElements = uint32_t();
        is.m_currentPos = TypesTools::ReadMap(numberOfElements, is.m_buffer, is.m_currentPos);
        data.clear();
        for(uint32_t i = 0; i < numberOfElements; i++)
        {
            Key k;
            Value v;
            is >> k >> v;
            data.insert({k, v});
        }
        return is;
    }

    template<typename Value>
    friend Deserializer& operator>>(Deserializer& is, std::vector<Value>& data)
    {
        uint16_t numberOfElements = uint32_t();
        is.m_currentPos = TypesTools::ReadVector(numberOfElements, is.m_buffer, is.m_currentPos);
        data.clear();
        for(uint32_t i = 0; i < numberOfElements; i++)
        {
            Value v;
            is >> v;
            data.push_back(v);
        }
        return is;
    }

private:
    TypesTools::Storage m_buffer;
    TypesTools::StreamPos m_currentPos{};
};

template<typename T>
Deserializer& operator>>(Deserializer& os, T& data);

#endif // DESERIALIZER_H
