#include <iostream>

#include "CPU.h"

using namespace std;

int main()
{
    memory *RAM = new memory();
    CPU *cpu = new CPU(RAM);
    bool debug = false;

    int num1;
    int num2;

    cout << "Number 1 to add: ";
    cin >> num1;
    cout << "Number 2 to add: ";
    cin >> num2;

    RAM->write(1, 1);
    RAM->write(2, num1);
    RAM->write(3, 2);
    RAM->write(4, num2);
    RAM->write(5, 3);
    RAM->write(6, 4);

    cout << "Memory Contents: " << endl;

    for (byte i = 0; i < 25; ++i)
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
}