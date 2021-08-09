#pragma once
#include "Types.hpp"

class Bus
{
    public:
        Bus();

        Byte ram[2048];
        uint64_t cycles;

        void tick();

        Byte read_byte(Word addr);
        Word read_word();

        Word read_noncontinuous_word(Byte x, Byte y);
        Word read_word(Word addr);

        void write_byte(Word addr, Byte data);
};