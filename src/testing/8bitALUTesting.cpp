#include "include/8bitALUTesting.h"

void EightBitALUTesting::run(CPU& cpu) {
    std::cout << std::endl << "Running 8-bit ALU tests..." << std::endl;
    assert(test_inc_r(cpu), "INC r");
    assert(test_inc_hl_indirect(cpu), "INC (HL)");
}

bool EightBitALUTesting::test_inc_r(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x04; // INC B
    cpu.registers.b = 0x01;
    cpu.execute(opcode);
    return cpu.registers.b == 0x02;
}

bool EightBitALUTesting::test_inc_hl_indirect(CPU& cpu) {
    EightBitALUInstructionSet eight_bit_alu_instr;
    uint8_t opcode = 0x34; // INC (HL)
    cpu.write(0xC000, 0x01);
    cpu.setPair(HL, 0xC000);
    cpu.execute(opcode);
    return cpu.read(0xC000) == 0x02;
}


