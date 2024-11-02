#ifndef EIGHT_LOAD_INSTRUCTION_SET_H
#define EIGHT_BIT_LOAD_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define LD_BC_A 0x02
#define LD_B_n8 0x06 
#define LD_A_BC 0x0A
#define LD_C_n8 0x0E
#define LD_DE_A 0x12
#define LD_D_n8 0x16
#define LD_A_DE 0x1A
#define LD_E_n8 0x1E
#define LD_HL_INC_A 0x22 // LD (HL+), A = LD (HLI), A = LDI (HL), A
#define LD_H_n8 0x26
#define LD_A_HL_INC 0x2A // LD A, (HL+) = LD A, (HLI) = LDI A, (HL)
#define LD_L_n8 0x2E
#define LD_HL_DEC_A 0x32 // LD (HL-), A = LD (HLD), A = LDD (HL), A
#define LD_HL_n8 0x36
#define LD_A_HL_DEC 0x3A // LD A, (HL-) = LD A, (HLD) = LDD A, (HL)
#define LD_A_n8 0x3E
#define LD_B_B 0x40
#define LD_B_C 0x41
#define LD_B_D 0x42
#define LD_B_E 0x43
#define LD_B_H 0x44
#define LD_B_L 0x45
#define LD_B_HL 0x46
#define LD_B_A 0x47
#define LD_C_B 0x48
#define LD_C_C 0x49
#define LD_C_D 0x4A
#define LD_C_E 0x4B
#define LD_C_H 0x4C
#define LD_C_L 0x4D
#define LD_C_HL 0x4E
#define LD_C_A 0x4F
#define LD_D_B 0x50
#define LD_D_C 0x51
#define LD_D_D 0x52
#define LD_D_E 0x53
#define LD_D_H 0x54
#define LD_D_L 0x55
#define LD_D_HL 0x56
#define LD_D_A 0x57
#define LD_E_B 0x58
#define LD_E_C 0x59
#define LD_E_D 0x5A
#define LD_E_E 0x5B
#define LD_E_H 0x5C
#define LD_E_L 0x5D
#define LD_E_HL 0x5E
#define LD_E_A 0x5F
#define LD_H_B 0x60
#define LD_H_C 0x61
#define LD_H_D 0x62
#define LD_H_E 0x63
#define LD_H_H 0x64
#define LD_H_L 0x65
#define LD_H_HL 0x66
#define LD_H_A 0x67
#define LD_L_B 0x68
#define LD_L_C 0x69
#define LD_L_D 0x6A
#define LD_L_E 0x6B
#define LD_L_H 0x6C
#define LD_L_L 0x6D
#define LD_L_HL 0x6E
#define LD_L_A 0x6F
#define LD_HL_B 0x70
#define LD_HL_C 0x71
#define LD_HL_D 0x72
#define LD_HL_E 0x73
#define LD_HL_H 0x74
#define LD_HL_L 0x75
#define LD_HL_A 0x77
#define LD_A_B 0x78
#define LD_A_C 0x79
#define LD_A_D 0x7A
#define LD_A_E 0x7B
#define LD_A_H 0x7C
#define LD_A_L 0x7D
#define LD_A_HL 0x7E
#define LD_A_A 0x7F
#define LDH_a8_A 0xE0 // LDH (a8), A = LD (FF00 + a8), A
#define LD__C_A 0xE2 // LD (C), A = LD (FF00 + C), A
#define LD_a16_A 0xEA
#define LDH_A_a8 0xF0 // LD A, (a8) = LD A, (FF00 + a8)
#define LD_A__C 0xF2 // LD A, (C) = LD A, (FF00 + C)
#define LD_A_a16 0xFA

class EightBitLoadInstructionSet : public InstructionSet {
public:
    bool execute(uint8_t opcode, CPU& cpu) override;

private:
    void ld_bc_a(CPU& cpu);
    void ld_b_n8(CPU& cpu);
    void ld_a_bc(CPU& cpu);
    void ld_c_n8(CPU& cpu);
    void ld_de_a(CPU& cpu);
    void ld_d_n8(CPU& cpu);
    void ld_a_de(CPU& cpu);
    void ld_e_n8(CPU& cpu);
    void ld_hl_inc_a(CPU& cpu);
    void ld_h_n8(CPU& cpu);
    void ld_a_hl_inc(CPU& cpu);
    void ld_l_n8(CPU& cpu);
    void ld_hl_dec_a(CPU& cpu);
    void ld_hl_n8(CPU& cpu);
    void ld_a_hl_dec(CPU& cpu);
    void ld_a_n8(CPU& cpu);
    void ld_b_b(CPU& cpu);
    void ld_b_c(CPU& cpu);
    void ld_b_d(CPU& cpu);
    void ld_b_e(CPU& cpu);
    void ld_b_h(CPU& cpu);
    void ld_b_l(CPU& cpu);
    void ld_b_hl(CPU& cpu);
    void ld_b_a(CPU& cpu);
    void ld_c_b(CPU& cpu);
    void ld_c_c(CPU& cpu);
    void ld_c_d(CPU& cpu);
    void ld_c_e(CPU& cpu);
    void ld_c_h(CPU& cpu);
    void ld_c_l(CPU& cpu);
    void ld_c_hl(CPU& cpu);
    void ld_c_a(CPU& cpu);
    void ld_d_b(CPU& cpu);
    void ld_d_c(CPU& cpu);
    void ld_d_d(CPU& cpu);
    void ld_d_e(CPU& cpu);
    void ld_d_h(CPU& cpu);
    void ld_d_l(CPU& cpu);
    void ld_d_hl(CPU& cpu);
    void ld_d_a(CPU& cpu);
    void ld_e_b(CPU& cpu);
    void ld_e_c(CPU& cpu);
    void ld_e_d(CPU& cpu);
    void ld_e_e(CPU& cpu);
    void ld_e_h(CPU& cpu);
    void ld_e_l(CPU& cpu);
    void ld_e_hl(CPU& cpu);
    void ld_e_a(CPU& cpu);
    void ld_h_b(CPU& cpu);
    void ld_h_c(CPU& cpu);
    void ld_h_d(CPU& cpu);
    void ld_h_e(CPU& cpu);
    void ld_h_h(CPU& cpu);
    void ld_h_l(CPU& cpu);
    void ld_h_hl(CPU& cpu);
    void ld_h_a(CPU& cpu);
    void ld_l_b(CPU& cpu);
    void ld_l_c(CPU& cpu);
    void ld_l_d(CPU& cpu);
    void ld_l_e(CPU& cpu);
    void ld_l_h(CPU& cpu);
    void ld_l_l(CPU& cpu);
    void ld_l_hl(CPU& cpu);
    void ld_l_a(CPU& cpu);
    void ld_hl_b(CPU& cpu);
    void ld_hl_c(CPU& cpu);
    void ld_hl_d(CPU& cpu);
    void ld_hl_e(CPU& cpu);
    void ld_hl_h(CPU& cpu);
    void ld_hl_l(CPU& cpu);
    void ld_hl_a(CPU& cpu);
    void ld_a_b(CPU& cpu);
    void ld_a_c(CPU& cpu);
    void ld_a_d(CPU& cpu);
    void ld_a_e(CPU& cpu);
    void ld_a_h(CPU& cpu);
    void ld_a_l(CPU& cpu);
    void ld_a_hl(CPU& cpu);
    void ld_a_a(CPU& cpu);
    void ldh_a8_a(CPU& cpu);
    void ld__c_a(CPU& cpu);
    void ld_a16_a(CPU& cpu);
    void ldh_a_a8(CPU& cpu);
    void ld_a__c(CPU& cpu);
    void ld_a_a16(CPU& cpu);
};

#endif // EIGHT_BIT_INSTRUCTION_SET_H