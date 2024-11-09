#include "include/8bitLoadInstructionSet.h"

EightBitLoadInstructionSet::EightBitLoadInstructionSet() : alu() {

}


bool EightBitLoadInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
        return false;
}

bool EightBitLoadInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    /*
    decoding logic where the opcode is 0b10xxxyyy

    where xxx is the destination and yyy is the source

    src & 0x07

    1011 1010 & 0000 0111 == 010

    dest >> 3 & 0x07

    (1011 1010) >> 3 ==> 0001 0110

    0001 0110 & 0x07 == 110
    */
   switch (opcode) {
        case LD_R_R: {
            uint8_t src = opcode & 0x07;
            uint8_t dest = (opcode >> 3) & 0x07;
            ld_r_r(cpu, src, dest);
            return true;
        }
        case LD_R_N: {
            uint8_t dest = (opcode >> 3) & 0x07;
            ld_r_n(cpu, dest);
            return true;
        }
        case LD_R_HL: {
            uint8_t dest = (opcode >> 3) & 0x07;
            ld_r_hl(cpu, dest);
            return true;
        }
        case LD_HL_R: {
            uint8_t src = opcode & 0x07;
            ld_hl_r(cpu, src);
            return true;
        }
        case LD_HL_N: {
            ld_hl_n(cpu);
            return true;
        }
        case LD_BC_A: {
            ld_bc_a(cpu);
            return true;
        }
        case LD_DE_A: {
            ld_de_a(cpu);
            return true;
        }
        case LD_A_NN: {
            ld_a_nn(cpu);
            return true;
        }
        case LD_NN_A: {
            ld_nn_a(cpu);
            return true;
        }
        case LDH_A_C: {
            ldh_a_c(cpu);
            return true;
        }
        case LDH_C_A: {
            ldh_c_a(cpu);
            return true;
        }
        case LDH_N_A: {
            ldh_n_a(cpu);
            return true;
        }
        case LDH_A_N: {
            ldh_a_n(cpu);
            return true;
        }
        case LD_A_DEC_HL: {
            ld_a_dec_hl(cpu);
            return true;
        }
        case LD_DEC_HL_A: {
            ld_dec_hl_a(cpu);
            return true;
        }
        case LD_A_INC_HL: {
            ld_a_inc_hl(cpu);
            return true;
        }
        default:
            return false; // Opcode not handled by EightBitLoadInstructionSet
    }
    
};


void EightBitLoadInstructionSet::ld_r_r(CPU& cpu, Byte& source, Byte& destination) {
    source = destination;
}

void EightBitLoadInstructionSet::ld_r_n(CPU& cpu, Byte& destination) {
    Byte data = cpu.bus.read(cpu.registers.program_counter);
    destination = data;
}

void EightBitLoadInstructionSet::ld_r_hl(CPU& cpu, Byte& destination) {
    destination = cpu.bus.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
}

void EightBitLoadInstructionSet::ld_hl_r(CPU& cpu, Byte& source) {
    cpu.bus.write(cpu.registers.h_register << 8 | cpu.registers.l_register, source);
}

void EightBitLoadInstructionSet::ld_hl_n(CPU& cpu) {
    Byte data = cpu.bus.read(cpu.registers.program_counter);
    cpu.bus.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitLoadInstructionSet::ld_bc_a(CPU& cpu) {
    cpu.registers.a_register = cpu.bus.read(cpu.registers.a_register << 8 | cpu.registers.b_register);
}

void EightBitLoadInstructionSet::ld_de_a(CPU& cpu) {
    cpu.registers.a_register = cpu.bus.read(cpu.registers.d_register << 8 | cpu.registers.e_register);
}

void EightBitLoadInstructionSet::ld_a_nn(CPU& cpu) {
    Byte nn_lsb = cpu.bus.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Byte nn_msb = cpu.bus.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    uint16_t nn = (nn_msb << 8) | nn_lsb; // creating 16 bit addr
    cpu.registers.a_register = cpu.bus.read(nn);
}

void EightBitLoadInstructionSet::ld_nn_a(CPU& cpu) {
    Byte nn_lsb = cpu.bus.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Byte nn_msb = cpu.bus.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    uint16_t nn = (nn_msb << 8) | nn_lsb; // creating 16 bit addr
    cpu.bus.write(nn, cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ldh_a_c(CPU& cpu) {
    Word address = (0xFF << 8) | cpu.registers.c_register;
    cpu.registers.a_register = cpu.bus.read(address);
}

void EightBitLoadInstructionSet::ldh_c_a(CPU& cpu) {
    Word address = (0xFF << 8) | cpu.registers.c_register;
    cpu.bus.write(address, cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ldh_a_n(CPU& cpu) {
    Byte data = cpu.bus.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Word address = (0xFF << 8) | data;
    cpu.registers.a_register = cpu.bus.read(address);
}

void EightBitLoadInstructionSet::ldh_n_a(CPU& cpu) {
    Byte data = cpu.bus.read(cpu.registers.program_counter);
    cpu.registers.program_counter++;
    Word address = (0xFF << 8) | data;
    cpu.bus.write(address, cpu.registers.a_register);
}

void EightBitLoadInstructionSet::ld_a_dec_hl(CPU& cpu) {
    Word address = cpu.registers.h_register << 8 | cpu.registers.l_register;
    cpu.registers.a_register = cpu.bus.read(address);
    alu.execute(DEC_HL_INDIRECT, cpu);
}

void EightBitLoadInstructionSet::ld_dec_hl_a(CPU& cpu) {
    Word address = cpu.registers.h_register << 8 | cpu.registers.l_register;
    cpu.bus.write(address, cpu.registers.a_register);
    alu.execute(DEC_HL_INDIRECT, cpu);
}

void EightBitLoadInstructionSet::ld_a_inc_hl(CPU& cpu) {
    Word address = cpu.registers.h_register << 8 | cpu.registers.l_register;
    cpu.registers.a_register = cpu.bus.read(address);
    alu.execute(INC_HL_INDIRECT, cpu);
}

void EightBitLoadInstructionSet::ld_inc_hl_a(CPU& cpu) {
    Word address = cpu.registers.h_register << 8 | cpu.registers.l_register;
    cpu.bus.write(address, cpu.registers.a_register);
    alu.execute(INC_HL_INDIRECT, cpu);
}