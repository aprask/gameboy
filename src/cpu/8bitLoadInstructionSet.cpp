#include "../include/8bitLoadInstructionSet.h"

void EightBitLoadInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x02, [this, &cpu] { ld_rr_a(cpu, BC); });
    cpu.addInstruction(0x06, [this, &cpu] { ld_r_n8(cpu, cpu.registers.b); });
    cpu.addInstruction(0x0A, [this, &cpu] { ld_a_rr(cpu, BC); });
    cpu.addInstruction(0x0E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.c); });
    cpu.addInstruction(0x12, [this, &cpu] { ld_rr_a(cpu, DE); });
    cpu.addInstruction(0x16, [this, &cpu] { ld_r_n8(cpu, cpu.registers.d); });
    cpu.addInstruction(0x1A, [this, &cpu] { ld_a_rr(cpu, DE); });
    cpu.addInstruction(0x1E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.e); });
    cpu.addInstruction(0x22, [this, &cpu] { ld_inc_hl_a(cpu); });
    cpu.addInstruction(0x26, [this, &cpu] { ld_r_n8(cpu, cpu.registers.h); });
    cpu.addInstruction(0x2A, [this, &cpu] { ld_a_inc_hl(cpu); });
    cpu.addInstruction(0x2E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.l); });
    cpu.addInstruction(0x32, [this, &cpu] { ld_dec_hl_a(cpu); });
    cpu.addInstruction(0x36, [this, &cpu] { ld_hl_n(cpu); });
    cpu.addInstruction(0x3A, [this, &cpu] { ld_a_dec_hl(cpu); });
    cpu.addInstruction(0x3E, [this, &cpu] { ld_r_n8(cpu, cpu.registers.a); });
    cpu.addInstruction(0x40, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.b); });
    cpu.addInstruction(0x41, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.b); });
    cpu.addInstruction(0x42, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.b); });
    cpu.addInstruction(0x43, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.b); });
    cpu.addInstruction(0x44, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.b); });
    cpu.addInstruction(0x45, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.b); });
    cpu.addInstruction(0x46, [this, &cpu] { ld_r_hl(cpu, cpu.registers.b); });
    cpu.addInstruction(0x47, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.b); });
    cpu.addInstruction(0x48, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.c); });
    cpu.addInstruction(0x49, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.c); });
    cpu.addInstruction(0x4A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.c); });
    cpu.addInstruction(0x4B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.c); });
    cpu.addInstruction(0x4C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.c); });
    cpu.addInstruction(0x4D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.c); });
    cpu.addInstruction(0x4E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.c); });
    cpu.addInstruction(0x4F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.c); });
    cpu.addInstruction(0x50, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.d); });
    cpu.addInstruction(0x51, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.d); });
    cpu.addInstruction(0x52, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.d); });
    cpu.addInstruction(0x53, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.d); });
    cpu.addInstruction(0x54, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.d); });
    cpu.addInstruction(0x55, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.d); });
    cpu.addInstruction(0x56, [this, &cpu] { ld_r_hl(cpu, cpu.registers.d); });
    cpu.addInstruction(0x57, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.d); });
    cpu.addInstruction(0x58, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.e); });
    cpu.addInstruction(0x59, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.e); });
    cpu.addInstruction(0x5A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.e); });
    cpu.addInstruction(0x5B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.e); });
    cpu.addInstruction(0x5C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.e); });
    cpu.addInstruction(0x5D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.e); });
    cpu.addInstruction(0x5E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.e); });
    cpu.addInstruction(0x5F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.e); });
    cpu.addInstruction(0x60, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.h); });
    cpu.addInstruction(0x61, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.h); });
    cpu.addInstruction(0x62, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.h); });
    cpu.addInstruction(0x63, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.h); });
    cpu.addInstruction(0x64, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.h); });
    cpu.addInstruction(0x65, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.h); });
    cpu.addInstruction(0x66, [this, &cpu] { ld_r_hl(cpu, cpu.registers.h); });
    cpu.addInstruction(0x67, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.h); });
    cpu.addInstruction(0x68, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.l); });
    cpu.addInstruction(0x69, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.l); });
    cpu.addInstruction(0x6A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.l); });
    cpu.addInstruction(0x6B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.l); });
    cpu.addInstruction(0x6C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.l); });
    cpu.addInstruction(0x6D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.l); });
    cpu.addInstruction(0x6E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.l); });
    cpu.addInstruction(0x6F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.l); });
    cpu.addInstruction(0x70, [this, &cpu] { ld_hl_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x71, [this, &cpu] { ld_hl_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x72, [this, &cpu] { ld_hl_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x73, [this, &cpu] { ld_hl_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x74, [this, &cpu] { ld_hl_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x75, [this, &cpu] { ld_hl_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x77, [this, &cpu] { ld_hl_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0x78, [this, &cpu] { ld_r_r(cpu, cpu.registers.b, cpu.registers.a); });
    cpu.addInstruction(0x79, [this, &cpu] { ld_r_r(cpu, cpu.registers.c, cpu.registers.a); });
    cpu.addInstruction(0x7A, [this, &cpu] { ld_r_r(cpu, cpu.registers.d, cpu.registers.a); });
    cpu.addInstruction(0x7B, [this, &cpu] { ld_r_r(cpu, cpu.registers.e, cpu.registers.a); });
    cpu.addInstruction(0x7C, [this, &cpu] { ld_r_r(cpu, cpu.registers.h, cpu.registers.a); });
    cpu.addInstruction(0x7D, [this, &cpu] { ld_r_r(cpu, cpu.registers.l, cpu.registers.a); });
    cpu.addInstruction(0x7E, [this, &cpu] { ld_r_hl(cpu, cpu.registers.a); });
    cpu.addInstruction(0x7F, [this, &cpu] { ld_r_r(cpu, cpu.registers.a, cpu.registers.a); });
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
    destination = cpu.fetchPC();
}

void EightBitLoadInstructionSet::ld_r_hl(CPU& cpu, Byte& destination) {
    destination = cpu.readPair(HL);
}

void EightBitLoadInstructionSet::ld_hl_r(CPU& cpu, Byte& source) {
    cpu.writePair(HL, source);
}

void EightBitLoadInstructionSet::ld_hl_n(CPU& cpu) {
    cpu.writePair(HL, cpu.fetchPC());
}

void EightBitLoadInstructionSet::ld_a_rr(CPU& cpu, int pair) {
    cpu.registers.a = cpu.readPair(pair);
}

void EightBitLoadInstructionSet::ld_rr_a(CPU& cpu, int pair) {
    cpu.writePair(pair, cpu.registers.a);
}

void EightBitLoadInstructionSet::ld_a_nn(CPU& cpu) {
    Byte low = cpu.fetchPC();
    Byte high = cpu.fetchPC();

    cpu.registers.a = cpu.read(high << 8 | low);
}

void EightBitLoadInstructionSet::ld_nn_a(CPU& cpu) {
    Byte low = cpu.fetchPC();
    Byte high = cpu.fetchPC();

    cpu.write(high << 8 | low, cpu.registers.a);
}

void EightBitLoadInstructionSet::ldh_a_c(CPU& cpu) {
    cpu.registers.a = cpu.read(0xFF00 | cpu.registers.c);
}

void EightBitLoadInstructionSet::ldh_c_a(CPU& cpu) {
    cpu.write(0xFF00 | cpu.registers.c, cpu.registers.a);
}

void EightBitLoadInstructionSet::ldh_a_n(CPU& cpu) {
    Byte offset = cpu.fetchPC();
    cpu.registers.a = cpu.read(0xFF00 | offset);
}

void EightBitLoadInstructionSet::ldh_n_a(CPU& cpu) {
    Byte offset = cpu.fetchPC();
    cpu.write(0xFF00 | offset, cpu.registers.a);
}

void EightBitLoadInstructionSet::ld_a_dec_hl(CPU& cpu) {
    cpu.registers.a = cpu.readPair(HL);
    cpu.execute(0x35); // DEC (HL)
}

void EightBitLoadInstructionSet::ld_dec_hl_a(CPU& cpu) {
    cpu.writePair(HL, cpu.registers.a);
    cpu.execute(0x35); // DEC (HL)
}

void EightBitLoadInstructionSet::ld_a_inc_hl(CPU& cpu) {
    cpu.registers.a = cpu.readPair(HL);
    cpu.execute(0x34); // INC (HL)
}

void EightBitLoadInstructionSet::ld_inc_hl_a(CPU& cpu) {
   cpu.writePair(HL, cpu.registers.a);
    cpu.execute(0x34); // INC (HL)
}