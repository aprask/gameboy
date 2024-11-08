#ifndef EIGHT_BIT_ALU_INSTRUCTION_SET_H
#define EIGHT_BIT_ALU_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define INC_B 0x04
#define DEC_B 0x05
#define INC_C 0x0C
#define DEC_C 0x0D
#define INC_D 0x14
#define DEC_D 0x15
#define INC_E 0x1C
#define DEC_E 0x1D
#define INC_H 0x24
#define DEC_H 0x25
#define DAA 0x27
#define INC_L 0x2C
#define DEC_L 0x2D
#define CPL 0x2F
#define INC_HL_INDIRECT 0x34 // INC (HL) not INC HL 
#define DEC_HL_INDIRECT 0x35 // DEC (HL) not DEC HL
#define SCF 0x37
#define INC_A 0x3C
#define DEC_A 0x3D
#define CCF 0x3F
#define ADD_A_B 0x80
#define ADD_A_C 0x81
#define ADD_A_D 0x82
#define ADD_A_E 0x83
#define ADD_A_H 0x84
#define ADD_A_L 0x85
#define ADD_A_HL 0x86
#define ADD_A_A 0x87
#define ADC_A_B 0x88
#define ADC_A_C 0x89
#define ADC_A_D 0x8A
#define ADC_A_E 0x8B
#define ADC_A_H 0x8C
#define ADC_A_L 0x8D
#define ADC_A_HL 0x8E
#define ADC_A_A 0x8F
#define SUB_A_B 0x90
#define SUB_A_C 0x91
#define SUB_A_D 0x92
#define SUB_A_E 0x93
#define SUB_A_H 0x94
#define SUB_A_L 0x95
#define SUB_A_HL 0x96
#define SUB_A_A 0x97
#define SBC_A_B 0x98
#define SBC_A_C 0x99
#define SBC_A_D 0x9A
#define SBC_A_E 0x9B
#define SBC_A_H 0x9C
#define SBC_A_L 0x9D
#define SBC_A_HL 0x9E
#define SBC_A_A 0x9F
#define AND_A_B 0xA0
#define AND_A_C 0xA1
#define AND_A_D 0xA2
#define AND_A_E 0xA3
#define AND_A_H 0xA4
#define AND_A_L 0xA5
#define AND_A_HL 0xA6
#define AND_A_A 0xA7
#define XOR_A_B 0xA8
#define XOR_A_C 0xA9
#define XOR_A_D 0xAA
#define XOR_A_E 0xAB
#define XOR_A_H 0xAC
#define XOR_A_L 0xAD
#define XOR_A_HL 0xAE
#define XOR_A_A 0xAF
#define OR_A_B 0xB0
#define OR_A_C 0xB1
#define OR_A_D 0xB2
#define OR_A_E 0xB3
#define OR_A_H 0xB4
#define OR_A_L 0xB5
#define OR_A_HL 0xB6
#define OR_A_A 0xB7
#define CP_A_B 0xB8
#define CP_A_C 0xB9
#define CP_A_D 0xBA
#define CP_A_E 0xBB
#define CP_A_H 0xBC
#define CP_A_L 0xBD
#define CP_A_HL 0xBE
#define CP_A_A 0xBF
#define ADD_A_n8 0xC6
#define ADC_A_n8 0xCE
#define SUB_A_n8 0xD6
#define SBC_A_n8 0xDE
#define AND_A_n8 0xE6
#define XOR_A_n8 0xEE
#define OR_A_n8 0xF6
#define CP_A_n8 0xFE

class EightBitALUInstructionSet : public InstructionSet {
public:
    bool execute(uint8_t opcode, CPU& cpu) override;
    bool execute_prefix(uint16_t opcode, CPU& cpu) override;

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