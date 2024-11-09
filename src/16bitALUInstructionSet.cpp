#include "include/16bitALUInstructionSet.h"

bool SixteenBitALUInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
        return false;
}

bool SixteenBitALUInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case INC_BC:
            inc_rr(cpu, cpu.registers.b_register, cpu.registers.c_register);
            return true;
        case ADD_HL_BC:
            add_hl_rr(cpu, cpu.registers.b_register, cpu.registers.c_register);
            return true;
        case DEC_BC:
            dec_rr(cpu, cpu.registers.b_register, cpu.registers.c_register);
            return true;
        case INC_DE:
            inc_rr(cpu, cpu.registers.d_register, cpu.registers.e_register);
            return true;
        case ADD_HL_DE:
            add_hl_rr(cpu, cpu.registers.d_register, cpu.registers.e_register);
            return true;
        case DEC_DE:
            dec_rr(cpu, cpu.registers.d_register, cpu.registers.e_register);
            return true;
        case INC_HL:
            inc_rr(cpu, cpu.registers.h_register, cpu.registers.l_register);
            return true;
        case ADD_HL_HL:
            add_hl_rr(cpu, cpu.registers.h_register, cpu.registers.l_register);
            return true;
        case DEC_HL:
            dec_rr(cpu, cpu.registers.h_register, cpu.registers.l_register);
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

void SixteenBitALUInstructionSet::inc_rr(CPU& cpu, Byte& reg1, Byte& reg2) {
    Word reg = reg1 << 8 | reg2;
    reg++;
    reg2 = reg & 0xFF; // Lower byte
    reg1 = reg >> 8; // Upper byte
}

void SixteenBitALUInstructionSet::dec_rr(CPU& cpu, Byte& reg1, Byte& reg2) {
    Word reg = reg1 << 8 | reg2;
    reg--;
    reg2 = reg & 0xFF;
    reg1 = reg >> 8;
}

void SixteenBitALUInstructionSet::add_hl_rr(CPU& cpu, Byte& reg1, Byte& reg2) {
    Word hl = cpu.registers.h_register << 8 | cpu.registers.l_register;
    Word reg = reg1 << 8 | reg2;
    Word result = hl + reg;

    cpu.registers.l_register = result & 0xFF;
    cpu.registers.h_register = result >> 8;

    cpu.registers.set_flag(FLAG_SUBTRACT, false);

    if (result & 0x8000 == 0) {
        cpu.registers.set_flag(FLAG_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_CARRY, true);
    }

    if (result & 0x0080 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }
}

void SixteenBitALUInstructionSet::inc_sp(CPU& cpu) {
    cpu.registers.stack_pointer++;
}

void SixteenBitALUInstructionSet::add_hl_sp(CPU& cpu) {
    Word hl = cpu.registers.h_register << 8 | cpu.registers.l_register;
    hl += cpu.registers.stack_pointer;
    cpu.registers.l_register = hl & 0xFF;
    cpu.registers.h_register = hl >> 8;
}

void SixteenBitALUInstructionSet::dec_sp(CPU& cpu) {
    cpu.registers.stack_pointer--;
}

void SixteenBitALUInstructionSet::add_sp_e8(CPU& cpu) {
    int8_t data = cpu.bus.read(cpu.registers.program_counter); // The SIGNED immediate value is stored in the next byte
    cpu.registers.program_counter++; // Increment program counter

    Word result = cpu.registers.stack_pointer; + data;
    cpu.registers.stack_pointer = result;

    cpu.registers.set_flag(FLAG_ZERO, false);
    cpu.registers.set_flag(FLAG_SUBTRACT, false);

    if (result & 0x8000 == 0) {
        cpu.registers.set_flag(FLAG_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_CARRY, true);
    }

    if (result & 0x0080 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }
}