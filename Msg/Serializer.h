#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <vector>
#include <map>
#include <stdint.h>
#include <type_traits>
#include "TypesTools.h"

class Serializer
{
public:

    Serializer() {}

    friend Serializer& operator<<(Serializer& os, const uint8_t& data);
    friend Serializer& operator<<(Serializer& os, const int8_t& data);
    friend Serializer& operator<<(Serializer& os, const uint16_t& data);
    friend Serializer& operator<<(Serializer& os, const int16_t& data);
    friend Serializer& operator<<(Serializer& os, const uint32_t& data);
    friend Serializer& operator<<(Serializer& os, const int32_t& data);
    friend Serializer& operator<<(Serializer& os, const uint64_t& data);
    friend Serializer& operator<<(Serializer& os, const int64_t& data);
    friend Serializer& operator<<(Serializer& os, const float& data);
    friend Serializer& operator<<(Serializer& os, const double& data);
    friend Serializer& operator<<(Serializer& os, const std::string& data);
    friend Serializer& operator<<(Serializer& os, const char* data);
    friend Serializer& operator<<(Serializer& os, const std::vector<uint8_t>& data);
    friend Serializer& operator<<(Serializer& os, const Serializer& data);

    template<typename Key, typename Value>
    friend Serializer& operator<<(Serializer& os, const std::map<Key, Value>& data)
    {
        TypesTools::WriteMap(data.size(), os.m_buffer);
        for(const auto& elem : data)
        {
            os << elem.first << elem.second;
        }
        return os;
    }

    template<typename Value>
    friend Serializer& operator<<(Serializer& os, const std::vector<Value>& data)
    {
        TypesTools::WriteVector(data.size(), os.m_buffer);
        for(const auto& elem : data)
        {
            os << elem;
        }
        return os;
    }

    const TypesTools::Storage& GetBuffer() const;
    void SetBuffer(const TypesTools::Storage& buff);
    void Clear();

private:
    TypesTools::Storage m_buffer;
};

template<typename T>
Serializer& operator<<(Serializer& is, const T& data);

#endif // SERIALIZER_H
