#include <iostream>
#include "cpu.cpp" // This is a hack, but it works for now.

int main() {

    // Basic bus unit test
    Memory memory;
    Registers registers;

    // Write on writeable memory
    Byte data = 0x48; 
    access(0x8000, false, &data);

    // Read from writeable memory
    access(0x8000, true, &data);
    std::cout << "Data at writeable memory: " << std::hex << (int)data << std::endl;

    // Write to read only memory
    access(0x0000, false, &data);

    // Read from read only memory
    access(0x0000, true, &data);
    std::cout << "Data at ROM: " << std::hex << (int)data << std::endl;

    // Write to echo memory
    data = 0x12;
    access(0xE000, false, &data);

    // Read from echo memory
    access(0xE000, true, &data);
    std::cout << "Data at echo memory (E000): " << std::hex << (int)data << std::endl;

    // Read from copy of echo memory
    access(0xC000, true, &data);
    std::cout << "Data at work RAM (C000): " << std::hex << (int)data << std::endl;

    // Write to forbidden memory
    access(0xFEA0, false, &data);

    // Read from forbidden memory
    access(0xFEA0, true, &data);
    std::cout << "Data at forbidden memory: (technically forbidden memory is supposed to crash the emulator... right now it should just ignore any read/write) " << std::hex << (int)data << std::endl;

}