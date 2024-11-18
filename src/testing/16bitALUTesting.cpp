#include "include/16bitALUTesting.h"

void SixteenBitALUTesting::run(CPU& cpu) {
    std::cout << std::endl << "Running 16-bit ALU tests..." << std::endl;
    assert(test_inc_rr(cpu), "INC rr");
    assert(test_dec_rr(cpu), "DEC rr");
    assert(test_add_hl_rr(cpu), "ADD HL rr");
    assert(test_inc_sp(cpu), "INC SP");
    assert(test_add_hl_sp(cpu), "ADD HL SP");
    assert(test_dec_sp(cpu), "DEC SP");
    assert(test_add_sp_e8(cpu), "ADD SP e8");
}

bool SixteenBitALUTesting::test_inc_rr(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x03; // INC BC
    cpu.setPair(BC, 0x00FF);
    cpu.execute(opcode);
    return cpu.getPair(BC) == 0x0100;
}

bool SixteenBitALUTesting::test_dec_rr(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x0B; // DEC BC
    cpu.setPair(BC, 0x0100);
    cpu.execute(opcode);
    return cpu.getPair(BC) == 0x00FF;
}

bool SixteenBitALUTesting::test_add_hl_rr(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x09; // ADD HL BC
    cpu.setPair(HL, 0x00FF);
    cpu.setPair(BC, 0x0001);
    cpu.execute(opcode);
    return cpu.getPair(HL) == 0x0100;
}

bool SixteenBitALUTesting::test_inc_sp(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x33; // INC SP
    cpu.registers.stack_pointer = 0x0001;
    cpu.execute(opcode);
    return cpu.registers.stack_pointer == 0x0002;
}

bool SixteenBitALUTesting::test_add_hl_sp(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x39; // ADD HL SP
    cpu.setPair(HL, 0x00FF);
    cpu.registers.stack_pointer = 0x0001;
    cpu.execute(opcode);
    return cpu.getPair(HL) == 0x0100;
}

bool SixteenBitALUTesting::test_dec_sp(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x3B; // DEC SP
    cpu.registers.stack_pointer = 0x0001;
    cpu.execute(opcode);
    return cpu.registers.stack_pointer == 0x0000;
}

bool SixteenBitALUTesting::test_add_sp_e8(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0xE8; // ADD SP e8
    cpu.registers.stack_pointer = 0x0001;
    cpu.bus.write(0xC000, 0x01);
    cpu.registers.program_counter = 0xC000;
    cpu.execute(opcode);
    return cpu.registers.stack_pointer == 0x0002;
}