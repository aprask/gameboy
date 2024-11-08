#include "include/8bitALUTesting.h"

void EightBitALUTesting::run(CPU& cpu) {
    std::cout << std::endl << "Running 8-bit ALU tests..." << std::endl;

    assert(test_inc_r(cpu), "INC r");
    assert(test_inc_hl_indirect(cpu), "INC (HL)");
    assert(test_dec_r(cpu), "DEC r");
    assert(test_dec_hl_indirect(cpu), "DEC (HL)");
    assert(test_daa(cpu), "DAA");
    assert(test_cpl(cpu), "CPL");
    assert(test_scf(cpu), "SCF");
    assert(test_ccf(cpu), "CCF");
    assert(test_add_r(cpu), "ADD r");
    assert(test_add_hl_indirect(cpu), "ADD (HL)");
    assert(test_adc_r(cpu), "ADC r");
    assert(test_adc_hl_indirect(cpu), "ADC (HL)");
    assert(test_sub_r(cpu), "SUB r");
    assert(test_sub_hl_indirect(cpu), "SUB (HL)");
    assert(test_sbc_r(cpu), "SBC r");
    assert(test_sbc_hl_indirect(cpu), "SBC (HL)");
    assert(test_and_r(cpu), "AND r");
    assert(test_and_hl_indirect(cpu), "AND (HL)");
    assert(test_xor_r(cpu), "XOR r");
    assert(test_xor_hl_indirect(cpu), "XOR (HL)");
    assert(test_or_r(cpu), "OR r");
    assert(test_or_hl_indirect(cpu), "OR (HL)");
    assert(test_cp_r(cpu), "CP r");
    assert(test_cp_hl_indirect(cpu), "CP (HL)");
    assert(test_add_n8(cpu), "ADD n8");
    assert(test_adc_n8(cpu), "ADC n8");
    assert(test_sub_n8(cpu), "SUB n8");
    assert(test_sbc_n8(cpu), "SBC n8");
    assert(test_and_n8(cpu), "AND n8");
    assert(test_xor_n8(cpu), "XOR n8");
    assert(test_or_n8(cpu), "OR n8");
    assert(test_cp_n8(cpu), "CP n8");
}

bool EightBitALUTesting::test_inc_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x04; // INC B
    cpu.registers.b_register = 0x01;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.b_register == 0x02;
}

bool EightBitALUTesting::test_inc_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x34; // INC (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.read(0xC000) == 0x02;
}

bool EightBitALUTesting::test_dec_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x05; // DEC B
    cpu.registers.b_register = 0x01;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.b_register == 0x00;
}

bool EightBitALUTesting::test_dec_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x35; // DEC (HL)
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.read(0xC000) == 0x00;
}

bool EightBitALUTesting::test_daa(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x27; // DAA
    cpu.registers.a_register = 0x45;
    cpu.registers.flag_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x45;
}

bool EightBitALUTesting::test_cpl(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x2F; // CPL
    cpu.registers.a_register = 0x45;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0xBA;
}

bool EightBitALUTesting::test_scf(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x37; // SCF
    cpu.registers.flag_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.flag_register == 0x10;
}

bool EightBitALUTesting::test_ccf(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x3F; // CCF
    cpu.registers.flag_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.flag_register == 0x10;
}

bool EightBitALUTesting::test_add_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x80; // ADD A, B
    cpu.registers.a_register = 0x01;
    cpu.registers.b_register = 0x02;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_add_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x86; // ADD A, (HL)
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_adc_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x88; // ADC A, B
    cpu.registers.a_register = 0x01;
    cpu.registers.b_register = 0x02;
    cpu.registers.flag_register = 0x10;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x04;
}

bool EightBitALUTesting::test_adc_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x8E; // ADC A, (HL)
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    cpu.registers.flag_register = 0x10;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x04;
}

bool EightBitALUTesting::test_sub_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x90; // SUB B
    cpu.registers.a_register = 0x02;
    cpu.registers.b_register = 0x01;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x01;
}

bool EightBitALUTesting::test_sub_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x96; // SUB (HL)
    cpu.registers.a_register = 0x02;
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x01;
}

bool EightBitALUTesting::test_sbc_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x98; // SBC A, B
    cpu.registers.a_register = 0x02;
    cpu.registers.b_register = 0x01;
    cpu.registers.flag_register = 0x10;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00;
}

bool EightBitALUTesting::test_sbc_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x9E; // SBC A, (HL)
    cpu.registers.a_register = 0x02;
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    cpu.registers.flag_register = 0x10;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00;
}

bool EightBitALUTesting::test_and_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xA0; // AND B
    cpu.registers.a_register = 0x01;
    cpu.registers.b_register = 0x02;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00;
}

bool EightBitALUTesting::test_and_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xA6; // AND (HL)
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00;
}

bool EightBitALUTesting::test_xor_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xA8; // XOR B
    cpu.registers.a_register = 0x01;
    cpu.registers.b_register = 0x02;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_xor_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xAE; // XOR (HL)
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_or_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xB0; // OR B
    cpu.registers.a_register = 0x01;
    cpu.registers.b_register = 0x02;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_or_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xB6; // OR (HL)
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_cp_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xB8; // CP B
    cpu.registers.a_register = 0x02;
    cpu.registers.b_register = 0x01;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x02;
}

bool EightBitALUTesting::test_cp_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xBE; // CP (HL)
    cpu.registers.a_register = 0x02;
    cpu.write(0xC000, 0x01);
    cpu.registers.h_register = 0xC0;
    cpu.registers.l_register = 0x00;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x02;
}

bool EightBitALUTesting::test_add_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xC6; // ADD A, n8
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.program_counter = 0xC000;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_adc_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xCE; // ADC A, n8
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.program_counter = 0xC000;
    cpu.registers.flag_register = 0x10;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x04;
}

bool EightBitALUTesting::test_sub_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xD6; // SUB n8
    cpu.registers.a_register = 0x02;
    cpu.write(0xC000, 0x01);
    cpu.registers.program_counter = 0xC000;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x01;
}

bool EightBitALUTesting::test_sbc_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xDE; // SBC A, n8
    cpu.registers.a_register = 0x02;
    cpu.write(0xC000, 0x01);
    cpu.registers.program_counter = 0xC000;
    cpu.registers.flag_register = 0x10;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00;
}

bool EightBitALUTesting::test_and_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xE6; // AND n8
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.program_counter = 0xC000;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x00;
}

bool EightBitALUTesting::test_xor_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xEE; // XOR n8
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.program_counter = 0xC000;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_or_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xF6; // OR n8
    cpu.registers.a_register = 0x01;
    cpu.write(0xC000, 0x02);
    cpu.registers.program_counter = 0xC000;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x03;
}

bool EightBitALUTesting::test_cp_n8(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0xFE; // CP n8
    cpu.registers.a_register = 0x02;
    cpu.write(0xC000, 0x01);
    cpu.registers.program_counter = 0xC000;
    eight_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.a_register == 0x02;
}