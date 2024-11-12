#include <iostream>
#include "include/cpu.h" 
#include "include/memory.h"
#include "include/bus.h"

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

int main() {
    Memory memory;
    Bus bus(memory);
    CPU cpu(bus);

    // CPU-rework tests
    cpu.registers.a_register = 0x01;
    cpu.initializeInstructionTable();
    cpu.execute(0x00); // NOP
    cpu.execute(0x76); // HALT

    // 8bitALUInstructionSet tests
    cpu.registers.b_register = 0x01;
    cpu.execute(0x04); // INC B
    std::cout << "B register: " << std::hex << (int) cpu.registers.b_register << std::endl;
}
