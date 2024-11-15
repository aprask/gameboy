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
    cpu.registers.b_register = 0x00;
    cpu.registers.c_register = 0xFF;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.b_register == 0x01 && cpu.registers.c_register == 0x00;
}

bool SixteenBitALUTesting::test_dec_rr(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x0B; // DEC BC
    cpu.registers.b_register = 0x01;
    cpu.registers.c_register = 0x00;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.b_register == 0x00 && cpu.registers.c_register == 0xFF;
}

bool SixteenBitALUTesting::test_add_hl_rr(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x09; // ADD HL BC
    cpu.registers.h_register = 0x00;
    cpu.registers.l_register = 0xFF;
    cpu.registers.b_register = 0x00;
    cpu.registers.c_register = 0x01;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.h_register == 0x01 && cpu.registers.l_register == 0x00;
}

bool SixteenBitALUTesting::test_inc_sp(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x33; // INC SP
    cpu.registers.stack_pointer = 0x0001;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.stack_pointer == 0x0002;
}

bool SixteenBitALUTesting::test_add_hl_sp(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x39; // ADD HL SP
    cpu.registers.h_register = 0x00;
    cpu.registers.l_register = 0xFF;
    cpu.registers.stack_pointer = 0x0001;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.h_register == 0x01 && cpu.registers.l_register == 0x00;
}

bool SixteenBitALUTesting::test_dec_sp(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0x3B; // DEC SP
    cpu.registers.stack_pointer = 0x0001;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.stack_pointer == 0x0000;
}

bool SixteenBitALUTesting::test_add_sp_e8(CPU& cpu) {
    SixteenBitALUInstructionSet sixteen_bit_alu_instr;
    Byte opcode = 0xE8; // ADD SP e8
    cpu.registers.stack_pointer = 0x0001;
    cpu.bus.write(0xC000, 0x01);
    cpu.registers.program_counter = 0xC000;
    sixteen_bit_alu_instr.execute(opcode, cpu);
    return cpu.registers.stack_pointer == 0x0002;
}