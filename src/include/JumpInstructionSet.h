#ifndef JUMP_INSTRUCTION_SET_H
#define JUMP_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

class JumpInstructionSet : public InstructionSet {
public:
    void initializeInstructionTable(CPU& cpu) override;

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