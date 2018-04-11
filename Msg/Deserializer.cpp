#include "Deserializer.h"

void Deserializer::Load(const TypesTools::Storage& buffer)
{
    m_currentPos = {};
    m_buffer = buffer;
}

Deserializer& operator>>(Deserializer& os, uint8_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, int8_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, uint16_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, int16_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, uint32_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, int32_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, int64_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, uint64_t& data)
{
    os.m_currentPos = TypesTools::ReadInteger(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, float& data)
{
    os.m_currentPos = TypesTools::ReadReal(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, double& data)
{
    os.m_currentPos = TypesTools::ReadReal(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, std::string& data)
{
    os.m_currentPos = TypesTools::ReadString(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, std::vector<uint8_t>& data)
{
    os.m_currentPos = TypesTools::ReadRawStream(data, os.m_buffer, os.m_currentPos);
    return os;
}

Deserializer& operator>>(Deserializer& os, Serializer& is)
{
    std::vector<uint8_t> buff;
    os >> buff;
    is.SetBuffer(buff);
    return os;
}
