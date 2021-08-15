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

Byte Bus::readByte(Word addr)
{
    return ram[addr];
}

void Bus::writeByte(Word addr, Byte data)
{
    ram[addr] = data;
}

Word Bus::readNoncontinuousWord(Byte x, Byte y)
{
    return (readByte(x) | readByte(y)) << 8;
}

Word Bus::readWord(Word addr)
{
    return readNoncontinuousWord(addr, addr++);
}
