#ifndef SIXTEEN_BIT_ALU_TESTING_H
#define SIXTEEN_BIT_ALU_TESTING_H

#include "Testing.h"
#include "../../include/16bitALUInstructionSet.h"

class SixteenBitALUTesting : public Testing {
public:
    void run(CPU& cpu);

private:
    bool test_inc_rr(CPU& cpu);
    bool test_dec_rr(CPU& cpu);
    bool test_add_hl_rr(CPU& cpu);
    bool test_inc_sp(CPU& cpu);
    bool test_add_hl_sp(CPU& cpu);
    bool test_dec_sp(CPU& cpu);
    bool test_add_sp_e8(CPU& cpu);
};

#endif // SIXTEEN_BIT_ALU_TESTING_H