#pragma once
#include "Types.hpp"

class Utils
{
    public:
        static bool cross(Word base, Byte offset);
        static Word offset(Word base, Byte offset);
        static Word lowByte(Word data);
        static Word highByte(Word data);
};