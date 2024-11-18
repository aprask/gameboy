#ifndef EIGHT_LOAD_INSTRUCTION_SET_H
#define EIGHT_BIT_LOAD_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

class EightBitLoadInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;

private:
    void ld_rr_a(CPU& cpu, int pair);
    void ld_a_rr(CPU& cpu, int pair);
    void ld_r_r(CPU& cpu, Byte& source, Byte& destination);
    void ld_r_n8(CPU& cpu, Byte& destination);
    void ld_r_hl(CPU& cpu, Byte& destination);
    void ld_hl_r(CPU& cpu, Byte& source);
    void ld_hl_n(CPU& cpu);
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