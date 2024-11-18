#include "../include/16bitLoadInstructionSet.h"

void SixteenBitLoadInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x01, [this, &cpu] { this->ld_rr_n16(cpu, BC); });
    cpu.addInstruction(0x08, [this, &cpu] { this->ld_a16_sp(cpu); });
    cpu.addInstruction(0x11, [this, &cpu] { this->ld_rr_n16(cpu, DE); });
    cpu.addInstruction(0x21, [this, &cpu] { this->ld_rr_n16(cpu, HL); });
    cpu.addInstruction(0x31, [this, &cpu] { this->ld_sp_n16(cpu); });
    cpu.addInstruction(0xC1, [this, &cpu] { this->pop_rr(cpu, BC); });
    cpu.addInstruction(0xD1, [this, &cpu] { this->pop_rr(cpu, DE); });
    cpu.addInstruction(0xE1, [this, &cpu] { this->pop_rr(cpu, HL); });
    cpu.addInstruction(0xF1, [this, &cpu] { this->pop_rr(cpu, AF); });
    cpu.addInstruction(0xC5, [this, &cpu] { this->push_rr(cpu, BC); });
    cpu.addInstruction(0xD5, [this, &cpu] { this->push_rr(cpu, DE); });
    cpu.addInstruction(0xE5, [this, &cpu] { this->push_rr(cpu, HL); });
    cpu.addInstruction(0xF5, [this, &cpu] { this->push_rr(cpu, AF); });
    cpu.addInstruction(0xF8, [this, &cpu] { this->lp_hl_sp_e8(cpu); });
    cpu.addInstruction(0xF9, [this, &cpu] { this->lp_sp_hl(cpu); });
}

void SixteenBitLoadInstructionSet::ld_rr_n16(CPU& cpu, int pair) {
    Byte low = cpu.read(cpu.fetchPC());
    Byte high = cpu.read(cpu.fetchPC());

    cpu.setPair(pair, high << 8 | low);
}


void SixteenBitLoadInstructionSet::ld_a16_sp(CPU& cpu) {
    Byte low = cpu.read(cpu.fetchPC());
    Byte high = cpu.read(cpu.fetchPC());

    Word address = high << 8 | low;

    Byte sp_low = cpu.registers.stack_pointer & 0xFF;
    Byte sp_high = cpu.registers.stack_pointer >> 8;

    cpu.write(address, sp_low);
    cpu.write(address + 1, sp_high);
}

void SixteenBitLoadInstructionSet::ld_sp_n16(CPU& cpu) {
    Byte low = cpu.read(cpu.fetchPC());
    Byte high = cpu.read(cpu.fetchPC());

    cpu.registers.stack_pointer = high << 8 | low;
}

void SixteenBitLoadInstructionSet::pop_rr(CPU& cpu, int pair) {
    Byte low = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
    Byte high = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;

    cpu.setPair(pair, high << 8 | low);
}

void SixteenBitLoadInstructionSet::push_rr(CPU& cpu, int pair) {
    Byte low = cpu.getPair(pair) & 0xFF;
    Byte high = cpu.getPair(pair) >> 8;
    
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, high);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, low);
}

void SixteenBitLoadInstructionSet::lp_hl_sp_e8(CPU& cpu) {
    int e8 = (int) cpu.read(cpu.fetchPC());

    Word result = cpu.registers.stack_pointer + e8;
    cpu.setPair(HL, result);

    cpu.setBit(cpu.registers.f, Z, false);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, result & 0x08);
    cpu.setBit(cpu.registers.f, C, result & 0x80);
}

void SixteenBitLoadInstructionSet::lp_sp_hl(CPU& cpu) {
    cpu.registers.stack_pointer = cpu.getPair(HL);
}