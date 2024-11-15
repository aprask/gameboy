#include "include/16bitALUInstructionSet.h"

void SixteenBitALUInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x03, [this, &cpu] { this->inc_bc(cpu); });
    cpu.addInstruction(0x09, [this, &cpu] { this->add_hl_bc(cpu); });
    cpu.addInstruction(0x0B, [this, &cpu] { this->dec_bc(cpu); });
    cpu.addInstruction(0x13, [this, &cpu] { this->inc_de(cpu); });
    cpu.addInstruction(0x19, [this, &cpu] { this->add_hl_de(cpu); });
    cpu.addInstruction(0x1B, [this, &cpu] { this->dec_de(cpu); });
    cpu.addInstruction(0x23, [this, &cpu] { this->inc_hl(cpu); });
    cpu.addInstruction(0x29, [this, &cpu] { this->add_hl_hl(cpu); });
    cpu.addInstruction(0x2B, [this, &cpu] { this->dec_hl(cpu); });
    cpu.addInstruction(0x33, [this, &cpu] { this->inc_sp(cpu); });
    cpu.addInstruction(0x39, [this, &cpu] { this->add_hl_sp(cpu); });
    cpu.addInstruction(0x3B, [this, &cpu] { this->dec_sp(cpu); });
    cpu.addInstruction(0xE8, [this, &cpu] { this->add_sp_e8(cpu); });
}

void SixteenBitALUInstructionSet::inc_bc(CPU& cpu) {
    // Placeholder: Call the inc_bc function on the CPU
    // Example: cpu.inc_bc();
}

void SixteenBitALUInstructionSet::add_hl_bc(CPU& cpu) {
    // Placeholder: Call the add_hl_bc function on the CPU
    // Example: cpu.add_hl_bc();
}

void SixteenBitALUInstructionSet::dec_bc(CPU& cpu) {
    // Placeholder: Call the dec_bc function on the CPU
    // Example: cpu.dec_bc();
}

void SixteenBitALUInstructionSet::inc_de(CPU& cpu) {
    // Placeholder: Call the inc_de function on the CPU
    // Example: cpu.inc_de();
}

void SixteenBitALUInstructionSet::add_hl_de(CPU& cpu) {
    // Placeholder: Call the add_hl_de function on the CPU
    // Example: cpu.add_hl_de();
}

void SixteenBitALUInstructionSet::dec_de(CPU& cpu) {
    // Placeholder: Call the dec_de function on the CPU
    // Example: cpu.dec_de();
}

void SixteenBitALUInstructionSet::inc_hl(CPU& cpu) {
    // Placeholder: Call the inc_hl function on the CPU
    // Example: cpu.inc_hl();
}

void SixteenBitALUInstructionSet::add_hl_hl(CPU& cpu) {
    // Placeholder: Call the add_hl_hl function on the CPU
    // Example: cpu.add_hl_hl();
}

void SixteenBitALUInstructionSet::dec_hl(CPU& cpu) {
    // Placeholder: Call the dec_hl function on the CPU
    // Example: cpu.dec_hl();
}

void SixteenBitALUInstructionSet::inc_sp(CPU& cpu) {
    // Placeholder: Call the inc_sp function on the CPU
    // Example: cpu.inc_sp();
}

void SixteenBitALUInstructionSet::add_hl_sp(CPU& cpu) {
    // Placeholder: Call the add_hl_sp function on the CPU
    // Example: cpu.add_hl_sp();
}

void SixteenBitALUInstructionSet::dec_sp(CPU& cpu) {
    // Placeholder: Call the dec_sp function on the CPU
    // Example: cpu.dec_sp();
}

void SixteenBitALUInstructionSet::add_sp_e8(CPU& cpu) {
    // Placeholder: Call the add_sp_e8 function on the CPU
    // Example: cpu.add_sp_e8();
}