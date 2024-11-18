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
    cpu.registers.a = 0x01;
    cpu.initializeInstructionTable();
    cpu.execute(0x00); // NOP
    cpu.execute(0x76); // HALT

    // 8bitALUInstructionSet tests
    cpu.registers.b = 0x01;
    cpu.execute(0x04); // INC B
    std::cout << "B register: " << std::hex << (int) cpu.registers.b << std::endl;

    // 8bitLoadInstructionSet tests
    cpu.write(0xC000, 0x01);
    cpu.registers.program_counter = 0xC000;
    cpu.registers.b = 0x00;
    cpu.execute(0x06); // LD B, n8
    std::cout << "B register: " << std::hex << (int) cpu.registers.b << std::endl;

    // 8bitShiftInstructionSet tests
    cpu.registers.b = 0x01;
    cpu.execute(0xCB30); // SWAP B
    std::cout << "B register: " << std::hex << (int) cpu.registers.b << std::endl;

    cpu.registers.program_counter = 0x0000;
    cpu.HALT_FLAG = false;

    // testing 5 cpu cycles
    while (true) {
        if (cpu.HALT_FLAG) {
            continue;
        }
        cpu.cycle();
        // temp exit cond
        if (cpu.registers.program_counter == 0x0005) break;
    }
    return 0;
}
