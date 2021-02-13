#pragma once

#include "memory.h"

class CPU
{
public:
    enum Registers
    {
        R0,
        R1,
        PC,
        R_COUNT
    };

    byte regs[R_COUNT];
private:

    bool m_Halt;

    memory *RAM;

    byte Fetch();

    void Decode(byte opcode);

    int jmpTimes;

public:
    CPU(memory *RAM);
    void Run();
    void Load0(byte value);
    void Load1(byte value);
    void Add();
    void Print();

    byte pc;
};