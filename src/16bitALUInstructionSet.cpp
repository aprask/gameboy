#include "include/16bitALUInstructionSet.h"

bool SixteenBitALUInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
        return false;
}

bool SixteenBitALUInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case INC_BC:
            inc_bc(cpu);
            return true;
        case ADD_HL_BC:
            add_hl_bc(cpu);
            return true;
        case DEC_BC:
            dec_bc(cpu);
            return true;
        case INC_DE:
            inc_de(cpu);
            return true;
        case ADD_HL_DE:
            add_hl_de(cpu);
            return true;
        case DEC_DE:
            dec_de(cpu);
            return true;
        case INC_HL:
            inc_hl(cpu);
            return true;
        case ADD_HL_HL:
            add_hl_hl(cpu);
            return true;
        case DEC_HL:
            dec_hl(cpu);
            return true;
        case INC_SP:
            inc_sp(cpu);
            return true;
        case ADD_HL_SP:
            add_hl_sp(cpu);
            return true;
        case DEC_SP:
            dec_sp(cpu);
            return true;
        case ADD_SP_e8:
            add_sp_e8(cpu);
            return true;
        default:
            return false; // Opcode not handled by SixteenBitALUInstructionSet
    }
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