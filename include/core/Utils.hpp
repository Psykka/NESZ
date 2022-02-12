#pragma once
#include "Types.hpp"

namespace core
{
    class Utils
    {
    public:
        static bool cross(Word base, Byte offset);
        static Word offset(Word base, Byte offset);
        static Word lowByte(Word data);
        static Word highByte(Word data);
    };
}