#include "include/8bitLoadInstructionSet.h"

void EightBitLoadInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x02, [this, &cpu] { ld_rr_a(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x06, [this, &cpu] { ld_r_n8(cpu, cpu.registers.b_register); });
    cpu.addInstruction(0x0A, [this, &cpu] { ld_a_rr(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x0E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.c_register); });
    cpu.addInstruction(0x12, [this, &cpu] { ld_rr_a(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x16, [this, &cpu] { ld_r_n8(cpu, cpu.registers.d_register); });
    cpu.addInstruction(0x1A, [this, &cpu] { ld_a_rr(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x1E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.e_register); });
    cpu.addInstruction(0x22, [this, &cpu] { ld_inc_hl_a(cpu); });
    cpu.addInstruction(0x26, [this, &cpu] { ld_r_n8(cpu, cpu.registers.h_register); });
    cpu.addInstruction(0x2A, [this, &cpu] { ld_a_inc_hl(cpu); });
    cpu.addInstruction(0x2E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.l_register); });
    cpu.addInstruction(0x32, [this, &cpu] { ld_dec_hl_a(cpu); });
    cpu.addInstruction(0x36, [this, &cpu] { ld_hl_n(cpu); });
    cpu.addInstruction(0x3A, [this, &cpu] { ld_a_dec_hl(cpu); });
    cpu.addInstruction(0x3E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.a_register); });
    cpu.addInstruction(0x40, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.b_register); });
    cpu.addInstruction(0x41, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.b_register); });
    cpu.addInstruction(0x42, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.b_register); });
    cpu.addInstruction(0x43, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.b_register); });
    cpu.addInstruction(0x44, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.b_register); });
    cpu.addInstruction(0x45, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.b_register); });
    cpu.addInstruction(0x46, [this, &cpu] { ld_r_hl(cpu, cpu.registers.b_register); });
    cpu.addInstruction(0x47, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.b_register); });
    cpu.addInstruction(0x48, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x49, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.c_register); });
    cpu.addInstruction(0x4A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.c_register); });
    cpu.addInstruction(0x4B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.c_register); });
    cpu.addInstruction(0x4C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.c_register); });
    cpu.addInstruction(0x4D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.c_register); });
    cpu.addInstruction(0x4E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.c_register); });
    cpu.addInstruction(0x4F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.c_register); });
    cpu.addInstruction(0x50, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.d_register); });
    cpu.addInstruction(0x51, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.d_register); });
    cpu.addInstruction(0x52, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.d_register); });
    cpu.addInstruction(0x53, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.d_register); });
    cpu.addInstruction(0x54, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.d_register); });
    cpu.addInstruction(0x55, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.d_register); });
    cpu.addInstruction(0x56, [this, &cpu] { ld_r_hl(cpu, cpu.registers.d_register); });
    cpu.addInstruction(0x57, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.d_register); });
    cpu.addInstruction(0x58, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.e_register); });
    cpu.addInstruction(0x59, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.e_register); });
    cpu.addInstruction(0x5A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x5B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.e_register); });
    cpu.addInstruction(0x5C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.e_register); });
    cpu.addInstruction(0x5D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.e_register); });
    cpu.addInstruction(0x5E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.e_register); });
    cpu.addInstruction(0x5F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.e_register); });
    cpu.addInstruction(0x60, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.h_register); });
    cpu.addInstruction(0x61, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.h_register); });
    cpu.addInstruction(0x62, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.h_register); });
    cpu.addInstruction(0x63, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.h_register); });
    cpu.addInstruction(0x64, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.h_register); });
    cpu.addInstruction(0x65, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.h_register); });
    cpu.addInstruction(0x66, [this, &cpu] { ld_r_hl(cpu, cpu.registers.h_register); });
    cpu.addInstruction(0x67, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.h_register); });
    cpu.addInstruction(0x68, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.l_register); });
    cpu.addInstruction(0x69, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.l_register); });
    cpu.addInstruction(0x6A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.l_register); });
    cpu.addInstruction(0x6B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.l_register); });
    cpu.addInstruction(0x6C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0x6D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.l_register); });
    cpu.addInstruction(0x6E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.l_register); });
    cpu.addInstruction(0x6F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.l_register); });
    cpu.addInstruction(0x70, [this, &cpu] { ld_hl_r(cpu, cpu.registers.b_register); });
    cpu.addInstruction(0x71, [this, &cpu] { ld_hl_r(cpu, cpu.registers.c_register); });
    cpu.addInstruction(0x72, [this, &cpu] { ld_hl_r(cpu, cpu.registers.d_register); });
    cpu.addInstruction(0x73, [this, &cpu] { ld_hl_r(cpu, cpu.registers.e_register); });
    cpu.addInstruction(0x74, [this, &cpu] { ld_hl_r(cpu, cpu.registers.h_register); });
    cpu.addInstruction(0x75, [this, &cpu] { ld_hl_r(cpu, cpu.registers.l_register); });
    cpu.addInstruction(0x77, [this, &cpu] { ld_hl_r(cpu, cpu.registers.a_register); });
    cpu.addInstruction(0x78, [this, &cpu] { ld_r_r(cpu, cpu.registers.b_register, cpu.registers.a_register); });
    cpu.addInstruction(0x79, [this, &cpu] { ld_r_r(cpu, cpu.registers.c_register, cpu.registers.a_register); });
    cpu.addInstruction(0x7A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d_register, cpu.registers.a_register); });
    cpu.addInstruction(0x7B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e_register, cpu.registers.a_register); });
    cpu.addInstruction(0x7C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h_register, cpu.registers.a_register); });
    cpu.addInstruction(0x7D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l_register, cpu.registers.a_register); });
    cpu.addInstruction(0x7E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.a_register); });
    cpu.addInstruction(0x7F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a_register, cpu.registers.a_register); });
    cpu.addInstruction(0xE0, [this, &cpu] { ldh_n_a(cpu); });
    cpu.addInstruction(0xE2, [this, &cpu] { ldh_c_a(cpu); });
    cpu.addInstruction(0xEA, [this, &cpu] { ld_nn_a(cpu); });
    cpu.addInstruction(0xF0, [this, &cpu] { ldh_a_n(cpu); });
    cpu.addInstruction(0xF2, [this, &cpu] { ldh_a_c(cpu); });
    cpu.addInstruction(0xFA, [this, &cpu] { ld_a_nn(cpu); });
}

void EightBitLoadInstructionSet::ld_r_r(CPU& cpu, Byte& source, Byte& destination) {
    destination = source;
}

void EightBitLoadInstructionSet::ld_r_n8(CPU& cpu, Byte& destination) {
    destination = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
}

void EightBitLoadInstructionSet::ld_r_hl(CPU& cpu, Byte& destination) {
    destination = cpu.read(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register));
}

void EightBitLoadInstructionSet::ld_hl_r(CPU& cpu, Byte& source) {
    cpu.write(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register), source);
}

void EightBitLoadInstructionSet::ld_hl_n(CPU& cpu) {
    cpu.write(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register), cpu.registers.program_counter);
    cpu.registers.program_counter++;
}

void EightBitLoadInstructionSet::ld_a_rr(CPU& cpu, Byte& high, Byte& low) {
    cpu.registers.a_register = cpu.read(cpu.registers.get_pair(high, low));
}

void EightBitLoadInstructionSet::ld_rr_a(CPU& cpu, Byte& high, Byte& low) {
    cpu.write(cpu.registers.get_pair(high, low), cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ld_a_nn(CPU& cpu) {
    Byte low = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Byte high = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;

    cpu.registers.a_register = cpu.read(high << 8 | low);
}

void EightBitLoadInstructionSet::ld_nn_a(CPU& cpu) {
    Byte low = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Byte high = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;

    cpu.write(high << 8 | low, cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ldh_a_c(CPU& cpu) {
    cpu.registers.a_register = cpu.read(0xFF00 | cpu.registers.c_register);
}

void EightBitLoadInstructionSet::ldh_c_a(CPU& cpu) {
    cpu.write(0xFF00 | cpu.registers.c_register, cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ldh_a_n(CPU& cpu) {
    Byte offset = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    cpu.registers.a_register = cpu.read(0xFF00 | offset);
}

void EightBitLoadInstructionSet::ldh_n_a(CPU& cpu) {
    Byte offset = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    cpu.write(0xFF00 | offset, cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ld_a_dec_hl(CPU& cpu) {
    cpu.registers.a_register = cpu.read(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register));
    cpu.execute(0x35); // DEC (HL)
}

void EightBitLoadInstructionSet::ld_dec_hl_a(CPU& cpu) {
    cpu.write(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register), cpu.registers.a_register);
    cpu.execute(0x35); // DEC (HL)
}

void EightBitLoadInstructionSet::ld_a_inc_hl(CPU& cpu) {
    cpu.registers.a_register = cpu.read(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register));
    cpu.execute(0x34); // INC (HL)
}

void EightBitLoadInstructionSet::ld_inc_hl_a(CPU& cpu) {
    cpu.write(cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register), cpu.registers.a_register);
    cpu.execute(0x34); // INC (HL)
}