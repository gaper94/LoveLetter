#include "Serializer.h"

Serializer& operator<<(Serializer& os, const uint8_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const int8_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const uint16_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const int16_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const uint32_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const int32_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const uint64_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const int64_t& data)
{
    TypesTools::WriteInteger(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const float& data)
{
    TypesTools::WriteReal(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const double& data)
{
    TypesTools::WriteReal(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const std::string& data)
{
    TypesTools::WriteString(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const char* data)
{
    TypesTools::WriteString(data, os.m_buffer);
    return os;
}

Serializer& operator<<(Serializer& os, const std::vector<uint8_t>& data)
{
    TypesTools::WriteRawStream(data, os.m_buffer);
    return os;
}


Serializer& operator<<(Serializer& os, const Serializer& data)
{
    os << data.m_buffer;
    return os;
}

const TypesTools::Storage& Serializer::GetBuffer() const
{
    return m_buffer;
}

void Serializer::SetBuffer(const TypesTools::Storage& buff)
{
    m_buffer = buff;
}

void Serializer::Clear()
{
    m_buffer.clear();
}
