#include "InstructionSet.h"
#include "cpu.h"
#ifndef SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H
#define SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H

class SixteenBitLoadInstructionSet : public InstructionSet {
    public:
        void initializeInstructionTable(CPU& cpu) override;
        
    private:
        void ld_rr_n16(CPU& cpu, Byte& high, Byte& low);
        void ld_a16_sp(CPU& cpu);
        void ld_sp_n16(CPU& cpu);
        void pop_rr(CPU& cpu, Byte& high, Byte& low);
        void push_rr(CPU& cpu, Byte& high, Byte& low);
        void lp_hl_sp_e8(CPU& cpu);
        void lp_sp_hl(CPU& cpu);
};
#endif // SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H