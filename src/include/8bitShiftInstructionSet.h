#ifndef EIGHT_BUT_SHIFT_INSTRUCTION_SET_H
#define EIGHT_BIT_SHIFT_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

class EightBitShiftInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;

private:
    void rlca(CPU& cpu);
    void rrca(CPU& cpu);
    void rra(CPU& cpu);
    void rla(CPU& cpu);
    void rlc_r(CPU& cpu, Byte& reg);
    void rlc_hl_indirect(CPU& cpu);
    void rrc_r(CPU& cpu, Byte& reg);
    void rrc_hl_indirect(CPU& cpu);
    void rl_r(CPU& cpu, Byte& reg);
    void rl_hl_indirect(CPU& cpu);
    void rr_r(CPU& cpu, Byte& reg);
    void rr_hl_indirect(CPU& cpu);
    void sla_r(CPU& cpu, Byte& reg);
    void sla_hl_indirect(CPU& cpu);
    void sra_r(CPU& cpu, Byte& reg);
    void sra_hl_indirect(CPU& cpu);
    void swap_r(CPU& cpu, Byte& reg);
    void swap_hl_indirect(CPU& cpu);
    void srl_r(CPU& cpu, Byte& reg);
    void srl_hl_indirect(CPU& cpu);
    void bit_n_r(uint8_t bit, CPU& cpu, Byte& reg);
    void bit_n_hl_indirect(uint8_t bit, CPU& cpu);
    void res_n_r(uint8_t bit, CPU& cpu, Byte& reg);
    void res_n_hl_indirect(uint8_t bit, CPU& cpu);
    void set_n_r(uint8_t bit, CPU& cpu, Byte& reg);
    void set_n_hl_indirect(uint8_t bit, CPU& cpu);
};

#endif