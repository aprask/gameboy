#include "include/16bitLoadInstructionSet.h"

bool SixteenBitLoadInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case LD_BC_n16:
            ld_bc_n16(cpu);
            return true;
        case LD_a16_SP:
            ld_a16_sp(cpu);
            return true;
        case LD_DE_n16:
            ld_de_n16(cpu);
            return true;
        case LD_HL_n16:
            ld_hl_n16(cpu);
            return true;
        case LD_SP_n16:
            ld_sp_n16(cpu);
            return true;
        case POP_BC:
            pop_bc(cpu);
            return true;
        case POP_DE:
            pop_de(cpu);
            return true;
        case POP_HL:
            pop_hl(cpu);
            return true;
        case POP_AF:
            pop_af(cpu);
            return true;
        case PUSH_BC:
            push_bc(cpu);
            return true;
        case PUSH_DE:
            push_de(cpu);
            return true;
        case PUSH_HL:
            push_hl(cpu);
            return true;
        case PUSH_AF:
            push_af(cpu);
            return true;
        case LP_HL_SP_e8:
            lp_hl_sp_e8(cpu);
            return true;
        case LP_SP_HL:
            lp_sp_hl(cpu);
            return true;
        default:
            return false;
    }
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