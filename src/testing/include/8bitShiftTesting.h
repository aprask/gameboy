#ifndef EIGHT_BIT_SHIFT_TESTING_H
#define EIGHT_BIT_SHIFT_TESTING_H

#include "Testing.h"
#include "../../include/8bitShiftInstructionSet.h"

class EightBitShiftTesting : public Testing {
public:
    void run(CPU& cpu);

private:
    bool test_rlca(CPU& cpu);
    bool test_rrca(CPU& cpu);
    bool test_rra(CPU& cpu);
    bool test_rla(CPU& cpu);
    bool test_rlc_r(CPU& cpu);
    bool test_rlc_hl_indirect(CPU& cpu);
    bool test_rrc_r(CPU& cpu);
    bool test_rrc_hl_indirect(CPU& cpu);
    bool test_rl_r(CPU& cpu);
    bool test_rl_hl_indirect(CPU& cpu);
    bool test_rr_r(CPU& cpu);
    bool test_rr_hl_indirect(CPU& cpu);
    bool test_sla_r(CPU& cpu);
    bool test_sla_hl_indirect(CPU& cpu);
    bool test_sra_r(CPU& cpu);
    bool test_sra_hl_indirect(CPU& cpu);
    bool test_swap_r(CPU& cpu);
    bool test_swap_hl_indirect(CPU& cpu);
    bool test_srl_r(CPU& cpu);
    bool test_srl_hl_indirect(CPU& cpu);
    bool test_bit_n_r(CPU& cpu);
    bool test_bit_n_hl_indirect(CPU& cpu);
    bool test_res_n_r(CPU& cpu);
    bool test_res_n_hl_indirect(CPU& cpu);
    bool test_set_n_r(CPU& cpu);
    bool test_set_n_hl_indirect(CPU& cpu);
};

#endif // EIGHT_BIT_SHIFT_TESTING_H