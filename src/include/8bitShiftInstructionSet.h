#ifndef EIGHT_BUT_SHIFT_INSTRUCTION_SET_H
#define EIGHT_BIT_SHIFT_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define RLCA 0x07
#define RRCA 0x0F
#define RRA 0x1F
#define RLA 0x17
#define RLC_B 0xCB00
#define RLC_C 0xCB01
#define RLC_D 0xCB02
#define RLC_E 0xCB03
#define RLC_H 0xCB04
#define RLC_L 0xCB05
#define RLC_HL 0xCB06
#define RLC_A 0xCB07
#define RRC_B 0xCB08
#define RRC_C 0xCB09
#define RRC_D 0xCB0A
#define RRC_E 0xCB0B
#define RRC_H 0xCB0C
#define RRC_L 0xCB0D
#define RRC_HL 0xCB0E
#define RRC_A 0xCB0F
#define RL_B 0xCB10
#define RL_C 0xCB11
#define RL_D 0xCB12
#define RL_E 0xCB13
#define RL_H 0xCB14
#define RL_L 0xCB15
#define RL_HL 0xCB16
#define RL_A 0xCB17
#define RR_B 0xCB18
#define RR_C 0xCB19
#define RR_D 0xCB1A
#define RR_E 0xCB1B
#define RR_H 0xCB1C
#define RR_L 0xCB1D
#define RR_HL 0xCB1E
#define RR_A 0xCB1F
#define SLA_B 0xCB20
#define SLA_C 0xCB21
#define SLA_D 0xCB22
#define SLA_E 0xCB23
#define SLA_H 0xCB24
#define SLA_L 0xCB25
#define SLA_HL 0xCB26
#define SLA_A 0xCB27
#define SRA_B 0xCB28
#define SRA_C 0xCB29
#define SRA_D 0xCB2A
#define SRA_E 0xCB2B
#define SRA_H 0xCB2C
#define SRA_L 0xCB2D
#define SRA_HL 0xCB2E
#define SRA_A 0xCB2F
#define SWAP_B 0xCB30
#define SWAP_C 0xCB31
#define SWAP_D 0xCB32
#define SWAP_E 0xCB33
#define SWAP_H 0xCB34
#define SWAP_L 0xCB35
#define SWAP_HL 0xCB36
#define SWAP_A 0xCB37
#define SRL_B 0xCB38
#define SRL_C 0xCB39
#define SRL_D 0xCB3A
#define SRL_E 0xCB3B
#define SRL_H 0xCB3C
#define SRL_L 0xCB3D
#define SRL_HL 0xCB3E
#define SRL_A 0xCB3F
#define BIT_0_B 0xCB40
#define BIT_0_C 0xCB41
#define BIT_0_D 0xCB42
#define BIT_0_E 0xCB43
#define BIT_0_H 0xCB44
#define BIT_0_L 0xCB45
#define BIT_0_HL 0xCB46
#define BIT_0_A 0xCB47
#define BIT_1_B 0xCB48
#define BIT_1_C 0xCB49
#define BIT_1_D 0xCB4A
#define BIT_1_E 0xCB4B
#define BIT_1_H 0xCB4C
#define BIT_1_L 0xCB4D
#define BIT_1_HL 0xCB4E
#define BIT_1_A 0xCB4F
#define BIT_2_B 0xCB50
#define BIT_2_C 0xCB51
#define BIT_2_D 0xCB52
#define BIT_2_E 0xCB53
#define BIT_2_H 0xCB54
#define BIT_2_L 0xCB55
#define BIT_2_HL 0xCB56
#define BIT_2_A 0xCB57
#define BIT_3_B 0xCB58
#define BIT_3_C 0xCB59
#define BIT_3_D 0xCB5A
#define BIT_3_E 0xCB5B
#define BIT_3_H 0xCB5C
#define BIT_3_L 0xCB5D
#define BIT_3_HL 0xCB5E
#define BIT_3_A 0xCB5F
#define BIT_4_B 0xCB60
#define BIT_4_C 0xCB61
#define BIT_4_D 0xCB62
#define BIT_4_E 0xCB63
#define BIT_4_H 0xCB64
#define BIT_4_L 0xCB65
#define BIT_4_HL 0xCB66
#define BIT_4_A 0xCB67
#define BIT_5_B 0xCB68
#define BIT_5_C 0xCB69
#define BIT_5_D 0xCB6A
#define BIT_5_E 0xCB6B
#define BIT_5_H 0xCB6C
#define BIT_5_L 0xCB6D
#define BIT_5_HL 0xCB6E
#define BIT_5_A 0xCB6F
#define BIT_6_B 0xCB70
#define BIT_6_C 0xCB71
#define BIT_6_D 0xCB72
#define BIT_6_E 0xCB73
#define BIT_6_H 0xCB74
#define BIT_6_L 0xCB75
#define BIT_6_HL 0xCB76
#define BIT_6_A 0xCB77
#define BIT_7_B 0xCB78
#define BIT_7_C 0xCB79
#define BIT_7_D 0xCB7A
#define BIT_7_E 0xCB7B
#define BIT_7_H 0xCB7C
#define BIT_7_L 0xCB7D
#define BIT_7_HL 0xCB7E
#define BIT_7_A 0xCB7F
#define RES_0_B 0xCB80
#define RES_0_C 0xCB81
#define RES_0_D 0xCB82
#define RES_0_E 0xCB83
#define RES_0_H 0xCB84
#define RES_0_L 0xCB85
#define RES_0_HL 0xCB86
#define RES_0_A 0xCB87
#define RES_1_B 0xCB88
#define RES_1_C 0xCB89
#define RES_1_D 0xCB8A
#define RES_1_E 0xCB8B
#define RES_1_H 0xCB8C
#define RES_1_L 0xCB8D
#define RES_1_HL 0xCB8E
#define RES_1_A 0xCB8F
#define RES_2_B 0xCB90
#define RES_2_C 0xCB91
#define RES_2_D 0xCB92
#define RES_2_E 0xCB93
#define RES_2_H 0xCB94
#define RES_2_L 0xCB95
#define RES_2_HL 0xCB96
#define RES_2_A 0xCB97
#define RES_3_B 0xCB98
#define RES_3_C 0xCB99
#define RES_3_D 0xCB9A
#define RES_3_E 0xCB9B
#define RES_3_H 0xCB9C
#define RES_3_L 0xCB9D
#define RES_3_HL 0xCB9E
#define RES_3_A 0xCB9F
#define RES_4_B 0xCBA0
#define RES_4_C 0xCBA1
#define RES_4_D 0xCBA2
#define RES_4_E 0xCBA3
#define RES_4_H 0xCBA4
#define RES_4_L 0xCBA5
#define RES_4_HL 0xCBA6
#define RES_4_A 0xCBA7
#define RES_5_B 0xCBA8
#define RES_5_C 0xCBA9
#define RES_5_D 0xCBAA
#define RES_5_E 0xCBAB
#define RES_5_H 0xCBAC
#define RES_5_L 0xCBAD
#define RES_5_HL 0xCBAE
#define RES_5_A 0xCBAF
#define RES_6_B 0xCBB0
#define RES_6_C 0xCBB1
#define RES_6_D 0xCBB2
#define RES_6_E 0xCBB3
#define RES_6_H 0xCBB4
#define RES_6_L 0xCBB5
#define RES_6_HL 0xCBB6
#define RES_6_A 0xCBB7
#define RES_7_B 0xCBB8
#define RES_7_C 0xCBB9
#define RES_7_D 0xCBBA
#define RES_7_E 0xCBBB
#define RES_7_H 0xCBBC
#define RES_7_L 0xCBBD
#define RES_7_HL 0xCBBE
#define RES_7_A 0xCBBF
#define SET_0_B 0xCBC0
#define SET_0_C 0xCBC1
#define SET_0_D 0xCBC2
#define SET_0_E 0xCBC3
#define SET_0_H 0xCBC4
#define SET_0_L 0xCBC5
#define SET_0_HL 0xCBC6
#define SET_0_A 0xCBC7
#define SET_1_B 0xCBC8
#define SET_1_C 0xCBC9
#define SET_1_D 0xCBCA
#define SET_1_E 0xCBCB
#define SET_1_H 0xCBCC
#define SET_1_L 0xCBCD
#define SET_1_HL 0xCBCE
#define SET_1_A 0xCBCF
#define SET_2_B 0xCBD0
#define SET_2_C 0xCBD1
#define SET_2_D 0xCBD2
#define SET_2_E 0xCBD3
#define SET_2_H 0xCBD4
#define SET_2_L 0xCBD5
#define SET_2_HL 0xCBD6
#define SET_2_A 0xCBD7
#define SET_3_B 0xCBD8
#define SET_3_C 0xCBD9
#define SET_3_D 0xCBDA
#define SET_3_E 0xCBDB
#define SET_3_H 0xCBDC
#define SET_3_L 0xCBDD
#define SET_3_HL 0xCBDE
#define SET_3_A 0xCBDF
#define SET_4_B 0xCBE0
#define SET_4_C 0xCBE1
#define SET_4_D 0xCBE2
#define SET_4_E 0xCBE3
#define SET_4_H 0xCBE4
#define SET_4_L 0xCBE5
#define SET_4_HL 0xCBE6
#define SET_4_A 0xCBE7
#define SET_5_B 0xCBE8
#define SET_5_C 0xCBE9
#define SET_5_D 0xCBEA
#define SET_5_E 0xCBEB
#define SET_5_H 0xCBEC
#define SET_5_L 0xCBED
#define SET_5_HL 0xCBEE
#define SET_5_A 0xCBEF
#define SET_6_B 0xCBF0
#define SET_6_C 0xCBF1
#define SET_6_D 0xCBF2
#define SET_6_E 0xCBF3
#define SET_6_H 0xCBF4
#define SET_6_L 0xCBF5
#define SET_6_HL 0xCBF6
#define SET_6_A 0xCBF7
#define SET_7_B 0xCBF8
#define SET_7_C 0xCBF9
#define SET_7_D 0xCBFA
#define SET_7_E 0xCBFB
#define SET_7_H 0xCBFC
#define SET_7_L 0xCBFD
#define SET_7_HL 0xCBFE
#define SET_7_A 0xCBFF

class EightBitShiftInstructionSet : public InstructionSet {
public:
    bool execute(uint8_t opcode, CPU& cpu) override;
    bool execute_prefix(uint16_t opcode, CPU& cpu) override;

private:
    void rlca(CPU& cpu);
    void rlc_a(CPU& cpu);
    void rlc_b(CPU& cpu);
    void rlc_c(CPU& cpu);
    void rlc_d(CPU& cpu);
    void rlc_e(CPU& cpu);
    void rlc_h(CPU& cpu);
    void rlc_l(CPU& cpu);
    void rlc_hl(CPU& cpu);
    void rrc_a(CPU& cpu);
    void rrc_b(CPU& cpu);
    void rrc_c(CPU& cpu);
    void rrc_d(CPU& cpu);
    void rrc_e(CPU& cpu);
    void rrc_h(CPU& cpu);
    void rrc_l(CPU& cpu);
    void rrc_hl(CPU& cpu);
    void rl_a(CPU& cpu);
    void rl_b(CPU& cpu);
    void rl_c(CPU& cpu);
    void rl_d(CPU& cpu);
    void rl_e(CPU& cpu);
    void rl_h(CPU& cpu);
    void rl_l(CPU& cpu);
    void rl_hl(CPU& cpu);
    void rr_a(CPU& cpu);
    void rr_b(CPU& cpu);
    void rr_c(CPU& cpu);
    void rr_d(CPU& cpu);
    void rr_e(CPU& cpu);
    void rr_h(CPU& cpu);
    void rr_l(CPU& cpu);
    void rr_hl(CPU& cpu);
    void sla_a(CPU& cpu);
    void sla_b(CPU& cpu);
    void sla_c(CPU& cpu);
    void sla_d(CPU& cpu);
    void sla_e(CPU& cpu);
    void sla_h(CPU& cpu);
    void sla_l(CPU& cpu);
    void sla_hl(CPU& cpu);
    void sra_a(CPU& cpu);
    void sra_b(CPU& cpu);
    void sra_c(CPU& cpu);
    void sra_d(CPU& cpu);
    void sra_e(CPU& cpu);
    void sra_h(CPU& cpu);
    void sra_l(CPU& cpu);
    void sra_hl(CPU& cpu);
    void swap_a(CPU& cpu);
    void swap_b(CPU& cpu);
    void swap_c(CPU& cpu);
    void swap_d(CPU& cpu);
    void swap_e(CPU& cpu);
    void swap_h(CPU& cpu);
    void swap_l(CPU& cpu);
    void swap_hl(CPU& cpu);
    void srl_a(CPU& cpu);
    void srl_b(CPU& cpu);
    void srl_c(CPU& cpu);
    void srl_d(CPU& cpu);
    void srl_e(CPU& cpu);
    void srl_h(CPU& cpu);
    void srl_l(CPU& cpu);
    void srl_hl(CPU& cpu);
    void bit_n_b(uint8_t bit, CPU& cpu);
    void bit_n_c(uint8_t bit, CPU& cpu);
    void bit_n_d(uint8_t bit, CPU& cpu);
    void bit_n_e(uint8_t bit, CPU& cpu);
    void bit_n_h(uint8_t bit, CPU& cpu);
    void bit_n_l(uint8_t bit, CPU& cpu);
    void bit_n_hl(uint8_t bit, CPU& cpu);
    void bit_n_a(uint8_t bit, CPU& cpu);
    void res_n_b(uint8_t bit, CPU& cpu);
    void res_n_c(uint8_t bit, CPU& cpu);
    void res_n_d(uint8_t bit, CPU& cpu);
    void res_n_e(uint8_t bit, CPU& cpu);
    void res_n_h(uint8_t bit, CPU& cpu);
    void res_n_l(uint8_t bit, CPU& cpu);
    void res_n_hl(uint8_t bit, CPU& cpu);
    void res_n_a(uint8_t bit, CPU& cpu);
    void set_n_b(uint8_t bit, CPU& cpu);
    void set_n_c(uint8_t bit, CPU& cpu);
    void set_n_d(uint8_t bit, CPU& cpu);
    void set_n_e(uint8_t bit, CPU& cpu);
    void set_n_h(uint8_t bit, CPU& cpu);
    void set_n_l(uint8_t bit, CPU& cpu);
    void set_n_hl(uint8_t bit, CPU& cpu);
    void set_n_a(uint8_t bit, CPU& cpu);
};

#endif