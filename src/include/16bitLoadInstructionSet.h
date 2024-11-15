#include "InstructionSet.h"
#include "cpu.h"
#ifndef SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H
#define SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H

class SixteenBitLoadInstructionSet : public InstructionSet {
    public:
        void initializeInstructionTable(CPU& cpu) override;
        
    private:
        void ld_bc_n16(CPU& cpu);
        void ld_a16_sp(CPU& cpu);
        void ld_de_n16(CPU& cpu);
        void ld_hl_n16(CPU& cpu);
        void ld_sp_n16(CPU& cpu);
        void pop_bc(CPU& cpu);
        void pop_de(CPU& cpu);
        void pop_hl(CPU& cpu);
        void pop_af(CPU& cpu);
        void push_bc(CPU& cpu);
        void push_de(CPU& cpu);
        void push_hl(CPU& cpu);
        void push_af(CPU& cpu);
        void lp_hl_sp_e8(CPU& cpu);
        void lp_sp_hl(CPU& cpu);
};
#endif // SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H