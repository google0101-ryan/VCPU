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
    cout << "\nHALT Encountered" << endl;
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
    case 10:
        Load1(RAM->read(++pc));
        pc++;
        break;
    case 11:
        Add();
        break;
    case 100:
        Int(RAM->read(++pc));
        break;
    case 101:
        Mul();
        break;
    case 110:
        printf("Push\n");
        Push(RAM->read(++pc));
        break;
    case 111:
        printf("Pop reg[0]\n");
        regs[R0] = Pop();
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

void CPU::Mul()
{
    int tmp1 = (int)regs[0];
    int tmp2 = (int)regs[1];
    regs[2] = (byte)(tmp1 * tmp2);
    pc++;
}

void CPU::Int(byte interrupt)
{
    switch(interrupt)
    {
    case 10:
        Print();
        break;
    default:
        cout << "Unknown Interrupt! Halting" << endl;
        m_Halt = true;
        break;
    }
}

void CPU::Push(byte value) 
{
    RAM->write(sp, value);
    sp++;
    pc++;
}

byte CPU::Pop()
{
    uint8_t value = RAM->read(sp);
    sp--;
    pc++;
    return value;
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