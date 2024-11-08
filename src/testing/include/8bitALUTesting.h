#ifndef EIGHT_BIT_ALU_TESTING_H
#define EIGHT_BIT_ALU_TESTING_H

#include "Testing.h"
#include "../../include/8bitALUInstructionSet.h"

class EightBitALUTesting : public Testing {
public:
    void run(CPU& cpu);
    
private:
    bool test_inc_r(CPU& cpu);
    bool test_inc_hl_indirect(CPU& cpu);
    bool test_dec_r(CPU& cpu);
    bool test_dec_hl_indirect(CPU& cpu);
    bool test_daa(CPU& cpu);
    bool test_cpl(CPU& cpu);
    bool test_scf(CPU& cpu);
    bool test_ccf(CPU& cpu);
    bool test_add_r(CPU& cpu);
    bool test_add_hl_indirect(CPU& cpu);
    bool test_adc_r(CPU& cpu);
    bool test_adc_hl_indirect(CPU& cpu);
    bool test_sub_r(CPU& cpu);
    bool test_sub_hl_indirect(CPU& cpu);
    bool test_sbc_r(CPU& cpu);
    bool test_sbc_hl_indirect(CPU& cpu);
    bool test_and_r(CPU& cpu);
    bool test_and_hl_indirect(CPU& cpu);
    bool test_xor_r(CPU& cpu);
    bool test_xor_hl_indirect(CPU& cpu);
    bool test_or_r(CPU& cpu);
    bool test_or_hl_indirect(CPU& cpu);
    bool test_cp_r(CPU& cpu);
    bool test_cp_hl_indirect(CPU& cpu);
    bool test_add_n8(CPU& cpu);
    bool test_adc_n8(CPU& cpu);
    bool test_sub_n8(CPU& cpu);
    bool test_sbc_n8(CPU& cpu);
    bool test_and_n8(CPU& cpu);
    bool test_xor_n8(CPU& cpu);
    bool test_or_n8(CPU& cpu);
    bool test_cp_n8(CPU& cpu);
};

#endif // EIGHT_BIT_ALU_TESTING_H