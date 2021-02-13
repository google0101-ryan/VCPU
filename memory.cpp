#include "memory.h"

memory::memory()
{
    for (byte i = 0; i < 25; ++i)
    {
        RAM[i] = 0;
    }
}

byte memory::read(byte address)
{
    return RAM[address];
}

void memory::write(byte address, byte value)
{
    RAM[address] = value;
}