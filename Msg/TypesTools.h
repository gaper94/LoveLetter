#ifndef TYPES_TOOLS_H
#define TYPES_TOOLS_H

#include <stdint.h>
#include <vector>
#include <string>
#include <map>

namespace TypesTools
{
    typedef uint32_t StreamPos;
    typedef std::vector<uint8_t> Storage;

    void WriteRawStream(std::vector<uint8_t> value, Storage& buffer);

    void WriteInteger(uint8_t value, Storage& buffer);
    void WriteInteger(int8_t value, Storage& buffer);

    void WriteInteger(uint16_t value, Storage& buffer);
    void WriteInteger(int16_t value, Storage& buffer);

    void WriteInteger(uint32_t value, Storage& buffer);
    void WriteInteger(int32_t value, Storage& buffer);

    void WriteInteger(uint64_t value, Storage& buffer);
    void WriteInteger(int64_t value, Storage& buffer);

    void WriteReal(float value, Storage& buffer);
    void WriteReal(double value, Storage& buffer);

    void WriteString(const char* str, Storage& buffer);
    void WriteString(const std::string& str, Storage& buffer);

    void WriteMap(uint16_t numberOfElements, Storage& buffer);

    //
    StreamPos ReadRawStream(std::vector<uint8_t>& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadInteger(uint8_t& value, Storage& buffer, StreamPos currentPos);
    StreamPos ReadInteger(int8_t& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadInteger(uint16_t& value, Storage& buffer, StreamPos currentPos);
    StreamPos ReadInteger(int16_t& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadInteger(uint32_t& value, Storage& buffer, StreamPos currentPos);
    StreamPos ReadInteger(int32_t& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadInteger(uint64_t& value, Storage& buffer, StreamPos currentPos);
    StreamPos ReadInteger(int64_t& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadReal(float& value, Storage& buffer, StreamPos currentPos);
    StreamPos ReadReal(double& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadString(std::string& value, Storage& buffer, StreamPos currentPos);

    StreamPos ReadMap(uint16_t& numberOfElements, Storage& buffer, StreamPos currentPos);
}

#endif // TYPES_TOOLS_H
