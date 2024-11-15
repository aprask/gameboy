#include "include/16bitLoadInstructionSet.h"

void SixteenBitLoadInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x01, [this, &cpu] { this->ld_bc_n16(cpu); });
    cpu.addInstruction(0x08, [this, &cpu] { this->ld_a16_sp(cpu); });
    cpu.addInstruction(0x11, [this, &cpu] { this->ld_de_n16(cpu); });
    cpu.addInstruction(0x21, [this, &cpu] { this->ld_hl_n16(cpu); });
    cpu.addInstruction(0x31, [this, &cpu] { this->ld_sp_n16(cpu); });
    cpu.addInstruction(0xC1, [this, &cpu] { this->pop_bc(cpu); });
    cpu.addInstruction(0xD1, [this, &cpu] { this->pop_de(cpu); });
    cpu.addInstruction(0xE1, [this, &cpu] { this->pop_hl(cpu); });
    cpu.addInstruction(0xF1, [this, &cpu] { this->pop_af(cpu); });
    cpu.addInstruction(0xC5, [this, &cpu] { this->push_bc(cpu); });
    cpu.addInstruction(0xD5, [this, &cpu] { this->push_de(cpu); });
    cpu.addInstruction(0xE5, [this, &cpu] { this->push_hl(cpu); });
    cpu.addInstruction(0xF5, [this, &cpu] { this->push_af(cpu); });
    cpu.addInstruction(0xF8, [this, &cpu] { this->lp_hl_sp_e8(cpu); });
    cpu.addInstruction(0xF9, [this, &cpu] { this->lp_sp_hl(cpu); });
}

void SixteenBitLoadInstructionSet::ld_bc_n16(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::ld_a16_sp(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::ld_de_n16(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::ld_hl_n16(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::ld_sp_n16(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::pop_bc(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::pop_de(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::pop_hl(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::pop_af(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::push_bc(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::push_de(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::push_hl(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::push_af(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::lp_hl_sp_e8(CPU& cpu) {

}

void SixteenBitLoadInstructionSet::lp_sp_hl(CPU& cpu) {

}