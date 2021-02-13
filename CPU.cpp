#include "CPU.h"
#include <iostream>

using namespace std;

CPU::CPU(memory *RAM)
{
    regs[0] = R0;
    regs[1] = R1;
    pc = 1;
    m_Halt = false;
    this->RAM = RAM;
}

void CPU::Run()
{
    while (!m_Halt)
    {
        RAM->write(0, Fetch());
        Decode(RAM->read(0));
    }
    cout << "HALT Encountered" << endl;
}

byte CPU::Fetch()
{
    byte opcode = RAM->read(pc);
    return opcode;
}

void CPU::Decode(byte opcode)
{
    switch(opcode)
    {
    case 0:
        m_Halt = true;
        break;
    case 1:
        Load0(RAM->read(++pc));
        pc++;
        break;
    case 2:
        Load1(RAM->read(++pc));
        pc++;
        break;
    case 3:
        Add();
        break;
    case 4:
        Print();
        break;
    default:
        cout << "Unknown opcode!" << endl;
        m_Halt = true;
        break;
    }
}

void CPU::Load0(byte value)
{
    regs[0] = value;
}

void CPU::Load1(byte value)
{
    regs[1] = value;
}

void CPU::Add()
{
    regs[2] = regs[0] + regs[1];
    pc++;
}

void CPU::Print()
{
    cout << endl;
    cout << endl;
    cout << (int)regs[2] << endl;
    cout << endl;
    cout << endl;
    ++pc;
}