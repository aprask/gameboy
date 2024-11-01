#include <iostream>
#include "include/cpu.h" 
#include "include/memory.h"
#include "include/bus.h"
#include "include/InstructionSet.h"
#include "include/ControlInstructionSet.h"
#include "include/JumpInstructionSet.h"

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

int main() {
    Memory memory;
    Bus bus(memory);
    CPU cpu(bus);

    Byte input = 0x48;

    // Basic test

    // Writing to RAM
    cpu.write(0x8000, input);
    // Reading from RAM
    Byte output = cpu.read(0x8000);
    std::cout << "RAM Output: " << std::hex << output << std::endl; // Should be 48

    // Writing to ROM
    cpu.write(0x0000, input);
    // Reading from ROM
    output = cpu.read(0x0000);
    std::cout << "Rom Output: " << std::hex << output << std::endl; // Should be 00

    // Write to Echo RAM
    cpu.write(0xE000, input);
    // Read from Echo RAM
    output = cpu.read(0xE000);
    std::cout << "Echo Output (E000): " << std::hex << output << std::endl; // Should be 48
    std::cout << "Echo Output (C000): " << std::hex << cpu.read(0xC000) << std::endl; // Should be 48

    // Write to forbidden memory
    cpu.write(0xFEA0, input);
    // Read from forbidden memory
    output = cpu.read(0xFEA0); // Should not return anything
    std::cout << "Forbidden Memory Output: " << std::hex << output << std::endl;

    // testing ControlSetInstruction
    ControlInstructionSet control_instr;
    uint8_t opcode_test_1 = 0x10; // STOP
    if (control_instr.execute(opcode_test_1, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }

    // testing JumpInstructionSet
    JumpInstructionSet jump_instr;
    uint8_t opcode_test_2 = 0xC3; // JP a16
    if (jump_instr.execute(opcode_test_2, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }
    

    return 0;
}
