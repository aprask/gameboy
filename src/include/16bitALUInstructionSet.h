#ifndef SIXTEEN_BIT_ALU_INSTRUCTION_SET_H
#define SIXTEEN_BIT_ALU_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

class SixteenBitALUInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;

private:
    void inc_rr(CPU& cpu, Byte& reg1, Byte& reg2);
    void dec_rr(CPU& cpu, Byte& reg1, Byte& reg2);
    void add_hl_rr(CPU& cpu, Byte& reg1, Byte& reg2);
    void inc_sp(CPU& cpu);
    void add_hl_sp(CPU& cpu);
    void dec_sp(CPU& cpu);
    void add_sp_e8(CPU& cpu);
};

#endif // SIXTEEN_BIT_ALU_INSTRUCTION_SET_H