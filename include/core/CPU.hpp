#pragma once
#include "Types.hpp"
#include "Bus.hpp"

class CPU {
    enum Flag {
        C = 1 << 0, // Carry
        Z = 1 << 1, // Zero
        I = 1 << 2, // Interrupts
        D = 1 << 3, // Decimal
        // B = 1 << 4, // Break
        V = 1 << 6, // Overflow
        N = 1 << 7  // Negative
    };

    enum Mode {
        ZP0, // Zero Page
        ZPX, // Zero Page X
        ZPY, // Zero Page Y
        ABS, // Absolute
        ABX, // Absolute X
        ABY, // Absolute Y
        IND, // Indirect
        IZX, // Indirect X
        IZY, // Indirect Y
        // IMP, // Implicit
        IMM, // Immediate
        // REL, // Relative
    };

    public:
        CPU();
        Bus bus;
        Word pc;
        Byte sp, a, x, y, p;

        void runNextInstruction();
        
    private:
        bool getFlag(Flag flag);
        void setFlag(Flag flag, bool value);

        void setFlagsZeroNegative(Byte value);
        void setFlagsCarryOverflow(Byte m, Byte n, Word value);
        Byte carry();

        Byte nextByte();
        Word nextWord();
        
        Word getAddr(Mode mode);
        void runInstruction(Byte opcode);

        // load & Store
        void LDA(Mode mode); void STA(Mode mode);
        void LDX(Mode mode); void STX(Mode mode);
        void LDY(Mode mode); void STY(Mode mode);
};