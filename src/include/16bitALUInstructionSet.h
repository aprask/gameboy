#ifndef SIXTEEN_BIT_ALU_INSTRUCTION_SET_H
#define SIXTEEN_BIT_ALU_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define INC_BC 0x03
#define ADD_HL_BC 0x09
#define DEC_BC 0x0B
#define INC_DE 0x13
#define ADD_HL_DE 0x19
#define DEC_DE 0x1B
#define INC_HL 0x23
#define ADD_HL_HL 0x29
#define DEC_HL 0x2B
#define INC_SP 0x33
#define ADD_HL_SP 0x39
#define DEC_SP 0x3B
#define ADD_SP_e8 0xE8

class SixteenBitALUInstructionSet : public InstructionSet {
public:
    bool execute(uint8_t opcode, CPU& cpu) override;
    bool execute_prefix(uint16_t opcode, CPU& cpu) override;

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