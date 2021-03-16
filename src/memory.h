#pragma once

#include <stdint.h>

typedef uint16_t byte;

class memory
{
private:
    byte RAM[255];

public:
    byte read(byte address);
    void write(byte address, byte value);
		void readFile(char* fileName);

    memory();
};