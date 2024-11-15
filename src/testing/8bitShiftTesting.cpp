#include "include/8bitShiftTesting.h"

void EightBitShiftTesting::run(CPU& cpu) {
    std::cout << std::endl << "Running 8-bit Shift tests..." << std::endl;
    assert(test_rlca(cpu), "RLCA");
    assert(test_rrca(cpu), "RRCA");
    assert(test_rra(cpu), "RRA");
    assert(test_rla(cpu), "RLA");
    assert(test_rlc_r(cpu), "RLC r");
    assert(test_rlc_hl_indirect(cpu), "RLC (HL)");
    assert(test_rrc_r(cpu), "RRC r");
    assert(test_rrc_hl_indirect(cpu), "RRC (HL)");
    assert(test_rl_r(cpu), "RL r");
    assert(test_rl_hl_indirect(cpu), "RL (HL)");
    assert(test_rr_r(cpu), "RR r");
    assert(test_rr_hl_indirect(cpu), "RR (HL)");
    assert(test_sla_r(cpu), "SLA r");
    assert(test_sla_hl_indirect(cpu), "SLA (HL)");
    assert(test_sra_r(cpu), "SRA r");
    assert(test_sra_hl_indirect(cpu), "SRA (HL)");
    assert(test_swap_r(cpu), "SWAP r");
    assert(test_swap_hl_indirect(cpu), "SWAP (HL)");
    assert(test_srl_r(cpu), "SRL r");
    assert(test_srl_hl_indirect(cpu), "SRL (HL)");
    assert(test_bit_n_r(cpu), "BIT n, r");
    assert(test_bit_n_hl_indirect(cpu), "BIT n, (HL)");
    assert(test_res_n_r(cpu), "RES n, r");
    assert(test_res_n_hl_indirect(cpu), "RES n, (HL)");
    assert(test_set_n_r(cpu), "SET n, r");
}

bool EightBitShiftTesting::test_rlca(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint8_t opcode = 0x07; // RLCA
    cpu.registers.a_register = 0x80;
    eight_bit_shift_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x01;
}

bool EightBitShiftTesting::test_rrca(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint8_t opcode = 0x0F; // RRCA
    cpu.registers.a_register = 0x01;
    eight_bit_shift_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x80;
}

bool EightBitShiftTesting::test_rra(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint8_t opcode = 0x1F; // RRA
    cpu.registers.a_register = 0x01;
    cpu.registers.set_flag(FLAG_CARRY, false);
    eight_bit_shift_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_rla(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint8_t opcode = 0x17; // RLA
    cpu.registers.a_register = 0x80;
    cpu.registers.set_flag(FLAG_CARRY, false);
    eight_bit_shift_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_rlc_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB00; // RLC B
    cpu.registers.b_register = 0x80;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x01;
}

bool EightBitShiftTesting::test_rlc_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB06; // RLC (HL)
    cpu.write(0xC000, 0x80);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x01;
}

bool EightBitShiftTesting::test_rrc_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB08; // RRC B
    cpu.registers.b_register = 0x01;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x80;
}

bool EightBitShiftTesting::test_rrc_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB0E; // RRC (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x80;
}

bool EightBitShiftTesting::test_rl_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB10; // RL B
    cpu.registers.b_register = 0x80;
    cpu.registers.set_flag(FLAG_CARRY, false);
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_rl_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB16; // RL (HL)
    cpu.write(0xC000, 0x80);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    cpu.registers.set_flag(FLAG_CARRY, false);
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_rr_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB18; // RR B
    cpu.registers.b_register = 0x01;
    cpu.registers.set_flag(FLAG_CARRY, false);
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_rr_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB1E; // RR (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    cpu.registers.set_flag(FLAG_CARRY, false);
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_sla_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB20; // SLA B
    cpu.registers.b_register = 0x80;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_sla_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB26; // SLA (HL)
    cpu.write(0xC000, 0x80);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_sra_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB28; // SRA B
    cpu.registers.b_register = 0x01;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_sra_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB2E; // SRA (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_swap_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB30; // SWAP B
    cpu.registers.b_register = 0x80;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x08;
}

bool EightBitShiftTesting::test_swap_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB36; // SWAP (HL)
    cpu.write(0xC000, 0x80);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x08;
}

bool EightBitShiftTesting::test_srl_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB38; // SRL B
    cpu.registers.b_register = 0x01;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_srl_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB3E; // SRL (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x00 && cpu.registers.flag_register & FLAG_CARRY;
}

bool EightBitShiftTesting::test_bit_n_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB40; // BIT 0, B
    cpu.registers.b_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.flag_register & FLAG_ZERO;
}

bool EightBitShiftTesting::test_bit_n_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB46; // BIT 0, (HL)
    cpu.write(0xC000, 0x00);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.flag_register & FLAG_ZERO;
}

bool EightBitShiftTesting::test_res_n_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB80; // RES 0, B
    cpu.registers.b_register = 0x01;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x00;
}

bool EightBitShiftTesting::test_res_n_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCB86; // RES 0, (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x00;
}

bool EightBitShiftTesting::test_set_n_r(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCBC0; // SET 0, B
    cpu.registers.b_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.registers.b_register == 0x01;
}

bool EightBitShiftTesting::test_set_n_hl_indirect(CPU& cpu) {
    EightBitShiftInstructionSet eight_bit_shift_instr;
    uint16_t opcode = 0xCBC6; // SET 0, (HL)
    cpu.write(0xC000, 0x00);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_shift_instr.execute_prefix(opcode, cpu);
    return cpu.read(0xC000) == 0x01;
}