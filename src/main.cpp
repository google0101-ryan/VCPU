#include <iostream>

#include "CPU.h"
#include "memory.h"

using namespace std;

int main()
{
    memory *RAM = new memory();
    CPU *cpu = new CPU(RAM);
    bool debug = false;

		RAM->readFile("src/prog.vasm");

/*
    int num1;
    int num2;

    cout << "Number 1 to add: ";
    cin >> num1;
    cout << "Number 2 to add: ";
    cin >> num2;

    RAM->write(1, 01); // Write num1 to reg[0]
    RAM->write(2, num1); 
    RAM->write(3, 10); //Write num2 to reg[1]
    RAM->write(4, num2);
    RAM->write(5, 11); // Add reg[0] and reg[1]; store in reg[2]
    RAM->write(6, 100); //Call interrupt 0x10 (Print())
    RAM->write(7, 0x10);
    RAM->write(8, 101); // Multiply reg[0] by reg[1]; Store in reg[2]
    RAM->write(9, 100); // Call interrupt 0x10 (Print())
    RAM->write(10, 0x10);
*/
    cout << "Memory Contents: " << endl;

    for (auto i = 0; i < 255; ++i)
    {
        cout << "Address[" << (int)i << "]: " << (int)RAM->read(i) << endl;
    }

    cout << "Running Program from memory" << endl;

    cpu->Run();

    cout << "Complete. Reg dump: " << endl;

    for (byte i = 0; i < cpu->R_COUNT; ++i)
    {
        cout << "Reg[" << (int)i << "]: " << (int)cpu->regs[i] << endl;
    }

    cout << "Program Counter: " << (int)cpu->pc << endl; 
}