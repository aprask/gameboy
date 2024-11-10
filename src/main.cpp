#include <iostream>
#include "include/cpu.h" 
#include "include/memory.h"
#include "include/bus.h"
#include "include/InstructionSet.h"
#include "include/ControlInstructionSet.h"
#include "include/JumpInstructionSet.h"
#include "include/8bitLoadInstructionSet.h"
#include "include/16bitLoadInstructionSet.h"
#include "include/16bitALUInstructionSet.h"
#include "include/8bitShiftInstructionSet.h"
#include "testing/include/8bitALUTesting.h"

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
    
    // testing EightBitLoadInstructionSet
    EightBitLoadInstructionSet eight_bit_load_instr;
    uint8_t opcode_test_3 = 0x06; // LD B, n8
    if (eight_bit_load_instr.execute(opcode_test_3, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }

    uint8_t opcode_test_3b = 0xF0;
    std::cout << "PC: " << cpu.registers.program_counter << std::endl;
    if (eight_bit_load_instr.execute(opcode_test_3b, cpu)) {
        std::cout << "PC: " << cpu.registers.program_counter << std::endl;
    }

    // testing SixteenBitLoadInstructionSet
    SixteenBitLoadInstructionSet sixteen_bit_load_instr;
    uint8_t opcode_test4 = 0xC1; // POP_BC
    if (sixteen_bit_load_instr.execute(opcode_test4, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }

    // testing EightBitShiftInstructionSet
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode_test5A = 0xCB01;
    uint8_t opcode_test6A = 0x17;
    if (eight_bit_shift_instr.execute(opcode_test6A, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }
    if (eight_bit_shift_instr.execute_prefix(opcode_test5A, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }

    // testing SixteenBitALUInstructionSet
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    uint8_t opcode_test6 = 0x03; // INC BC
    if (sixteen_bit_alu_instr.execute(opcode_test6, cpu)) {
        std::cout << "Found memory match" << std::endl;
    } else {
        std::cout << "Could not find memory location in Instruction Set" << std::endl;
    }

    // testing 8bitALUTesting
    EightBitALUTesting eight_bit_alu_test;
    eight_bit_alu_test.run(cpu);
}
