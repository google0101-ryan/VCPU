#include "memory.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

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

void memory::readFile(char* fileName)
{
	std::ifstream inFile;

	inFile.open(fileName, std::ios_base::in);

	if(!inFile) {
        std::cout<<"Couldn't open the file"<<std::endl;
        exit(1);
    }
		byte i = 1;
    std::string line;   
    while ( getline( inFile, line )) {
   
         std::stringstream str(line);
         byte num;
         str >> num;
				 std::cout << (int)num << std::endl;
				 if (num == 1)
				 {
					 num = 01;
				 }
         write(i, num);
				 i++;
     }
}