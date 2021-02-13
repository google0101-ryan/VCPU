#pragma once

typedef unsigned char byte;

class memory
{
private:
    byte RAM[25];

public:
    byte read(byte address);
    void write(byte address, byte value);

    memory();
};