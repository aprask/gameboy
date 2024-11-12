#include "include/cpu.h"

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

void CPU::initializeInstructionTable() {
    // This is where we are going to have each InstructionSet class add their own instructions to the table
    // The goal is modularity, this will be called on startup... not much overhead once the table is initialized... I hope.
}

bool CPU::executeInstruction(Word opcode) {
    // This is where we will look up the opcode in the table and execute the instruction
    return false;
}
