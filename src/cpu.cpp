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
    vblank = {false, false, 0x0040};
    lcdStat = {false, false, 0x0048};
    timer = {false, false, 0x0050};
    serial = {false, false, 0x0058};
    joypad = {false, false, 0x0060};
}

void CPU::reset() {
}

void CPU::handleInterrupts() {
    std::cout << "Interrupt" << std::endl;
}

// Fetches the next opcode from the memory address stored in the program counter
Word CPU::fetchPC() {
    Byte opcode = read(registers.program_counter);
    registers.program_counter++;
    return opcode;
}

void CPU::cycle() {
    Word opcode = fetchPC();
    if (!execute(opcode)) {
        std::cout << "Cannot execute opcode" << std::endl;
    } else {
        std::cout << "Executed opcode" << std::endl;
    }
    handleInterrupts();
}

// Writes the data to the memory address
void CPU::write(Word address, Byte data) {
    bus.write(address, data);
}

// Reads the data at the memory address
Byte CPU::read(Word address) {
    return bus.read(address);
}

// Adds the instruction to the instruction table
void CPU::addInstruction(Word opcode, Instruction instruction) {
    instruction_table[opcode] = instruction;
}

// Initializes the instruction table with the instructions from the instruction sets
void CPU::initializeInstructionTable() {
    control_instruction_set.initializeInstructionTable(*this);
    eight_bit_alu_instruction_set.initializeInstructionTable(*this);
    eight_bit_load_instruction_set.initializeInstructionTable(*this);
    eight_bit_shift_instruction_set.initializeInstructionTable(*this);
    sixteen_bit_alu_instruction_set.initializeInstructionTable(*this);
    sixteen_bit_load_instruction_set.initializeInstructionTable(*this);
}

// Executes the instruction stored in the opcode
bool CPU::execute(Word opcode) {
    if (instruction_table.find(opcode) == instruction_table.end()) {
        return false;
    }

    auto instruction = instruction_table.find(opcode);
    instruction->second();
    return true;
}

// Reads the value at the memory address stored in the register pair
Byte CPU::readPair(int pair) {
    switch (pair) {
        case AF:
            read(getPair(AF));
        case BC:
            read(getPair(BC));
        case DE:
            read(getPair(DE));
        case HL:
            read(getPair(HL));
        default:
            return 0;
    }
}

// Writes the value provided to the memory address stored in the register pair
void CPU::writePair(int pair, Byte value) {
    switch (pair) {
        case AF:
            write(getPair(AF), value);
        case BC:
            write(getPair(BC), value);
        case DE:
            write(getPair(DE), value);
        case HL:
            write(getPair(HL), value);
        default:
            break;
    }
}

// Returns the data stored in the register pair
Word CPU::getPair(int pair) {
    switch (pair) {
        case AF:
            return (registers.a << 8) | registers.f;
        case BC:
            return (registers.b << 8) | registers.c;
        case DE:
            return (registers.d << 8) | registers.e;
        case HL:
            return (registers.h << 8) | registers.l;
        default:
            return 0;
    }
}

// Sets the register pair to the Word value
void CPU::setPair(int pair, Word value) {
    switch (pair) {
        case AF:
            registers.a = value >> 8;
            registers.f = value & 0x00FF;
            break;
        case BC:
            registers.b = value >> 8;
            registers.c = value & 0x00FF;
            break;
        case DE:
            registers.d = value >> 8;
            registers.e = value & 0x00FF;
            break;
        case HL:
            registers.h = value >> 8;
            registers.l = value & 0x00FF;
            break;
        default:
            break;
    }
}

// Returns the value of the specified bit in the specified register
bool CPU::getBit(Byte& reg, Byte bit) {
    return (reg >> bit) & 1;
}

// Sets the specified bit in the specified register to the specified value
void CPU::setBit(Byte& reg, unsigned int bit, bool value) {
    if (value) {
        reg |= (1 << bit);
    } else {
        reg &= ~(1 << bit);
    }
}
