#ifndef EIGHT_BIT_ALU_INSTRUCTION_SET_H
#define EIGHT_BIT_ALU_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

class EightBitALUInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;
private:
    void inc_r(CPU& cpu, Byte& reg);
    void dec_r(CPU& cpu, Byte& reg);
    void inc_hl_indirect(CPU& cpu);
    void dec_hl_indirect(CPU& cpu);
    void daa(CPU& cpu);
    void cpl(CPU& cpu);
    void scf(CPU& cpu);
    void ccf(CPU& cpu);
    void add_r(CPU& cpu, Byte& reg);
    void add_hl_indirect(CPU& cpu);
    void adc_r(CPU& cpu, Byte& reg);
    void adc_hl_indirect(CPU& cpu);
    void sub_r(CPU& cpu, Byte& reg);
    void sub_hl_indirect(CPU& cpu);
    void sbc_r(CPU& cpu, Byte& reg);
    void sbc_hl_indirect(CPU& cpu);
    void and_r(CPU& cpu, Byte& reg);
    void and_hl_indirect(CPU& cpu);
    void xor_r(CPU& cpu, Byte& reg);
    void xor_hl_indirect(CPU& cpu);
    void or_r(CPU& cpu, Byte& reg);
    void or_hl_indirect(CPU& cpu);
    void cp_r(CPU& cpu, Byte& reg);
    void cp_hl_indirect(CPU& cpu);
    void add_n8(CPU& cpu);
    void adc_n8(CPU& cpu);
    void sub_n8(CPU& cpu);
    void sbc_n8(CPU& cpu);
    void and_n8(CPU& cpu);
    void xor_n8(CPU& cpu);
    void or_n8(CPU& cpu);
    void cp_n8(CPU& cpu);
};

#endif // EIGHT_BIT_ALU_INSTRUCTION_SET_H