#ifndef EIGHT_LOAD_INSTRUCTION_SET_H
#define EIGHT_BIT_LOAD_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define LD_R_R 0x41
#define LD_R_N 0x06
#define LD_R_HL 0x46
#define LD_HL_R 0x70
#define LD_HL_N 0x36
#define LD_A_BC 0x0A
#define LD_A_DE 0x1A
#define LD_BC_A 0x02
#define LD_DE_A 0x12
#define LD_A_NN 0xFA
#define LD_NN_A 0xEA
#define LDH_A_C 0xF2
#define LDH_C_A 0xE2
#define LDH_A_N 0xF0
#define LDH_N_A 0xE0
#define LD_A_DEC_HL 0x3A
#define LD_DEC_HL_A 0x32
#define LD_A_INC_HL 0x2A
#define LD_INC_HL_A 0x22


class EightBitLoadInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;

private:
    void ld_rr_a(CPU& cpu, Byte& source, Byte& destination);
    void ld_r_r(CPU& cpu, Byte& source, Byte& destination);
    void ld_r_n8(CPU& cpu, Byte& destination);
    void ld_r_hl(CPU& cpu, Byte& destination);
    void ld_hl_r(CPU& cpu, Byte& source);
    void ld_hl_n(CPU& cpu);
    void ld_bc_a(CPU& cpu);
    void ld_de_a(CPU& cpu);
    void ld_a_nn(CPU& cpu);
    void ld_nn_a(CPU& cpu);
    void ldh_a_c(CPU& cpu);
    void ldh_c_a(CPU& cpu);
    void ldh_a_n(CPU& cpu);
    void ldh_n_a(CPU& cpu);
    void ld_a_dec_hl(CPU& cpu);
    void ld_dec_hl_a(CPU& cpu);
    void ld_a_inc_hl(CPU& cpu);
    void ld_inc_hl_a(CPU& cpu);
};

#endif // EIGHT_BIT_INSTRUCTION_SET_H