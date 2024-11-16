#include "include/cpu.h"
#include "include/ControlInstructionSet.h"
#include "include/8bitALUInstructionSet.h"
#include "include/8bitLoadInstructionSet.h"
#include "include/8bitShiftInstructionSet.h"
#include "include/16bitALUInstructionSet.h"
#include "include/16bitLoadInstructionSet.h"
#include <iostream>

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
    HALT_FLAG = false;
    Interrupt vblank = {false, false, 0x0040};
    Interrupt lcdStat = {false, false, 0x0048};
    Interrupt timer = {false, false, 0x0050};
    Interrupt serial = {false, false, 0x0058};
    Interrupt joypad = {false, false, 0x0060};
}

void CPU::reset() {
}

void CPU::handleInterrupts() {
    std::cout << "TODO" << std::endl;
}

Word CPU::fetchPC() {
    Byte opcode = read(registers.program_counter);
    registers.program_counter++;
    return opcode;
}

void CPU::cycle() {
    Word opcode = fetchPC();
    if (!execute(opcode)) {
        std::cout << "Cannot execute opcode" << std::endl;
    }
    handleInterrupts();
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
