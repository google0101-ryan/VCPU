#pragma once

#include <stdint.h>

typedef uint16_t byte;

class memory
{
private:
    byte RAM[25];

public:
    byte read(byte address);
    void write(byte address, byte value);
		void readFile(char* fileName);

    memory();
};