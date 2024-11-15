#ifndef SIXTEEN_BIT_ALU_INSTRUCTION_SET_H
#define SIXTEEN_BIT_ALU_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

class SixteenBitALUInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;

private:
    void inc_bc(CPU& cpu);
    void add_hl_bc(CPU& cpu);
    void dec_bc(CPU& cpu);
    void inc_de(CPU& cpu);
    void add_hl_de(CPU& cpu);
    void dec_de(CPU& cpu);
    void inc_hl(CPU& cpu);
    void add_hl_hl(CPU& cpu);
    void dec_hl(CPU& cpu);
    void inc_sp(CPU& cpu);
    void add_hl_sp(CPU& cpu);
    void dec_sp(CPU& cpu);
    void add_sp_e8(CPU& cpu);
};

#endif // SIXTEEN_BIT_ALU_INSTRUCTION_SET_H