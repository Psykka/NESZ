#include "Bus.hpp"

Bus::Bus()
{
    for (auto&& i : ram) ram[i] = 0;
    cycles = 0;
}

void Bus::tick()
{
    cycles++;
}

Byte Bus::read_byte(Word addr)
{
    return ram[addr];
}

void Bus::write_byte(Word addr, Byte data)
{
    ram[addr] = data;
}

Word Bus::read_noncontinuous_word(Byte x, Byte y)
{
    return (read_byte(x) | read_byte(y)) << 8;
}

Word Bus::read_word(Word addr)
{
    return read_noncontinuous_word(addr, addr++);
}
