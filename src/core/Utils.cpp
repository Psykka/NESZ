#include "Utils.hpp"

bool Utils::cross(Word base, Byte offset)
{
    return high_byte(base + offset) != high_byte(base);
}

Word Utils::offset(Word base, Byte offset)
{
    return base + offset;
}

Word Utils::low_byte(Word data)
{
    return data & 0xFF;
}

Word Utils::high_byte(Word data)
{
    return data & 0xFFFF;
}