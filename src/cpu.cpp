#include "include/cpu.h"
#include "include/ControlInstructionSet.h"
#include "include/8bitALUInstructionSet.h"
#include "include/8bitLoadInstructionSet.h"
#include "include/8bitShiftInstructionSet.h"
#include "include/16bitALUInstructionSet.h"
#include "include/16bitLoadInstructionSet.h"

ControlInstructionSet control_instruction_set;
EightBitALUInstructionSet eight_bit_alu_instruction_set;
EightBitLoadInstructionSet eight_bit_load_instruction_set;
EightBitShiftInstructionSet eight_bit_shift_instruction_set;
SixteenBitALUInstructionSet sixteen_bit_alu_instruction_set;
SixteenBitLoadInstructionSet sixteen_bit_load_instruction_set;

CPU::CPU(Bus& bus) : bus(bus) {
    IME_FLAG = false; // disable interrupts by default (until EI is called, then IME_FLAG is set to true)
        // Reasoning: Interrupts could interfere with the BIOS set up. If the system "NEEDS" interrupts, it will enable them.
        // More, this is how the actual Gameboy worked. When you boot it up, interrupts are disabled.
}

void CPU::reset() {
}

void CPU::cycle() {
}


void CPU::write(Word address, Byte data) {
    bus.write(address, data);
}

Byte CPU::read(Word address) {
    return bus.read(address);
}

void CPU::addInstruction(Word opcode, Instruction instruction) {
    instruction_table[opcode] = instruction;
}

void CPU::initializeInstructionTable() {
    control_instruction_set.initializeInstructionTable(*this);
    eight_bit_alu_instruction_set.initializeInstructionTable(*this);
    eight_bit_load_instruction_set.initializeInstructionTable(*this);
    eight_bit_shift_instruction_set.initializeInstructionTable(*this);
    sixteen_bit_alu_instruction_set.initializeInstructionTable(*this);
    sixteen_bit_load_instruction_set.initializeInstructionTable(*this);
}

bool CPU::execute(Word opcode) {
    if (instruction_table.find(opcode) == instruction_table.end()) {
        return false;
    }

    auto instruction = instruction_table.find(opcode);
    instruction->second();
    return true;
}
