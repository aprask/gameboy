#include "include/8bitShiftInstructionSet.h"

bool EightBitShiftInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case RLCA:
            rlca(cpu);
            return true;
        case RRCA:
            rrca(cpu);
            return true;
        case RRA:
            rra(cpu);
            return true;
        case RLA:
            rla(cpu);
            return true;
        default:
            return false;
    }
}

// We really need to consider an unordered map or something, this cannot be efficient.
bool EightBitShiftInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
    switch (opcode) {
        case RLC_B:
            rlc_r(cpu, cpu.registers.b_register);
            return true;
        case RL_A:
            rl_r(cpu, cpu.registers.a_register);
            return true;
        case RR_A:
            rr_r(cpu, cpu.registers.a_register);
            return true;
        case RRC_A:
            rrc_r(cpu, cpu.registers.a_register);
            return true;
        case RLC_C:
            rlc_r(cpu, cpu.registers.c_register);
            return true;
        case RLC_D:
            rlc_r(cpu, cpu.registers.d_register);
            return true;
        case RLC_E:
            rlc_r(cpu, cpu.registers.e_register);
            return true;
        case RLC_H:
            rlc_r(cpu, cpu.registers.h_register);
            return true;
        case RLC_L:
            rlc_r(cpu, cpu.registers.l_register);
            return true;
        case RLC_HL:
            rlc_hl_indirect(cpu);
            return true;
        case RLC_A:
            rlc_r(cpu, cpu.registers.a_register);
            return true;
        case RRC_B:
            rrc_r(cpu, cpu.registers.b_register);
            return true;
        case RRC_C:
            rrc_r(cpu, cpu.registers.c_register);
            return true;
        case RRC_D:
            rrc_r(cpu, cpu.registers.d_register);
            return true;
        case RRC_E:
            rrc_r(cpu, cpu.registers.e_register);
            return true;
        case RRC_H:
            rrc_r(cpu, cpu.registers.h_register);
            return true;
        case RRC_L:
            rrc_r(cpu, cpu.registers.l_register);
            return true;
        case RRC_HL:
            rrc_hl_indirect(cpu);
            return true;
        case RL_B:
            rl_r(cpu, cpu.registers.b_register);
            return true;
        case RL_C:
            rl_r(cpu, cpu.registers.c_register);
            return true;
        case RL_D:
            rl_r(cpu, cpu.registers.d_register);
            return true;
        case RL_E:
            rl_r(cpu, cpu.registers.e_register);
            return true;
        case RL_H:
            rl_r(cpu, cpu.registers.h_register);
            return true;
        case RL_L:
            rl_r(cpu, cpu.registers.l_register);
            return true;
        case RL_HL:
            rl_hl_indirect(cpu);
            return true;
        case RR_B:
            rr_r(cpu, cpu.registers.b_register);
            return true;
        case RR_C:
            rr_r(cpu, cpu.registers.c_register);
            return true;
        case RR_D:
            rr_r(cpu, cpu.registers.d_register);
            return true;
        case RR_E:
            rr_r(cpu, cpu.registers.e_register);
            return true;
        case RR_H:
            rr_r(cpu, cpu.registers.h_register);
            return true;
        case RR_L:
            rr_r(cpu, cpu.registers.l_register);
            return true;
        case RR_HL:
            rr_hl_indirect(cpu);
            return true;
        case SLA_A:
            sla_r(cpu, cpu.registers.a_register);
            return true;
        case SLA_B:
            sla_r(cpu, cpu.registers.b_register);
            return true;
        case SLA_C:
            sla_r(cpu, cpu.registers.c_register);
            return true;
        case SLA_D:
            sla_r(cpu, cpu.registers.d_register);
            return true;
        case SLA_E:
            sla_r(cpu, cpu.registers.e_register);
            return true;
        case SLA_H:
            sla_r(cpu, cpu.registers.h_register);
            return true;
        case SLA_L:
            sla_r(cpu, cpu.registers.l_register);
            return true;
        case SLA_HL:
            sla_hl_indirect(cpu);
            return true;
        case SRA_A:
            sra_r(cpu, cpu.registers.a_register);
            return true;
        case SRA_B:
            sra_r(cpu, cpu.registers.b_register);
            return true;
        case SRA_C:
            sra_r(cpu, cpu.registers.c_register);
            return true;
        case SRA_D:
            sra_r(cpu, cpu.registers.d_register);
            return true;
        case SRA_E:
            sra_r(cpu, cpu.registers.e_register);
            return true;
        case SRA_H:
            sra_r(cpu, cpu.registers.h_register);
            return true;
        case SRA_L:
            sra_r(cpu, cpu.registers.l_register);
            return true;
        case SRA_HL:
            sra_hl_indirect(cpu);
            return true;
        case SWAP_A:
            swap_r(cpu, cpu.registers.a_register);
            return true;
        case SWAP_B:
            swap_r(cpu, cpu.registers.b_register);
            return true;
        case SWAP_C:
            swap_r(cpu, cpu.registers.c_register);
            return true;
        case SWAP_D:
            swap_r(cpu, cpu.registers.d_register);
            return true;
        case SWAP_E:
            swap_r(cpu, cpu.registers.e_register);
            return true;
        case SWAP_H:
            swap_r(cpu, cpu.registers.h_register);
            return true;
        case SWAP_L:
            swap_r(cpu, cpu.registers.l_register);
            return true;
        case SWAP_HL:
            swap_hl_indirect(cpu);
            return true;
        case SRL_A:
            srl_r(cpu, cpu.registers.a_register);
            return true;
        case SRL_B:
            srl_r(cpu, cpu.registers.b_register);
            return true;
        case SRL_C:
            srl_r(cpu, cpu.registers.c_register);
            return true;
        case SRL_D:
            srl_r(cpu, cpu.registers.d_register);
            return true;
        case SRL_E:
            srl_r(cpu, cpu.registers.e_register);
            return true;
        case SRL_H:
            srl_r(cpu, cpu.registers.h_register);
            return true;
        case SRL_L:
            srl_r(cpu, cpu.registers.l_register);
            return true;
        case SRL_HL:
            srl_hl_indirect(cpu);
            return true;
        case BIT_0_B:
            bit_n_r(0, cpu, cpu.registers.b_register);
            return true;
        case BIT_0_C:
            bit_n_r(0, cpu, cpu.registers.c_register);
            return true;
        case BIT_0_D:
            bit_n_r(0, cpu, cpu.registers.d_register);
            return true;
        case BIT_0_E:
            bit_n_r(0, cpu, cpu.registers.e_register);
            return true;
        case BIT_0_H:
            bit_n_r(0, cpu, cpu.registers.h_register);
            return true;
        case BIT_0_L:
            bit_n_r(0, cpu, cpu.registers.l_register);
            return true;
        case BIT_0_HL:
            bit_n_hl_indirect(0, cpu);
            return true;
        case BIT_0_A:
            bit_n_r(0, cpu, cpu.registers.a_register);
            return true;
        case BIT_1_B:
            bit_n_r(1, cpu, cpu.registers.b_register);
            return true;
        case BIT_1_C:
            bit_n_r(1, cpu, cpu.registers.c_register);
            return true;
        case BIT_1_D:
            bit_n_r(1, cpu, cpu.registers.d_register);
            return true;
        case BIT_1_E:
            bit_n_r(1, cpu, cpu.registers.e_register);
            return true;
        case BIT_1_H:
            bit_n_r(1, cpu, cpu.registers.h_register);
            return true;
        case BIT_1_L:
            bit_n_r(1, cpu, cpu.registers.l_register);
            return true;
        case BIT_1_HL:
            bit_n_hl_indirect(1, cpu);
            return true;
        case BIT_1_A:
            bit_n_r(1, cpu, cpu.registers.a_register);
            return true;
        case BIT_2_B:
            bit_n_r(2, cpu, cpu.registers.b_register);
            return true;
        case BIT_2_C:
            bit_n_r(2, cpu, cpu.registers.c_register);
            return true;
        case BIT_2_D:
            bit_n_r(2, cpu, cpu.registers.d_register);
            return true;
        case BIT_2_E:
            bit_n_r(2, cpu, cpu.registers.e_register);
            return true;
        case BIT_2_H:
            bit_n_r(2, cpu, cpu.registers.h_register);
            return true;
        case BIT_2_L:
            bit_n_r(2, cpu, cpu.registers.l_register);
            return true;
        case BIT_2_HL:
            bit_n_hl_indirect(2, cpu);
            return true;
        case BIT_2_A:
            bit_n_r(2, cpu, cpu.registers.a_register);
            return true;
        case BIT_3_B:
            bit_n_r(3, cpu, cpu.registers.b_register);
            return true;
        case BIT_3_C:
            bit_n_r(3, cpu, cpu.registers.c_register);
            return true;
        case BIT_3_D:
            bit_n_r(3, cpu, cpu.registers.d_register);
            return true;
        case BIT_3_E:
            bit_n_r(3, cpu, cpu.registers.e_register);
            return true;
        case BIT_3_H:
            bit_n_r(3, cpu, cpu.registers.h_register);
            return true;
        case BIT_3_L:
            bit_n_r(3, cpu, cpu.registers.l_register);
            return true;
        case BIT_3_HL:
            bit_n_hl_indirect(3, cpu);
            return true;
        case BIT_3_A:
            bit_n_r(3, cpu, cpu.registers.a_register);
            return true;
        case BIT_4_B:
            bit_n_r(4, cpu, cpu.registers.b_register);
            return true;
        case BIT_4_C:
            bit_n_r(4, cpu, cpu.registers.c_register);
            return true;
        case BIT_4_D:
            bit_n_r(4, cpu, cpu.registers.d_register);
            return true;
        case BIT_4_E:
            bit_n_r(4, cpu, cpu.registers.e_register);
            return true;
        case BIT_4_H:
            bit_n_r(4, cpu, cpu.registers.h_register);
            return true;
        case BIT_4_L:
            bit_n_r(4, cpu, cpu.registers.l_register);
            return true;
        case BIT_4_HL:
            bit_n_hl_indirect(4, cpu);
            return true;
        case BIT_4_A:
            bit_n_r(4, cpu, cpu.registers.a_register);
            return true;
        case BIT_5_B:
            bit_n_r(5, cpu, cpu.registers.b_register);
            return true;
        case BIT_5_C:
            bit_n_r(5, cpu, cpu.registers.c_register);
            return true;
        case BIT_5_D:
            bit_n_r(5, cpu, cpu.registers.d_register);
            return true;
        case BIT_5_E:
            bit_n_r(5, cpu, cpu.registers.e_register);
            return true;
        case BIT_5_H:
            bit_n_r(5, cpu, cpu.registers.h_register);
            return true;
        case BIT_5_L:
            bit_n_r(5, cpu, cpu.registers.l_register);
            return true;
        case BIT_5_HL:
            bit_n_hl_indirect(5, cpu);
            return true;
        case BIT_5_A:
            bit_n_r(5, cpu, cpu.registers.a_register);
            return true;
        case BIT_6_B:
            bit_n_r(6, cpu, cpu.registers.b_register);
            return true;
        case BIT_6_C:
            bit_n_r(6, cpu, cpu.registers.c_register);
            return true;
        case BIT_6_D:
            bit_n_r(6, cpu, cpu.registers.d_register);
            return true;
        case BIT_6_E:
            bit_n_r(6, cpu, cpu.registers.e_register);
            return true;
        case BIT_6_H:
            bit_n_r(6, cpu, cpu.registers.h_register);
            return true;
        case BIT_6_L:
            bit_n_r(6, cpu, cpu.registers.l_register);
            return true;
        case BIT_6_HL:
            bit_n_hl_indirect(6, cpu);
            return true;
        case BIT_6_A:
            bit_n_r(6, cpu, cpu.registers.a_register);
            return true;
        case BIT_7_B:
            bit_n_r(7, cpu, cpu.registers.b_register);
            return true;
        case BIT_7_C:
            bit_n_r(7, cpu, cpu.registers.c_register);
            return true;
        case BIT_7_D:
            bit_n_r(7, cpu, cpu.registers.d_register);
            return true;
        case BIT_7_E:
            bit_n_r(7, cpu, cpu.registers.e_register);
            return true;
        case BIT_7_H:
            bit_n_r(7, cpu, cpu.registers.h_register);
            return true;
        case BIT_7_L:
            bit_n_r(7, cpu, cpu.registers.l_register);
            return true;
        case BIT_7_HL:
            bit_n_hl_indirect(7, cpu);
            return true;
        case BIT_7_A:
            bit_n_r(7, cpu, cpu.registers.a_register);
            return true;
        case RES_0_B:
            res_n_r(0, cpu, cpu.registers.b_register);
            return true;
        case RES_0_C:
            res_n_r(0, cpu, cpu.registers.c_register);
            return true;
        case RES_0_D:
            res_n_r(0, cpu, cpu.registers.d_register);
            return true;
        case RES_0_E:
            res_n_r(0, cpu, cpu.registers.e_register);
            return true;
        case RES_0_H:
            res_n_r(0, cpu, cpu.registers.h_register);
            return true;
        case RES_0_L:
            res_n_r(0, cpu, cpu.registers.l_register);
            return true;
        case RES_0_HL:
            res_n_hl_indirect(0, cpu);
            return true;
        case RES_0_A:
            res_n_r(0, cpu, cpu.registers.a_register);
            return true;
        case RES_1_B:
            res_n_r(1, cpu, cpu.registers.b_register);
            return true;
        case RES_1_C:
            res_n_r(1, cpu, cpu.registers.c_register);
            return true;
        case RES_1_D:
            res_n_r(1, cpu, cpu.registers.d_register);
            return true;
        case RES_1_E:
            res_n_r(1, cpu, cpu.registers.e_register);
            return true;
        case RES_1_H:
            res_n_r(1, cpu, cpu.registers.h_register);
            return true;
        case RES_1_L:
            res_n_r(1, cpu, cpu.registers.l_register);
            return true;
        case RES_1_HL:
            res_n_hl_indirect(1, cpu);
            return true;
        case RES_1_A:
            res_n_r(1, cpu, cpu.registers.a_register);
            return true;
        case RES_2_B:
            res_n_r(2, cpu, cpu.registers.b_register);
            return true;
        case RES_2_C:
            res_n_r(2, cpu, cpu.registers.c_register);
            return true;
        case RES_2_D:
            res_n_r(2, cpu, cpu.registers.d_register);
            return true;
        case RES_2_E:
            res_n_r(2, cpu, cpu.registers.e_register);
            return true;
        case RES_2_H:
            res_n_r(2, cpu, cpu.registers.h_register);
            return true;
        case RES_2_L:
            res_n_r(2, cpu, cpu.registers.l_register);
            return true;
        case RES_2_HL:
            res_n_hl_indirect(2, cpu);
            return true;
        case RES_2_A:
            res_n_r(2, cpu, cpu.registers.a_register);
            return true;
        case RES_3_B:
            res_n_r(3, cpu, cpu.registers.b_register);
            return true;
        case RES_3_C:
            res_n_r(3, cpu, cpu.registers.c_register);
            return true;
        case RES_3_D:
            res_n_r(3, cpu, cpu.registers.d_register);
            return true;
        case RES_3_E:
            res_n_r(3, cpu, cpu.registers.e_register);
            return true;
        case RES_3_H:
            res_n_r(3, cpu, cpu.registers.h_register);
            return true;
        case RES_3_L:
            res_n_r(3, cpu, cpu.registers.l_register);
            return true;
        case RES_3_HL:
            res_n_hl_indirect(3, cpu);
            return true;
        case RES_3_A:
            res_n_r(3, cpu, cpu.registers.a_register);
            return true;
        case RES_4_B:
            res_n_r(4, cpu, cpu.registers.b_register);
            return true;
        case RES_4_C:
            res_n_r(4, cpu, cpu.registers.c_register);
            return true;
        case RES_4_D:
            res_n_r(4, cpu, cpu.registers.d_register);
            return true;
        case RES_4_E:
            res_n_r(4, cpu, cpu.registers.e_register);
            return true;
        case RES_4_H:
            res_n_r(4, cpu, cpu.registers.h_register);
            return true;
        case RES_4_L:
            res_n_r(4, cpu, cpu.registers.l_register);
            return true;
        case RES_4_HL:
            res_n_hl_indirect(4, cpu);
            return true;
        case RES_4_A:
            res_n_r(4, cpu, cpu.registers.a_register);
            return true;
        case RES_5_B:
            res_n_r(5, cpu, cpu.registers.b_register);
            return true;
        case RES_5_C:
            res_n_r(5, cpu, cpu.registers.c_register);
            return true;
        case RES_5_D:
            res_n_r(5, cpu, cpu.registers.d_register);
            return true;
        case RES_5_E:
            res_n_r(5, cpu, cpu.registers.e_register);
            return true;
        case RES_5_H:
            res_n_r(5, cpu, cpu.registers.h_register);
            return true;
        case RES_5_L:
            res_n_r(5, cpu, cpu.registers.l_register);
            return true;
        case RES_5_HL:
            res_n_hl_indirect(5, cpu);
            return true;
        case RES_5_A:
            res_n_r(5, cpu, cpu.registers.a_register);
            return true;
        case RES_6_B:
            res_n_r(6, cpu, cpu.registers.b_register);
            return true;
        case RES_6_C:
            res_n_r(6, cpu, cpu.registers.c_register);
            return true;
        case RES_6_D:
            res_n_r(6, cpu, cpu.registers.d_register);
            return true;
        case RES_6_E:
            res_n_r(6, cpu, cpu.registers.e_register);
            return true;
        case RES_6_H:
            res_n_r(6, cpu, cpu.registers.h_register);
            return true;
        case RES_6_L:
            res_n_r(6, cpu, cpu.registers.l_register);
            return true;
        case RES_6_HL:
            res_n_hl_indirect(6, cpu);
            return true;
        case RES_6_A:
            res_n_r(6, cpu, cpu.registers.a_register);
            return true;
        case RES_7_B:
            res_n_r(7, cpu, cpu.registers.b_register);
            return true;
        case RES_7_C:
            res_n_r(7, cpu, cpu.registers.c_register);
            return true;
        case RES_7_D:
            res_n_r(7, cpu, cpu.registers.d_register);
            return true;
        case RES_7_E:
            res_n_r(7, cpu, cpu.registers.e_register);
            return true;
        case RES_7_H:
            res_n_r(7, cpu, cpu.registers.h_register);
            return true;
        case RES_7_L:
            res_n_r(7, cpu, cpu.registers.l_register);
            return true;
        case RES_7_HL:
            res_n_hl_indirect(7, cpu);
            return true;
        case RES_7_A:
            res_n_r(7, cpu, cpu.registers.a_register);
            return true;
        case SET_0_B:
            set_n_r(0, cpu, cpu.registers.b_register);
            return true;
        case SET_0_C:
            set_n_r(0, cpu, cpu.registers.c_register);
            return true;
        case SET_0_D:
            set_n_r(0, cpu, cpu.registers.d_register);
            return true;
        case SET_0_E:
            set_n_r(0, cpu, cpu.registers.e_register);
            return true;
        case SET_0_H:
            set_n_r(0, cpu, cpu.registers.h_register);
            return true;
        case SET_0_L:
            set_n_r(0, cpu, cpu.registers.l_register);
            return true;
        case SET_0_HL:
            set_n_hl_indirect(0, cpu);
            return true;
        case SET_0_A:
            set_n_r(0, cpu, cpu.registers.a_register);
            return true;
        case SET_1_B:
            set_n_r(1, cpu, cpu.registers.b_register);
            return true;
        case SET_1_C:
            set_n_r(1, cpu, cpu.registers.c_register);
            return true;
        case SET_1_D:
            set_n_r(1, cpu, cpu.registers.d_register);
            return true;
        case SET_1_E:
            set_n_r(1, cpu, cpu.registers.e_register);
            return true;
        case SET_1_H:
            set_n_r(1, cpu, cpu.registers.h_register);
            return true;
        case SET_1_L:
            set_n_r(1, cpu, cpu.registers.l_register);
            return true;
        case SET_1_HL:
            set_n_hl_indirect(1, cpu);
            return true;
        case SET_1_A:
            set_n_r(1, cpu, cpu.registers.a_register);
            return true;
        case SET_2_B:
            set_n_r(2, cpu, cpu.registers.b_register);
            return true;
        case SET_2_C:
            set_n_r(2, cpu, cpu.registers.c_register);
            return true;
        case SET_2_D:
            set_n_r(2, cpu, cpu.registers.d_register);
            return true;
        case SET_2_E:
            set_n_r(2, cpu, cpu.registers.e_register);
            return true;
        case SET_2_H:
            set_n_r(2, cpu, cpu.registers.h_register);
            return true;
        case SET_2_L:
            set_n_r(2, cpu, cpu.registers.l_register);
            return true;
        case SET_2_HL:
            set_n_hl_indirect(2, cpu);
            return true;
        case SET_2_A:
            set_n_r(2, cpu, cpu.registers.a_register);
            return true;
        case SET_3_B:
            set_n_r(3, cpu, cpu.registers.b_register);
            return true;
        case SET_3_C:
            set_n_r(3, cpu, cpu.registers.c_register);
            return true;
        case SET_3_D:
            set_n_r(3, cpu, cpu.registers.d_register);
            return true;
        case SET_3_E:
            set_n_r(3, cpu, cpu.registers.e_register);
            return true;
        case SET_3_H:
            set_n_r(3, cpu, cpu.registers.h_register);
            return true;
        case SET_3_L:
            set_n_r(3, cpu, cpu.registers.l_register);
            return true;
        case SET_3_HL:
            set_n_hl_indirect(3, cpu);
            return true;
        case SET_3_A:
            set_n_r(3, cpu, cpu.registers.a_register);
            return true;
        case SET_4_B:
            set_n_r(4, cpu, cpu.registers.b_register);
            return true;
        case SET_4_C:
            set_n_r(4, cpu, cpu.registers.c_register);
            return true;
        case SET_4_D:
            set_n_r(4, cpu, cpu.registers.d_register);
            return true;
        case SET_4_E:
            set_n_r(4, cpu, cpu.registers.e_register);
            return true;
        case SET_4_H:
            set_n_r(4, cpu, cpu.registers.h_register);
            return true;
        case SET_4_L:
            set_n_r(4, cpu, cpu.registers.l_register);
            return true;
        case SET_4_HL:
            set_n_hl_indirect(4, cpu);
            return true;
        case SET_4_A:
            set_n_r(4, cpu, cpu.registers.a_register);
            return true;
        case SET_5_B:
            set_n_r(5, cpu, cpu.registers.b_register);
            return true;
        case SET_5_C:
            set_n_r(5, cpu, cpu.registers.c_register);
            return true;
        case SET_5_D:
            set_n_r(5, cpu, cpu.registers.d_register);
            return true;
        case SET_5_E:
            set_n_r(5, cpu, cpu.registers.e_register);
            return true;
        case SET_5_H:
            set_n_r(5, cpu, cpu.registers.h_register);
            return true;
        case SET_5_L:
            set_n_r(5, cpu, cpu.registers.l_register);
            return true;
        case SET_5_HL:
            set_n_hl_indirect(5, cpu);
            return true;
        case SET_5_A:
            set_n_r(5, cpu, cpu.registers.a_register);
            return true;
        case SET_6_B:
            set_n_r(6, cpu, cpu.registers.b_register);
            return true;
        case SET_6_C:
            set_n_r(6, cpu, cpu.registers.c_register);
            return true;
        case SET_6_D:
            set_n_r(6, cpu, cpu.registers.d_register);
            return true;
        case SET_6_E:
            set_n_r(6, cpu, cpu.registers.e_register);
            return true;
        case SET_6_H:
            set_n_r(6, cpu, cpu.registers.h_register);
            return true;
        case SET_6_L:
            set_n_r(6, cpu, cpu.registers.l_register);
            return true;
        case SET_6_HL:
            set_n_hl_indirect(6, cpu);
            return true;
        case SET_6_A:
            set_n_r(6, cpu, cpu.registers.a_register);
            return true;
        case SET_7_B:
            set_n_r(7, cpu, cpu.registers.b_register);
            return true;
        case SET_7_C:
            set_n_r(7, cpu, cpu.registers.c_register);
            return true;
        case SET_7_D:
            set_n_r(7, cpu, cpu.registers.d_register);
            return true;
        case SET_7_E:
            set_n_r(7, cpu, cpu.registers.e_register);
            return true;
        case SET_7_H:
            set_n_r(7, cpu, cpu.registers.h_register);
            return true;
        case SET_7_L:
            set_n_r(7, cpu, cpu.registers.l_register);
            return true;
        case SET_7_HL:
            set_n_hl_indirect(7, cpu);
            return true;
        case SET_7_A:
            set_n_r(7, cpu, cpu.registers.a_register);
            return true;
        default:
            return false;
    }
}

void EightBitShiftInstructionSet::rrca(CPU& cpu) {
    bool least_significant_bit = cpu.registers.a_register & 1;
    cpu.registers.a_register = cpu.registers.a_register >> 1;
    cpu.registers.a_register = cpu.registers.a_register | (least_significant_bit << 7);

    if (cpu.registers.a_register == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, least_significant_bit);
}

void EightBitShiftInstructionSet::rlca(CPU& cpu) {
    bool most_significant_bit = cpu.registers.a_register >> 7;
    cpu.registers.a_register = cpu.registers.a_register << 1;
    cpu.registers.a_register = cpu.registers.a_register | most_significant_bit;

    if (cpu.registers.a_register == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, most_significant_bit);
}

void EightBitShiftInstructionSet::rra(CPU& cpu) {
    bool carry = cpu.registers.flag_register & FLAG_CARRY;
    bool least_significant_bit = cpu.registers.a_register & 1;
    cpu.registers.a_register = cpu.registers.a_register >> 1;
    cpu.registers.a_register = cpu.registers.a_register | (carry << 7);

    if (cpu.registers.a_register == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, least_significant_bit);
}

void EightBitShiftInstructionSet::rla(CPU& cpu) {
    bool carry = cpu.registers.flag_register & FLAG_CARRY;
    bool most_significant_bit = cpu.registers.a_register >> 7;
    cpu.registers.a_register = cpu.registers.a_register << 1;
    cpu.registers.a_register = cpu.registers.a_register | carry;

    if (cpu.registers.a_register == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, most_significant_bit);
}

void EightBitShiftInstructionSet::rlc_r(CPU& cpu, Byte& reg) {
    bool most_significant_bit = reg >> 7;
    reg = reg << 1;
    reg = reg | most_significant_bit;
    
    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, most_significant_bit);
}

void EightBitShiftInstructionSet::rlc_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    rlc_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::rrc_r(CPU& cpu, Byte& reg) {
    bool least_significant_bit = reg & 1;
    reg = reg >> 1;
    reg = reg | (least_significant_bit << 7);

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, least_significant_bit);
}

void EightBitShiftInstructionSet::rrc_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    rrc_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::rl_r(CPU& cpu, Byte& reg) {
    bool carry = cpu.registers.flag_register & FLAG_CARRY;
    bool most_significant_bit = reg >> 7;
    reg = reg << 1;
    reg = reg | carry;

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, most_significant_bit);
}

void EightBitShiftInstructionSet::rl_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    rl_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::rr_r(CPU& cpu, Byte& reg) {
    bool carry = cpu.registers.flag_register & FLAG_CARRY;
    bool least_significant_bit = reg & 1;
    reg = reg >> 1;
    reg = reg | (carry << 7);

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, least_significant_bit);
}

void EightBitShiftInstructionSet::rr_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    rr_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::sla_r(CPU& cpu, Byte& reg) {
    bool most_significant_bit = reg >> 7;
    reg = reg << 1;

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, most_significant_bit);
}

void EightBitShiftInstructionSet::sla_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    sla_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::sra_r(CPU& cpu, Byte& reg) {
    bool least_significant_bit = reg & 1;
    bool most_significant_bit = reg >> 7;
    reg = reg >> 1;
    reg = reg | (most_significant_bit << 7);

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, least_significant_bit);
}

void EightBitShiftInstructionSet::sra_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    sra_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::swap_r(CPU& cpu, Byte& reg) {
    reg = (reg >> 4) | (reg << 4);

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, false);
}

void EightBitShiftInstructionSet::swap_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    swap_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::srl_r(CPU& cpu, Byte& reg) {
    bool least_significant_bit = reg & 1;
    reg = reg >> 1;

    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    cpu.registers.set_flag(FLAG_CARRY, least_significant_bit);
}

void EightBitShiftInstructionSet::srl_hl_indirect(CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    srl_r(cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::bit_n_r(uint8_t n, CPU& cpu, Byte& reg) {
    if (reg & (1 << n)) { // Complement of specified bit
        cpu.registers.set_flag(FLAG_ZERO, false);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, true);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);
    cpu.registers.set_flag(FLAG_HALF_CARRY, true);
}

void EightBitShiftInstructionSet::bit_n_hl_indirect(uint8_t n, CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    bit_n_r(n, cpu, data);
}

void EightBitShiftInstructionSet::set_n_r(uint8_t n, CPU& cpu, Byte& reg) {
    reg = reg | (1 << n);
}

void EightBitShiftInstructionSet::set_n_hl_indirect(uint8_t n, CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    set_n_r(n, cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}

void EightBitShiftInstructionSet::res_n_r(uint8_t n, CPU& cpu, Byte& reg) {
    reg = reg & ~(1 << n);
}

void EightBitShiftInstructionSet::res_n_hl_indirect(uint8_t n, CPU& cpu) {
    Byte data = cpu.read(cpu.registers.h_register << 8 | cpu.registers.l_register);
    res_n_r(n, cpu, data);
    cpu.write(cpu.registers.h_register << 8 | cpu.registers.l_register, data);
}