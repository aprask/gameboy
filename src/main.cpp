#include <iostream>
#include "include/cpu.h" 
#include "include/memory.h"
#include "include/bus.h"
#include "include/cartridge.h"

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

int main() {
    Memory memory;
    Bus bus(memory);
    CPU cpu(bus);
    Cartridge cartridge;

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


    // // jr_e8 (0x18)
    cpu.registers.program_counter = 0x0005;
    std::cout << "PC:" << cpu.registers.program_counter << std::endl;
    cpu.execute(0x18);
    std::cout << "PC:" << cpu.registers.program_counter << std::endl;

    // rst_10H (0xD7)
    std::cout << "PC:" << cpu.registers.program_counter << std::endl;
    cpu.execute(0xD7);
    // should be 0x10
    std::cout << "PC:" << cpu.registers.program_counter << std::endl;

    // testing call_c_a16 (0xDC)
    cpu.registers.program_counter = 0x0002;
    std::cout << "PC:" << cpu.registers.program_counter << std::endl;
    cpu.registers.f |= (1 << C); // setting the carry flag
    cpu.execute(0xDC); // TODO finish testing
    std::cout << "PC:" << cpu.registers.program_counter << std::endl;


    cpu.registers.stack_pointer = 1;
    
    cpu.execute(0xC4);

    cpu.registers.f |= (1 << Z);

    cpu.execute(0xC8);


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


    cartridge.parse_rom("../roms/test_rom.gb");
    return 0;
}
