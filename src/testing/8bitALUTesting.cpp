#include "include/8bitALUTesting.h"

void EightBitALUTesting::run(CPU& cpu) {
    std::cout << std::endl << "Running 8-bit ALU tests..." << std::endl;
    assert(test_inc_r(cpu), "INC r");
    assert(test_inc_hl_indirect(cpu), "INC (HL)");
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


