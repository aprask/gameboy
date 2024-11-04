#include "InstructionSet.h"
#include "cpu.h"
#ifndef SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H
#define SIXTEEN_BIT_LOAD_INSTRUCTION_SET_H
#define LD_BC_n16 0x01
#define LD_a16_SP 0x08
#define LD_DE_n16 0x11
#define LD_HL_n16 0x21
#define LD_SP_n16 0x31
#define POP_BC 0xC1
#define POP_DE 0xD1
#define POP_HL 0xE1
#define POP_AF 0xF1
#define PUSH_BC 0xC5
#define PUSH_DE 0xD5
#define PUSH_HL 0xE5
#define PUSH_AF 0xF5
#define LP_HL_SP_e8 0xF8
#define LP_SP_HL 0xF9

class SixteenBitLoadInstructionSet : public InstructionSet {
    public:
        bool execute(uint8_t opcode, CPU& cpu) override;
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