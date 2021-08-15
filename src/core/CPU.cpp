#include <stdexcept>
#include "CPU.hpp"
#include "Utils.hpp"

CPU::CPU()
{
    pc, sp, a, x, y, p = 0;
}

bool CPU::get_flag(Flag flag)
{
    return p & flag != 0;
}

void CPU::set_flag(Flag flag, bool value)
{
    if(value) {
        p |= flag;
    } else {
        p &= !flag;
    }
}

void CPU::set_flags_zero_negative(Byte value)
{
    set_flag(Z, value == 0);
    set_flag(N, (value & 1 << 7) != 0);
}

void CPU::set_flags_carry_overflow(Byte m, Byte n, Word value)
{
    set_flag(C, value > 0xFF);
    set_flag(V, (m ^ value) & (n ^ value) & 0x80 != 0);
}

Byte CPU::carry()
{
    return p & C;
}

Byte CPU::next_byte()
{
    Byte x = pc;
    pc++;
    return bus.read_byte(x);
}

Word CPU::next_word()
{
    Byte x = pc;
    pc += 2;
    return bus.read_byte(x);
}

Word CPU::get_addr(Mode mode)
{
    switch (mode)
    {
        case ZP0:
            return next_byte();
        case ZPX:
            bus.tick();
            return Utils::low_byte(Utils::offset(next_byte(), x));
        case ZPY:
            bus.tick();
            return Utils::low_byte(Utils::offset(next_byte(), y));
        case ABS:
            return next_word();
        case ABX:
        {
            Word data = next_word();
            if (Utils::cross(data, x)) bus.tick();
            
            return Utils::offset(data, x);
        }
        case ABY:
        {
            Word data = next_word();
            if (Utils::cross(data, y)) bus.tick();

            return Utils::offset(data, y);
        }
        case IND:
        {
            Word i = next_word();
            return bus.read_noncontinuous_word(i, Utils::high_byte(i) | Utils::low_byte(i++));
        }
        case IZX:
        {
            bus.tick();
            Word i = Utils::offset(next_byte(), x);
            return bus.read_noncontinuous_word(i, Utils::low_byte(i) | Utils::low_byte(i++));;
        }
        case IZY:
        {
            Word i = next_word();
            Word data = bus.read_noncontinuous_word(i, Utils::low_byte(i++));

            if (Utils::cross(data, y)) bus.tick();

            return Utils::offset(data, y);
        }
        case IMM:
        {
            Byte i = pc;
            pc++;
            return i;
        }
        default:
            throw std::runtime_error("No addressing mode");
    }
}

void CPU::run_next_instruction()
{
    run_instruction(next_byte());
}

void CPU::run_instruction(Byte opcode)
{
    switch (opcode)
    {
    case 0xa9:
        return LDA(IMM);
    case 0xa5:
        return LDA(ZP0);
    case 0xb5:
        return LDA(ZPX);
    case 0xad:
        return LDA(ABS);
    case 0xbd:
        return LDA(ABX);
    case 0xb9:
        return LDA(ABY);
    case 0xa1:
        return LDA(IZX);
    case 0xb1:
        return LDA(IZY);
    default:
        pc++;
    }
}

void CPU::LDA(Mode mode)
{
    Byte data = get_addr(mode);
    set_flags_zero_negative(data);
    a = data;
}

void CPU::LDX(Mode mode)
{
    Byte data = get_addr(mode);
    set_flags_zero_negative(data);
    x = data;
}

void CPU::LDY(Mode mode)
{
    Byte data = get_addr(mode);
    set_flags_zero_negative(data);
    y = data;
}

void CPU::STA(Mode mode)
{
    Byte data = get_addr(mode);
    bus.write_byte(data, a);
}

void CPU::STX(Mode mode)
{
    Byte data = get_addr(mode);
    bus.write_byte(data, x);
}

void CPU::STY(Mode mode)
{
    Byte data = get_addr(mode);
    bus.write_byte(data, y);
}