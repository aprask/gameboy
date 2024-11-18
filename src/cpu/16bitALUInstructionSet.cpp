#include "../include/16bitALUInstructionSet.h"

void SixteenBitALUInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x03, [this, &cpu] { this->inc_rr(cpu, BC); });
    cpu.addInstruction(0x09, [this, &cpu] { this->add_hl_rr(cpu, BC); });
    cpu.addInstruction(0x0B, [this, &cpu] { this->dec_rr(cpu, BC); });
    cpu.addInstruction(0x13, [this, &cpu] { this->inc_rr(cpu, DE); });
    cpu.addInstruction(0x19, [this, &cpu] { this->add_hl_rr(cpu, DE); });
    cpu.addInstruction(0x1B, [this, &cpu] { this->dec_rr(cpu, DE); });
    cpu.addInstruction(0x23, [this, &cpu] { this->inc_rr(cpu, HL); });
    cpu.addInstruction(0x29, [this, &cpu] { this->add_hl_rr(cpu, HL); });
    cpu.addInstruction(0x2B, [this, &cpu] { this->dec_rr(cpu, HL); });
    cpu.addInstruction(0x33, [this, &cpu] { this->inc_sp(cpu); });
    cpu.addInstruction(0x39, [this, &cpu] { this->add_hl_sp(cpu); });
    cpu.addInstruction(0x3B, [this, &cpu] { this->dec_sp(cpu); });
    cpu.addInstruction(0xE8, [this, &cpu] { this->add_sp_e8(cpu); });
}

void SixteenBitALUInstructionSet::inc_rr(CPU& cpu, int pair) {
    Word reg = cpu.getPair(pair);
    reg++;
    cpu.setPair(pair, reg);
}

void SixteenBitALUInstructionSet::dec_rr(CPU& cpu, int pair) {
    Word reg = cpu.getPair(pair);
    reg--;
    cpu.setPair(pair, reg);
}

void SixteenBitALUInstructionSet::add_hl_rr(CPU& cpu, int pair) {
    Word hl = cpu.getPair(HL);
    Word reg = cpu.getPair(pair);
    Word result = hl + reg;

    cpu.setPair(HL, result);

    cpu.setBit(cpu.registers.f, Z, false);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, (result & 0x0080) == 1);
    cpu.setBit(cpu.registers.f, C, (result & 0x8000) == 1);
}

void SixteenBitALUInstructionSet::inc_sp(CPU& cpu) {
    cpu.registers.stack_pointer++;
}

void SixteenBitALUInstructionSet::add_hl_sp(CPU& cpu) {
    Word hl = cpu.getPair(HL);
    hl += cpu.registers.stack_pointer;
    cpu.setPair(HL, hl);
}

void SixteenBitALUInstructionSet::dec_sp(CPU& cpu) {
    cpu.registers.stack_pointer--;
}

void SixteenBitALUInstructionSet::add_sp_e8(CPU& cpu) {
    int8_t data = (int8_t) cpu.fetchPC(); // The SIGNED immediate value is stored in the next byte

    Word result = cpu.registers.stack_pointer + data;
    cpu.registers.stack_pointer = result;

    cpu.setBit(cpu.registers.f, Z, false);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, (result & 0x0080) == 1);
    cpu.setBit(cpu.registers.f, C, (result & 0x8000) == 1);
}