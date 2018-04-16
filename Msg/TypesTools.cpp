#include "TypesTools.h"
#include <cstring>

namespace TypesTools
{
// Fields
//    1. Size of the field (2 bytes)
//    2. Type of the field (1 byte)
//       - 1. Integer field
//       - 2. String
//       - 3. Array
//       - 4. RawStream
//       - 5. Map
//    3. Number of elements (2 bytes)
//       Remark: Present only when field 2 is array or map
//    4. Raw data (filed number of bytes)

typedef uint16_t SizeType;

const SizeType SizeFieldLength = 2;
const SizeType TypeFieldLength = 1;
const SizeType NumberOfElementsFieldLength = 2;

enum class FieldTypes : uint8_t
{
    Invalid = 0,
    Integer,
    String,
    Array,
    RawStream,
    Map,
};

template<typename T>
StreamPos WriteRaw( const T& data, SizeType bytesToWrite,
                    Storage& buffer, StreamPos currentPos)
{
    std::memcpy(buffer.data() + currentPos, &data, bytesToWrite);
    return currentPos + bytesToWrite;
}

template<typename T>
StreamPos WriteRawFromPointer( const T* data, SizeType bytesToWrite,
                    Storage& buffer, StreamPos currentPos)
{
    std::memcpy(buffer.data() + currentPos, data, bytesToWrite);
    return currentPos + bytesToWrite;
}

template<typename T>
StreamPos WriteRaw(const T& data, Storage& buffer, StreamPos currentPos)
{
    auto bytesToWrite = sizeof(T);
    return WriteRaw(data, bytesToWrite, buffer, currentPos);
}

template<typename T>
StreamPos ReadRaw(T& data, SizeType bytesToRead,
                  Storage& buffer, StreamPos currentPos)
{
    std::memcpy(&data, buffer.data() + currentPos, bytesToRead);
    return currentPos + bytesToRead;
}

template<typename T>
StreamPos ReadRaw(T* data, SizeType bytesToRead,
                  Storage& buffer, StreamPos currentPos)
{
    std::memcpy(data, buffer.data() + currentPos, bytesToRead);
    return currentPos + bytesToRead;
}

template<typename T>
StreamPos ReadRaw(T& data, Storage& buffer, StreamPos currentPos)
{
    auto bytesToRead = sizeof(T);
    return ReadRaw(data, bytesToRead, buffer, currentPos);
}

void WriteRawStream(std::vector<uint8_t> value, Storage& buffer)
{
    Storage temp;
    SizeType FieldSize = value.size();
    auto bufferSize = SizeFieldLength + TypeFieldLength + FieldSize;
    temp.resize(bufferSize);
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::RawStream);
    StreamPos currentPos = 0;
    currentPos = WriteRaw(FieldSize, temp, currentPos);
    currentPos = WriteRaw(FieldType, temp, currentPos);
    currentPos = WriteRawFromPointer(value.data(), FieldSize, temp, currentPos);
    //
    buffer.insert(buffer.end(), temp.begin(), temp.end());
}

template<typename T>
void IntegerFieldSerializer(const T& value, Storage& buffer)
{
    Storage temp;
    SizeType FieldSize = sizeof(T);
    auto bufferSize = SizeFieldLength + TypeFieldLength + FieldSize;
    temp.resize(bufferSize);
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Integer);
    StreamPos currentPos = 0;
    currentPos = WriteRaw(FieldSize, temp, currentPos);
    currentPos = WriteRaw(FieldType, temp, currentPos);
    currentPos = WriteRaw(value, temp, currentPos);
    //
    buffer.insert(buffer.end(), temp.begin(), temp.end());
}

void WriteInteger(uint8_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(int8_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(uint16_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(int16_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(uint32_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(int32_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(uint64_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteInteger(int64_t value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteReal(float value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteReal(double value, Storage& buffer)
{
    IntegerFieldSerializer(value, buffer);
}

void WriteString(const char* str, Storage& buffer)
{
    if(str == nullptr)
    {
        return;
    }
    //
    Storage temp;
    SizeType FieldSize = strlen(str);
    auto bufferSize = SizeFieldLength + TypeFieldLength + FieldSize;
    temp.resize(bufferSize);
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::String);
    StreamPos currentPos = 0;
    currentPos = WriteRaw(FieldSize, temp, currentPos);
    currentPos = WriteRaw(FieldType, temp, currentPos);
    currentPos = WriteRawFromPointer(str, FieldSize, temp, currentPos);
    //
    buffer.insert(buffer.end(), temp.begin(), temp.end());
}

void WriteString(const std::string& str, Storage& buffer)
{
    WriteString(str.c_str(), buffer);
}

void WriteVector(uint16_t numberOfElements, Storage& buffer)
{
    Storage temp;
    SizeType FieldSize = 0;
    auto bufferSize = SizeFieldLength + TypeFieldLength + FieldSize + NumberOfElementsFieldLength;
    temp.resize(bufferSize);
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Array);
    StreamPos currentPos = 0;
    currentPos = WriteRaw(FieldSize, temp, currentPos);
    currentPos = WriteRaw(FieldType, temp, currentPos);
    currentPos = WriteRaw(numberOfElements, temp, currentPos);
    //
    buffer.insert(buffer.end(), temp.begin(), temp.end());
}

void WriteMap(uint16_t numberOfElements, Storage& buffer)
{
    Storage temp;
    SizeType FieldSize = 0;
    auto bufferSize = SizeFieldLength + TypeFieldLength + FieldSize + NumberOfElementsFieldLength;
    temp.resize(bufferSize);
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Map);
    StreamPos currentPos = 0;
    currentPos = WriteRaw(FieldSize, temp, currentPos);
    currentPos = WriteRaw(FieldType, temp, currentPos);
    currentPos = WriteRaw(numberOfElements, temp, currentPos);
    //
    buffer.insert(buffer.end(), temp.begin(), temp.end());
}

StreamPos ReadRawStream(std::vector<uint8_t>& value, Storage& buffer, StreamPos currentPos)
{
    SizeType FieldSize{};
    StreamPos tempPos = currentPos;
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Invalid);
    tempPos = ReadRaw(FieldSize, buffer, tempPos);
    tempPos = ReadRaw(FieldType, buffer, tempPos);

    if(FieldType != static_cast<uint8_t>(FieldTypes::RawStream))
    {
        return currentPos;
    }

    value.resize(FieldSize);
    tempPos = ReadRaw(value.data(), FieldSize, buffer, tempPos);
    return tempPos;
}

template<typename T>
StreamPos IntegerFieldDeserializer(T& value, Storage& buffer, StreamPos currentPos)
{
    SizeType FieldSize{};
    StreamPos tempPos = currentPos;
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Invalid);
    tempPos = ReadRaw(FieldSize, buffer, tempPos);
    tempPos = ReadRaw(FieldType, buffer, tempPos);

    if(FieldType != static_cast<uint8_t>(FieldTypes::Integer))
    {
        return currentPos;
    }

    tempPos = ReadRaw(value, buffer, tempPos);
    return tempPos;
}

StreamPos ReadInteger(uint8_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(int8_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(uint16_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(int16_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(uint32_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(int32_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(uint64_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadInteger(int64_t& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadReal(float& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadReal(double& value, Storage& buffer, StreamPos currentPos)
{
    return IntegerFieldDeserializer(value, buffer, currentPos);
}

StreamPos ReadString(std::string& value, Storage& buffer, StreamPos currentPos)
{
    SizeType FieldSize{};
    StreamPos tempPos = currentPos;
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Invalid);
    tempPos = ReadRaw(FieldSize, buffer, tempPos);
    tempPos = ReadRaw(FieldType, buffer, tempPos);

    if(FieldType != static_cast<uint8_t>(FieldTypes::String))
    {
        return currentPos;
    }

    std::vector<char> temp;
    temp.resize(FieldSize + 1);

    tempPos = ReadRaw(temp.data(), FieldSize, buffer, tempPos);
    value = temp.data();
    return tempPos;
}

StreamPos ReadVector(uint16_t& numberOfElements, Storage& buffer, StreamPos currentPos)
{
    SizeType FieldSize{};
    StreamPos tempPos = currentPos;
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Invalid);
    tempPos = ReadRaw(FieldSize, buffer, tempPos);
    tempPos = ReadRaw(FieldType, buffer, tempPos);

    if(FieldType != static_cast<uint8_t>(FieldTypes::Array))
    {
        return currentPos;
    }

    numberOfElements = 0;
    tempPos = ReadRaw(numberOfElements, buffer, tempPos);
    return tempPos;
}

StreamPos ReadMap(uint16_t& numberOfElements, Storage& buffer, StreamPos currentPos)
{
    SizeType FieldSize{};
    StreamPos tempPos = currentPos;
    uint8_t FieldType = static_cast<uint8_t>(FieldTypes::Invalid);
    tempPos = ReadRaw(FieldSize, buffer, tempPos);
    tempPos = ReadRaw(FieldType, buffer, tempPos);

    if(FieldType != static_cast<uint8_t>(FieldTypes::Map))
    {
        return currentPos;
    }

    numberOfElements = 0;
    tempPos = ReadRaw(numberOfElements, buffer, tempPos);
    return tempPos;
}

}
