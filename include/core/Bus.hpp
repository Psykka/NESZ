#pragma once
#include "Types.hpp"

class Bus
{
    public:
        Bus();

        Byte ram[2048];
        uint64_t cycles;

        void tick();

        Byte readByte(Word addr);
        Word readWord();

        Word readNoncontinuousWord(Byte x, Byte y);
        Word readWord(Word addr);

        void writeByte(Word addr, Byte data);
};