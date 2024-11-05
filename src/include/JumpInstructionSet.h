#ifndef JUMP_INSTRUCTION_SET_H
#define JUMP_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define JR_e8 0x18
#define JR_NZ_e8 0x20
#define JR_Z_e8 0x28
#define JR_NC_e8 0x30
#define JR_C_e8 0x38
#define RET_NZ 0xC0
#define JP_NZ_a16 0xC2
#define JP_a16 0xC3
#define CALL_NZ_a16 0xC4
#define RST_00H 0xC7
#define RET_Z 0xC8
#define RET 0xC9
#define JP_Z_a16 0xCA
#define CALL_Z_a16 0xCC
#define CALL_a16 0xCD
#define RST_08H 0xCF
#define RET_NC 0xD0
#define JP_NC_a16 0xD2
#define CALL_NC_a16 0xD4
#define RST_10H 0xD7
#define RET_C 0xD8
#define RETI 0xD9
#define JP_C_a16 0xDA
#define CALL_C_a16 0xDC
#define RST_18H 0xDF
#define RST_20H 0xE7
#define JP_HL 0xE9
#define RST_28H 0xEF
#define RST_30H 0xF7
#define RST_38H 0xFF

class JumpInstructionSet : public InstructionSet {
public:
    bool execute(uint8_t opcode, CPU& cpu) override;
    bool execute_prefix(uint16_t opcode, CPU& cpu) override;

private:
    void jr_e8(CPU& cpu);
    void jr_nz_e8(CPU& cpu);
    void jr_z_e8(CPU& cpu);
    void jr_nc_e8(CPU& cpu);
    void jr_c_e8(CPU& cpu);
    void ret_nz(CPU& cpu);
    void jp_nz_a16(CPU& cpu);
    void jp_a16(CPU& cpu);
    void call_nz_a16(CPU& cpu);
    void rst_00H(CPU& cpu);
    void ret_z(CPU& cpu);
    void ret(CPU& cpu);
    void jp_z_a16(CPU& cpu);
    void call_z_a16(CPU& cpu);
    void call_a16(CPU& cpu);
    void rst_08H(CPU& cpu);
    void ret_nc(CPU& cpu);
    void jp_nc_a16(CPU& cpu);
    void call_nc_a16(CPU& cpu);
    void rst_10H(CPU& cpu);
    void ret_c(CPU& cpu);
    void reti(CPU& cpu);
    void jp_c_a16(CPU& cpu);
    void call_c_a16(CPU& cpu);
    void rst_18H(CPU& cpu);
    void rst_20H(CPU& cpu);
    void jp_hl(CPU& cpu);
    void rst_28H(CPU& cpu);
    void rst_30H(CPU& cpu);
    void rst_38H(CPU& cpu);
};

#endif // JUMP_INSTRUCTION_SET_H