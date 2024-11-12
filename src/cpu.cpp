#include "include/cpu.h"
#include "include/ControlInstructionSet.h"
#include "include/8bitALUInstructionSet.h"
#include "include/8bitLoadInstructionSet.h"

ControlInstructionSet control_instruction_set;
EightBitALUInstructionSet eight_bit_alu_instruction_set;
EightBitLoadInstructionSet eight_bit_load_instruction_set;

CPU::CPU(Bus& bus) : bus(bus) {
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
}

bool CPU::execute(Word opcode) {
    if (instruction_table.find(opcode) == instruction_table.end()) {
        return false;
    }

    auto instruction = instruction_table.find(opcode);
    instruction->second();
    return true;
}
