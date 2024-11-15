#include "include/16bitALUInstructionSet.h"

void SixteenBitALUInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x03, [this, &cpu] { this->inc_rr(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x09, [this, &cpu] { this->add_hl_rr(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x0B, [this, &cpu] { this->dec_rr(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x13, [this, &cpu] { this->inc_rr(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x19, [this, &cpu] { this->add_hl_rr(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x1B, [this, &cpu] { this->dec_rr(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x23, [this, &cpu] { this->inc_rr(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0x29, [this, &cpu] { this->add_hl_rr(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0x2B, [this, &cpu] { this->dec_rr(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0x33, [this, &cpu] { this->inc_sp(cpu); });
    cpu.addInstruction(0x39, [this, &cpu] { this->add_hl_sp(cpu); });
    cpu.addInstruction(0x3B, [this, &cpu] { this->dec_sp(cpu); });
    cpu.addInstruction(0xE8, [this, &cpu] { this->add_sp_e8(cpu); });
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
    int8_t data = (int8_t) cpu.bus.read(cpu.registers.program_counter); // The SIGNED immediate value is stored in the next byte
    cpu.registers.program_counter++; // Increment program counter

    Word result = cpu.registers.stack_pointer + data;
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