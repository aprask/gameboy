#include "../include/JumpInstructionSet.h"

void JumpInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x18, [this, &cpu] { this->jr_e8(cpu); });
    cpu.addInstruction(0x20, [this, &cpu] { this->jr_nz_e8(cpu); });
    cpu.addInstruction(0x28, [this, &cpu] { this->jr_z_e8(cpu); });
    cpu.addInstruction(0x30, [this, &cpu] { this->jr_nc_e8(cpu); });
    cpu.addInstruction(0x38, [this, &cpu] { this->jr_c_e8(cpu); });
    cpu.addInstruction(0xC0, [this, &cpu] { this->ret_nz(cpu); });
    cpu.addInstruction(0xC2, [this, &cpu] { this->jp_nz_a16(cpu); });
    cpu.addInstruction(0xC3, [this, &cpu] { this->jp_a16(cpu); });
    cpu.addInstruction(0xC4, [this, &cpu] { this->call_nz_a16(cpu); });
    cpu.addInstruction(0xC7, [this, &cpu] { this->rst_00H(cpu); });
    cpu.addInstruction(0xC8, [this, &cpu] { this->ret_z(cpu); });
    cpu.addInstruction(0xC9, [this, &cpu] { this->ret(cpu); });
    cpu.addInstruction(0xCA, [this, &cpu] { this->jp_z_a16(cpu); });
    cpu.addInstruction(0xCC, [this, &cpu] { this->call_z_a16(cpu); });
    cpu.addInstruction(0xCD, [this, &cpu] { this->call_a16(cpu); });
    cpu.addInstruction(0xCF, [this, &cpu] { this->rst_08H(cpu); });
    cpu.addInstruction(0xD0, [this, &cpu] { this->ret_nc(cpu); });
    cpu.addInstruction(0xD2, [this, &cpu] { this->jp_nc_a16(cpu); });
    cpu.addInstruction(0xD4, [this, &cpu] { this->call_nc_a16(cpu); });
    cpu.addInstruction(0xD7, [this, &cpu] { this->rst_10H(cpu); });
    cpu.addInstruction(0xD8, [this, &cpu] { this->ret_c(cpu); });
    cpu.addInstruction(0xD9, [this, &cpu] { this->reti(cpu); });
    cpu.addInstruction(0xDA, [this, &cpu] { this->jp_c_a16(cpu); });
    cpu.addInstruction(0xDC, [this, &cpu] { this->call_c_a16(cpu); });
    cpu.addInstruction(0xDF, [this, &cpu] { this->rst_18H(cpu); });
    cpu.addInstruction(0xE7, [this, &cpu] { this->rst_20H(cpu); });
    cpu.addInstruction(0xE9, [this, &cpu] { this->jp_hl(cpu); });
    cpu.addInstruction(0xEF, [this, &cpu] { this->rst_28H(cpu); });
    cpu.addInstruction(0xF7, [this, &cpu] { this->rst_30H(cpu); });
    cpu.addInstruction(0xFF, [this, &cpu] { this->rst_38H(cpu); });
}

void JumpInstructionSet::jr_e8(CPU& cpu) {
    // Placeholder for JR e8 functionality
    // Example: cpu.jr_e8();
}

void JumpInstructionSet::jr_nz_e8(CPU& cpu) {
    // Placeholder for JR NZ e8 functionality
    // Example: cpu.jr_nz_e8();
}

void JumpInstructionSet::jr_z_e8(CPU& cpu) {
    // Placeholder for JR Z e8 functionality
    // Example: cpu.jr_z_e8();
}

void JumpInstructionSet::jr_nc_e8(CPU& cpu) {
    // Placeholder for JR NC e8 functionality
    // Example: cpu.jr_nc_e8();
}

void JumpInstructionSet::jr_c_e8(CPU& cpu) {
    // Placeholder for JR C e8 functionality
    // Example: cpu.jr_c_e8();
}

void JumpInstructionSet::ret_nz(CPU& cpu) {
    // Placeholder for RET NZ functionality
    // Example: cpu.ret_nz();
}

void JumpInstructionSet::jp_nz_a16(CPU& cpu) {
    // Placeholder for JP NZ a16 functionality
    // Example: cpu.jp_nz_a16();
}

void JumpInstructionSet::jp_a16(CPU& cpu) {
    // Placeholder for JP a16 functionality
    // Example: cpu.jp_a16();
}

void JumpInstructionSet::call_nz_a16(CPU& cpu) {
    // Placeholder for CALL NZ a16 functionality
    // Example: cpu.call_nz_a16();
}

void JumpInstructionSet::rst_00H(CPU& cpu) {
    // Placeholder for RST 00 functionality
    // Example: cpu.rst_00();
}

void JumpInstructionSet::ret_z(CPU& cpu) {
    // Placeholder for RET Z functionality
    // Example: cpu.ret_z();
}

void JumpInstructionSet::ret(CPU& cpu) {
    // Placeholder for RET functionality
    // Example: cpu.ret();
}

void JumpInstructionSet::jp_z_a16(CPU& cpu) {
    // Placeholder for JP Z a16 functionality
    // Example: cpu.jp_z_a16();
}

void JumpInstructionSet::call_z_a16(CPU& cpu) {
    // Placeholder for CALL Z a16 functionality
    // Example: cpu.call_z_a16();
}

void JumpInstructionSet::call_a16(CPU& cpu) {
    // Placeholder for CALL a16 functionality
    // Example: cpu.call_a16();
}

void JumpInstructionSet::rst_08H(CPU& cpu) {
    // Placeholder for RST 08 functionality
    // Example: cpu.rst_08();
}

void JumpInstructionSet::ret_nc(CPU& cpu) {
    // Placeholder for RET NC functionality
    // Example: cpu.ret_nc();
}

void JumpInstructionSet::jp_nc_a16(CPU& cpu) {
    // Placeholder for JP NC a16 functionality
    // Example: cpu.jp_nc_a16();
}

void JumpInstructionSet::call_nc_a16(CPU& cpu) {
    // Placeholder for CALL NC a16 functionality
    // Example: cpu.call_nc_a16();
}

void JumpInstructionSet::rst_10H(CPU& cpu) {
    // Placeholder for RST 10 functionality
    // Example: cpu.rst_10();
}

void JumpInstructionSet::ret_c(CPU& cpu) {
    // Placeholder for RET C functionality
    // Example: cpu.ret_c();
}

void JumpInstructionSet::reti(CPU& cpu) {
    // Placeholder for RETI functionality
    // Example: cpu.reti();
}

void JumpInstructionSet::jp_c_a16(CPU& cpu) {
    // Placeholder for JP C a16 functionality
    // Example: cpu.jp_c_a16();
}

void JumpInstructionSet::call_c_a16(CPU& cpu) {
    // Placeholder for CALL C a16 functionality
    // Example: cpu.call_c_a16();
}

void JumpInstructionSet::rst_18H(CPU& cpu) {
    // Placeholder for RST 18 functionality
    // Example: cpu.rst_18();
}

void JumpInstructionSet::rst_20H(CPU& cpu) {
    // Placeholder for RST 20 functionality
    // Example: cpu.rst_20();
}

void JumpInstructionSet::jp_hl(CPU& cpu) {
    // Placeholder for JP HL functionality
    // Example: cpu.jp_hl();
}

void JumpInstructionSet::rst_28H(CPU& cpu) {
    // Placeholder for RST 28 functionality
    // Example: cpu.rst_28();
}

void JumpInstructionSet::rst_30H(CPU& cpu) {
    // Placeholder for RST 30 functionality
    // Example: cpu.rst_30();
}

void JumpInstructionSet::rst_38H(CPU& cpu) {
    // Placeholder for RST 38 functionality
    // Example: cpu.rst_38();
}

