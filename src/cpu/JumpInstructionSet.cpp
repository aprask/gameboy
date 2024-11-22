#include "../include/JumpInstructionSet.h"
#include <iostream>

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
    int8_t offset = cpu.fetchPC();
    cpu.registers.program_counter += offset;
}

void JumpInstructionSet::jr_nz_e8(CPU& cpu) {
    int8_t offset = cpu.fetchPC();
    if (!(cpu.registers.f & (1 << Z))) {
        cpu.registers.program_counter += offset;
    }
}

void JumpInstructionSet::jr_z_e8(CPU& cpu) {
    int8_t offset = cpu.fetchPC();
    if ((cpu.registers.f & (1 << Z))) {
        cpu.registers.program_counter += offset;
    }
}

void JumpInstructionSet::jr_nc_e8(CPU& cpu) {
    int8_t offset = cpu.fetchPC();
    if (!(cpu.registers.f & (1 << C))) {
        cpu.registers.program_counter += offset;
    }
}

void JumpInstructionSet::jr_c_e8(CPU& cpu) {
    int8_t offset = cpu.fetchPC();
    if ((cpu.registers.f & (1 << C))) {
        cpu.registers.program_counter += offset;
    }
}

void JumpInstructionSet::ret_nz(CPU& cpu) {
    if (!(cpu.registers.f & (1 << Z))) {
        uint8_t lsb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        uint8_t msb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        cpu.registers.program_counter = (msb << 8) | lsb;
    }
}

void JumpInstructionSet::jp_nz_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if (!(cpu.registers.f & (1 << Z))) {
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::jp_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    cpu.registers.program_counter = nn;
}

void JumpInstructionSet::call_nz_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if (!(cpu.registers.f & (1 << Z))) {
        uint16_t return_address = cpu.registers.program_counter;
        // allocating space for return address (writing to memory)
        cpu.registers.stack_pointer--;
        std::cout << "SP: " << cpu.registers.stack_pointer << std::endl;
        cpu.write(cpu.registers.stack_pointer, (return_address >> 8) & 0xFF);
        cpu.registers.stack_pointer--;
        std::cout << "SP: " << cpu.registers.stack_pointer << std::endl;
        cpu.write(cpu.registers.stack_pointer, return_address & 0xFF);
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::rst_00H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x00;
}

void JumpInstructionSet::ret_z(CPU& cpu) {
    if ((cpu.registers.f & (1 << Z))) {
        uint8_t lsb = cpu.read(cpu.registers.stack_pointer);
        std::cout << "SP: " << cpu.registers.stack_pointer << std::endl;
        cpu.registers.stack_pointer++;
        std::cout << "SP: " << cpu.registers.stack_pointer << std::endl;
        uint8_t msb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        std::cout << "SP: " << cpu.registers.stack_pointer << std::endl;
        cpu.registers.program_counter = (msb << 8) | lsb;
    }
}

void JumpInstructionSet::ret(CPU& cpu) {
    uint8_t lsb = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
    uint8_t msb = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
    cpu.registers.program_counter = (msb << 8) | lsb;
}

void JumpInstructionSet::jp_z_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if ((cpu.registers.f & (1 << Z))) {
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::call_z_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if ((cpu.registers.f & (1 << Z))) {
        uint16_t return_address = cpu.registers.program_counter;
        // allocating space for return address (writing to memory)
        cpu.registers.stack_pointer--;
        cpu.write(cpu.registers.stack_pointer, (return_address >> 8) & 0xFF);
        cpu.registers.stack_pointer--;
        cpu.write(cpu.registers.stack_pointer, return_address & 0xFF);
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::call_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    uint16_t return_address = cpu.registers.program_counter;
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (return_address >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, return_address & 0xFF);
    cpu.registers.program_counter = nn;
}

void JumpInstructionSet::rst_08H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x08;
}

void JumpInstructionSet::ret_nc(CPU& cpu) {
    if (!(cpu.registers.f & (1 << C))) {
        uint8_t lsb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        uint8_t msb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        cpu.registers.program_counter = (msb << 8) | lsb;
    }
}

void JumpInstructionSet::jp_nc_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if (!(cpu.registers.f & (1 << C))) {
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::call_nc_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if (!(cpu.registers.f & (1 << C))) {
        uint16_t return_address = cpu.registers.program_counter;
        // allocating space for return address (writing to memory)
        cpu.registers.stack_pointer--;
        cpu.write(cpu.registers.stack_pointer, (return_address >> 8) & 0xFF);
        cpu.registers.stack_pointer--;
        cpu.write(cpu.registers.stack_pointer, return_address & 0xFF);
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::rst_10H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x10;
}

void JumpInstructionSet::ret_c(CPU& cpu) {
    if ((cpu.registers.f & (1 << C))) {
        uint8_t lsb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        uint8_t msb = cpu.read(cpu.registers.stack_pointer);
        cpu.registers.stack_pointer++;
        cpu.registers.program_counter = (msb << 8) | lsb;
    }
}

void JumpInstructionSet::reti(CPU& cpu) {
    uint8_t lsb = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
    uint8_t msb = cpu.read(cpu.registers.stack_pointer);
    cpu.registers.stack_pointer++;
    cpu.registers.program_counter = (msb << 8) | lsb;
    cpu.IME_FLAG = true;
}

void JumpInstructionSet::jp_c_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if ((cpu.registers.f & (1 << C))) {
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::call_c_a16(CPU& cpu) {
    uint8_t nn_lsb = cpu.fetchPC();
    uint8_t nn_msb = cpu.fetchPC();
    uint16_t nn = (nn_msb << 8) | nn_lsb;
    if ((cpu.registers.f & (1 << C))) {
        uint16_t return_address = cpu.registers.program_counter;
        // allocating space for return address (writing to memory)
        cpu.registers.stack_pointer--;
        cpu.write(cpu.registers.stack_pointer, (return_address >> 8) & 0xFF);
        cpu.registers.stack_pointer--;
        cpu.write(cpu.registers.stack_pointer, return_address & 0xFF);
        cpu.registers.program_counter = nn;
    }
}

void JumpInstructionSet::rst_18H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x18;
}

void JumpInstructionSet::rst_20H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x20;
}

void JumpInstructionSet::jp_hl(CPU& cpu) {
    cpu.registers.program_counter = (cpu.registers.h << 8) | cpu.registers.l;
}

void JumpInstructionSet::rst_28H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x28;
}

void JumpInstructionSet::rst_30H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x30;
}

void JumpInstructionSet::rst_38H(CPU& cpu) {
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter >> 8) & 0xFF);
    cpu.registers.stack_pointer--;
    cpu.write(cpu.registers.stack_pointer, (cpu.registers.program_counter) & 0xFF);
    cpu.registers.program_counter = 0x38;
}

