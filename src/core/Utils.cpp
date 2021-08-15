#include "Utils.hpp"

bool Utils::cross(Word base, Byte offset)
{
    return highByte(base + offset) != highByte(base);
}

Word Utils::offset(Word base, Byte offset)
{
    return base + offset;
}

Word Utils::lowByte(Word data)
{
    return data & 0xFF;
}

Word Utils::highByte(Word data)
{
    return data & 0xFFFF;
}