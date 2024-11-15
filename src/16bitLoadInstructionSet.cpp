#include "include/16bitLoadInstructionSet.h"

void SixteenBitLoadInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x01, [this, &cpu] { this->ld_rr_n16(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0x08, [this, &cpu] { this->ld_a16_sp(cpu); });
    cpu.addInstruction(0x11, [this, &cpu] { this->ld_rr_n16(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0x21, [this, &cpu] { this->ld_rr_n16(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0x31, [this, &cpu] { this->ld_sp_n16(cpu); });
    cpu.addInstruction(0xC1, [this, &cpu] { this->pop_rr(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0xD1, [this, &cpu] { this->pop_rr(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0xE1, [this, &cpu] { this->pop_rr(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0xF1, [this, &cpu] { this->pop_rr(cpu, cpu.registers.a_register, cpu.registers.flag_register); });
    cpu.addInstruction(0xC5, [this, &cpu] { this->push_rr(cpu, cpu.registers.b_register, cpu.registers.c_register); });
    cpu.addInstruction(0xD5, [this, &cpu] { this->push_rr(cpu, cpu.registers.d_register, cpu.registers.e_register); });
    cpu.addInstruction(0xE5, [this, &cpu] { this->push_rr(cpu, cpu.registers.h_register, cpu.registers.l_register); });
    cpu.addInstruction(0xF5, [this, &cpu] { this->push_rr(cpu, cpu.registers.a_register, cpu.registers.flag_register); });
    cpu.addInstruction(0xF8, [this, &cpu] { this->lp_hl_sp_e8(cpu); });
    cpu.addInstruction(0xF9, [this, &cpu] { this->lp_sp_hl(cpu); });
}

void SixteenBitLoadInstructionSet::ld_rr_n16(CPU& cpu, Byte& high, Byte& low) {
    low = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    high = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
}


void SixteenBitLoadInstructionSet::ld_a16_sp(CPU& cpu) {
    Byte low = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Byte high = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;

    Word address = high << 8 | low;

    Byte sp_low = cpu.registers.stack_pointer & 0xFF;
    Byte sp_high = cpu.registers.stack_pointer >> 8;

    cpu.write(address, sp_low);
    cpu.write(address + 1, sp_high);
}

void SixteenBitLoadInstructionSet::ld_sp_n16(CPU& cpu) {
    Byte low = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Byte high = cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;

    cpu.registers.stack_pointer = high << 8 | low;
}

void SixteenBitLoadInstructionSet::pop_rr(CPU& cpu, Byte& high, Byte& low) {
    low = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
    high = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
}

void SixteenBitLoadInstructionSet::push_rr(CPU& cpu, Byte& high, Byte& low) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, high);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, low);
}

void SixteenBitLoadInstructionSet::lp_hl_sp_e8(CPU& cpu) {
    int e8 = (int) cpu.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;

    Word result = cpu.registers.stack_pointer + e8;
    cpu.registers.set_pair(result, cpu.registers.h_register, cpu.registers.l_register);

    cpu.registers.set_bit(cpu.registers.flag_register, Z, false);
    cpu.registers.set_bit(cpu.registers.flag_register, N, false);
    cpu.registers.set_bit(cpu.registers.flag_register, H, result & 0x08);
    cpu.registers.set_bit(cpu.registers.flag_register, C, result & 0x80);
}

void SixteenBitLoadInstructionSet::lp_sp_hl(CPU& cpu) {
    cpu.registers.stack_pointer = cpu.registers.get_pair(cpu.registers.h_register, cpu.registers.l_register);
}