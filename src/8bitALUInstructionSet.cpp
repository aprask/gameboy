#include "include/8bitALUInstructionSet.h"

bool EightBitALUInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
        return false;
}

bool EightBitALUInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case INC_B:
            inc_r(cpu, cpu.registers.b_register);
            return true;
        case DEC_B:
            dec_r(cpu, cpu.registers.b_register);
            return true;
        case INC_C:
            inc_r(cpu, cpu.registers.c_register);
            return true;
        case DEC_C:
            dec_r(cpu, cpu.registers.c_register);
            return true;
        case INC_D:
            inc_r(cpu, cpu.registers.d_register);
            return true;
        case DEC_D:
            dec_r(cpu, cpu.registers.d_register);
            return true;
        case INC_E:
            inc_r(cpu, cpu.registers.e_register);
            return true;
        case DEC_E:
            dec_r(cpu, cpu.registers.e_register);
            return true;
        case INC_H:
            inc_r(cpu, cpu.registers.hl_registers[0]);
            return true;
        case DEC_H:
            dec_r(cpu, cpu.registers.hl_registers[0]);
            return true;
        case DAA:
            daa(cpu);
            return true;
        case INC_L:
            inc_r(cpu, cpu.registers.hl_registers[1]);
            return true;
        case DEC_L:
            dec_r(cpu, cpu.registers.hl_registers[1]);
            return true;
        case CPL:
            cpl(cpu);
            return true;
        case INC_HL_INDIRECT:
            inc_hl_indirect(cpu);
            return true;
        case DEC_HL_INDIRECT:
            dec_hl_indirect(cpu);
            return true;
        case SCF:
            scf(cpu);
            return true;
        case INC_A:
            inc_r(cpu, cpu.registers.a_register);
            return true;
        case DEC_A:
            dec_r(cpu, cpu.registers.a_register);
            return true;
        case CCF:
            ccf(cpu);
            return true;
        case ADD_A_B:
            add_r(cpu, cpu.registers.b_register);
            return true;
        case ADD_A_C:
            add_r(cpu, cpu.registers.c_register);
            return true;
        case ADD_A_D:
            add_r(cpu, cpu.registers.d_register);
            return true;
        case ADD_A_E:
            add_r(cpu, cpu.registers.e_register);
            return true;
        case ADD_A_H:
            add_r(cpu, cpu.registers.hl_registers[0]);
            return true;
        case ADD_A_L:
            add_r(cpu, cpu.registers.hl_registers[1]);
            return true;
        case ADD_A_HL:
            add_hl_indirect(cpu);
            return true;
        case ADD_A_A:
            add_r(cpu, cpu.registers.a_register);
            return true;
        case ADC_A_B:
            adc_a_b(cpu);
            return true;
        case ADC_A_C:
            adc_a_c(cpu);
            return true;
        case ADC_A_D:
            adc_a_d(cpu);
            return true;
        case ADC_A_E:
            adc_a_e(cpu);
            return true;
        case ADC_A_H:
            adc_a_h(cpu);
            return true;
        case ADC_A_L:
            adc_a_l(cpu);
            return true;
        case ADC_A_HL:
            adc_a_hl(cpu);
            return true;
        case ADC_A_A:
            adc_a_a(cpu);
            return true;
        case SUB_A_B:
            sub_a_b(cpu);
            return true;
        case SUB_A_C:
            sub_a_c(cpu);
            return true;
        case SUB_A_D:
            sub_a_d(cpu);
            return true;  
        case SUB_A_E:
            sub_a_e(cpu);
            return true;
        case SUB_A_H:
            sub_a_h(cpu);
            return true;
        case SUB_A_L:
            sub_a_l(cpu);
            return true;
        case SUB_A_HL:
            sub_a_hl(cpu);
            return true;
        case SUB_A_A:
            sub_a_a(cpu);
            return true;
        case SBC_A_B:
            sbc_a_b(cpu);
            return true;
        case SBC_A_C:
            sbc_a_c(cpu);
            return true;
        case SBC_A_D:
            sbc_a_d(cpu);
            return true;
        case SBC_A_E:
            sbc_a_e(cpu);
            return true;
        case SBC_A_H:
            sbc_a_h(cpu);
            return true;
        case SBC_A_L:
            sbc_a_l(cpu);
            return true;
        case SBC_A_HL:
            sbc_a_hl(cpu);
            return true;
        case SBC_A_A:
            sbc_a_a(cpu);
            return true;
        case AND_A_B:
            and_a_b(cpu);
            return true;
        case AND_A_C:
            and_a_c(cpu);
            return true;
        case AND_A_D:
            and_a_d(cpu);
            return true;
        case AND_A_E:
            and_a_e(cpu);
            return true;
        case AND_A_H:
            and_a_h(cpu);
            return true;
        case AND_A_L:
            and_a_l(cpu);
            return true;
        case AND_A_HL:
            and_a_hl(cpu);
            return true;
        case AND_A_A:
            and_a_a(cpu);
            return true;
        case XOR_A_B:
            xor_a_b(cpu);
            return true;
        case XOR_A_C:
            xor_a_c(cpu);
            return true;
        case XOR_A_D:
            xor_a_d(cpu);
            return true;
        case XOR_A_E:
            xor_a_e(cpu);
            return true;
        case XOR_A_H:
            xor_a_h(cpu);
            return true;
        case XOR_A_L:
            xor_a_l(cpu);
            return true;
        case XOR_A_HL:
            xor_a_hl(cpu);
            return true;
        case XOR_A_A:
            xor_a_a(cpu);
            return true;
        case OR_A_B:
            or_a_b(cpu);
            return true;
        case OR_A_C:
            or_a_c(cpu);
            return true;
        case OR_A_D:
            or_a_d(cpu);
            return true;
        case OR_A_E:
            or_a_e(cpu);
            return true;
        case OR_A_H:
            or_a_h(cpu);
            return true;
        case OR_A_L:
            or_a_l(cpu);
            return true;
        case OR_A_HL:
            or_a_hl(cpu);
            return true;
        case OR_A_A:
            or_a_a(cpu);
            return true;
        case CP_A_B:
            cp_a_b(cpu);
            return true;
        case CP_A_C:
            cp_a_c(cpu);
            return true;
        case CP_A_D:
            cp_a_d(cpu);
            return true;
        case CP_A_E:
            cp_a_e(cpu);
            return true;
        case CP_A_H:
            cp_a_h(cpu);
            return true;
        case CP_A_L:
            cp_a_l(cpu);
            return true;
        case CP_A_HL:
            cp_a_hl(cpu);
            return true;
        case CP_A_A:
            cp_a_a(cpu);
            return true;
        case ADD_A_n8:
            add_a_n8(cpu);
            return true;
        case SUB_A_n8:
            sub_a_n8(cpu);
            return true;
        case SBC_A_n8:
            sbc_a_n8(cpu);
            return true;
        case AND_A_n8:
            and_a_n8(cpu);
            return true;
        case XOR_A_n8:
            xor_a_n8(cpu);
            return true;
        case OR_A_n8:
            or_a_n8(cpu);
            return true;
        case CP_A_n8:
            cp_a_n8(cpu);
            return true;
        default:
            return false; // Opcode not handled by EightBitALUInstructionSet
    }

    cpu.registers.instruction_register = cpu.bus.read(cpu.registers.program_counter); // Read the next byte from memory)
    cpu.registers.program_counter++; // Increment program counter
}

void EightBitALUInstructionSet::inc_r(CPU& cpu, Byte& reg) {
    reg++; // Increment register
    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);

    // Half carry flag is set if there is a carry from the 3rd bit
    if (reg & 0x08 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }
}

void EightBitALUInstructionSet::dec_r(CPU& cpu, Byte& reg) {
    reg--; // Decrement register
    if (reg == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, true);

    // Half carry flag is set if there is a borrow from the 4th bit
    if (reg & 0x08 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }
}

void EightBitALUInstructionSet::daa(CPU& cpu) {
    // DAA arithmetic operation was hardcoded into the gameboy. I don't know exactly how this works.
    // Source - https://ehaskins.com/2018-01-30%20Z80%20DAA/

    Byte a = cpu.registers.a_register; 

    if (cpu.registers.flag_register & FLAG_SUBTRACT) { // if n
        if (cpu.registers.flag_register & FLAG_HALF_CARRY) {
            a = (a - 0x06) & 0xFF;
        }

        if (cpu.registers.flag_register & FLAG_CARRY) {
            a = (a - 0x60) & 0xFF;
        }
    } else { // if not n
        if ((a & 0x0F) > 0x09 || cpu.registers.flag_register & FLAG_HALF_CARRY) {
            a += 0x06;
        }

        if (a > 0x99 || cpu.registers.flag_register & FLAG_CARRY) {
            cpu.registers.set_flag(FLAG_CARRY, true);
            a += 0x60;
        }
    }

    if (a == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_HALF_CARRY, false);
}

void EightBitALUInstructionSet::cpl(CPU& cpu) {
    // Placeholder: Call the cpl function on the CPU
    // Example: cpu.cpl();
}

void EightBitALUInstructionSet::inc_hl_indirect(CPU& cpu) {
    // hl is an array with two eight bit elements, so we shift the first element 8 bits to the left and OR it with the second element to get the 16 bit address
    Byte data = cpu.bus.read(cpu.registers.hl_registers[0] << 8 | cpu.registers.hl_registers[1]);
    data++; // Increment data

    cpu.bus.write(cpu.registers.hl_registers[0] << 8 | cpu.registers.hl_registers[1], data); // address, data

    if (data == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);

    if (data & 0x08 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }
}

void EightBitALUInstructionSet::dec_hl_indirect(CPU& cpu) {
    Byte data = cpu.bus.read(cpu.registers.hl_registers[0] << 8 | cpu.registers.hl_registers[1]);
    data--; // Increment data

    cpu.bus.write(cpu.registers.hl_registers[0] << 8 | cpu.registers.hl_registers[1], data); // address, data

    if (data == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, true);

    if (data & 0x08 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }
}

void EightBitALUInstructionSet::scf(CPU& cpu) {
    // Placeholder: Call the scf function on the CPU
    // Example: cpu.scf();
}

void EightBitALUInstructionSet::ccf(CPU& cpu) {
    // Placeholder: Call the ccf function on the CPU
    // Example: cpu.ccf();
}

void EightBitALUInstructionSet::add_r(CPU& cpu, Byte& reg) {
    Byte result = cpu.registers.a_register + reg;
    cpu.registers.a_register = result;

    if (result == 0) {
        cpu.registers.set_flag(FLAG_ZERO, true);
    } else {
        cpu.registers.set_flag(FLAG_ZERO, false);
    }

    cpu.registers.set_flag(FLAG_SUBTRACT, false);

    if (result & 0x08 == 0) {
        cpu.registers.set_flag(FLAG_HALF_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_HALF_CARRY, true);
    }

    if (result & 0x80 == 0) {
        cpu.registers.set_flag(FLAG_CARRY, false);
    } else {
        cpu.registers.set_flag(FLAG_CARRY, true);
    }
}

void EightBitALUInstructionSet::add_hl_indirect(CPU& cpu) {
    Byte data = cpu.bus.read(cpu.registers.hl_registers[0] << 8 | cpu.registers.hl_registers[1]);
    add_r(cpu, data);
}

void EightBitALUInstructionSet::adc_a_b(CPU& cpu) {
    // Placeholder: Call the adc_a_b function on the CPU
    // Example: cpu.adc_a_b();
}

void EightBitALUInstructionSet::adc_a_c(CPU& cpu) {
    // Placeholder: Call the adc_a_c function on the CPU
    // Example: cpu.adc_a_c();
}

void EightBitALUInstructionSet::adc_a_d(CPU& cpu) {
    // Placeholder: Call the adc_a_d function on the CPU
    // Example: cpu.adc_a_d();
}

void EightBitALUInstructionSet::adc_a_e(CPU& cpu) {
    // Placeholder: Call the adc_a_e function on the CPU
    // Example: cpu.adc_a_e();
}

void EightBitALUInstructionSet::adc_a_h(CPU& cpu) {
    // Placeholder: Call the adc_a_h function on the CPU
    // Example: cpu.adc_a_h();
}

void EightBitALUInstructionSet::adc_a_l(CPU& cpu) {
    // Placeholder: Call the adc_a_l function on the CPU
    // Example: cpu.adc_a_l();
}

void EightBitALUInstructionSet::adc_a_hl(CPU& cpu) {
    // Placeholder: Call the adc_a_hl function on the CPU
    // Example: cpu.adc_a_hl();
}

void EightBitALUInstructionSet::adc_a_a(CPU& cpu) {
    // Placeholder: Call the adc_a_a function on the CPU
    // Example: cpu.adc_a_a();
}

void EightBitALUInstructionSet::sub_a_b(CPU& cpu) {
    // Placeholder: Call the sub_a_b function on the CPU
    // Example: cpu.sub_a_b();
}

void EightBitALUInstructionSet::sub_a_c(CPU& cpu) {
    // Placeholder: Call the sub_a_c function on the CPU
    // Example: cpu.sub_a_c();
}

void EightBitALUInstructionSet::sub_a_d(CPU& cpu) {
    // Placeholder: Call the sub_a_d function on the CPU
    // Example: cpu.sub_a_d();
}

void EightBitALUInstructionSet::sub_a_e(CPU& cpu) {
    // Placeholder: Call the sub_a_e function on the CPU
    // Example: cpu.sub_a_e();
}

void EightBitALUInstructionSet::sub_a_h(CPU& cpu) {
    // Placeholder: Call the sub_a_h function on the CPU
    // Example: cpu.sub_a_h();
}

void EightBitALUInstructionSet::sub_a_l(CPU& cpu) {
    // Placeholder: Call the sub_a_l function on the CPU
    // Example: cpu.sub_a_l();
}

void EightBitALUInstructionSet::sub_a_hl(CPU& cpu) {
    // Placeholder: Call the sub_a_hl function on the CPU
    // Example: cpu.sub_a_hl();
}

void EightBitALUInstructionSet::sub_a_a(CPU& cpu) {
    // Placeholder: Call the sub_a_a function on the CPU
    // Example: cpu.sub_a_a();
}

void EightBitALUInstructionSet::sbc_a_b(CPU& cpu) {
    // Placeholder: Call the sbc_a_b function on the CPU
    // Example: cpu.sbc_a_b();
}

void EightBitALUInstructionSet::sbc_a_c(CPU& cpu) {
    // Placeholder: Call the sbc_a_c function on the CPU
    // Example: cpu.sbc_a_c();
}

void EightBitALUInstructionSet::sbc_a_d(CPU& cpu) {
    // Placeholder: Call the sbc_a_d function on the CPU
    // Example: cpu.sbc_a_d();
}

void EightBitALUInstructionSet::sbc_a_e(CPU& cpu) {
    // Placeholder: Call the sbc_a_e function on the CPU
    // Example: cpu.sbc_a_e();
}

void EightBitALUInstructionSet::sbc_a_h(CPU& cpu) {
    // Placeholder: Call the sbc_a_h function on the CPU
    // Example: cpu.sbc_a_h();
}

void EightBitALUInstructionSet::sbc_a_l(CPU& cpu) {
    // Placeholder: Call the sbc_a_l function on the CPU
    // Example: cpu.sbc_a_l();
}

void EightBitALUInstructionSet::sbc_a_hl(CPU& cpu) {
    // Placeholder: Call the sbc_a_hl function on the CPU
    // Example: cpu.sbc_a_hl();
}

void EightBitALUInstructionSet::sbc_a_a(CPU& cpu) {
    // Placeholder: Call the sbc_a_a function on the CPU
    // Example: cpu.sbc_a_a();
}

void EightBitALUInstructionSet::and_a_b(CPU& cpu) {
    // Placeholder: Call the and_a_b function on the CPU
    // Example: cpu.and_a_b();
}

void EightBitALUInstructionSet::and_a_c(CPU& cpu) {
    // Placeholder: Call the and_a_c function on the CPU
    // Example: cpu.and_a_c();
}

void EightBitALUInstructionSet::and_a_d(CPU& cpu) {
    // Placeholder: Call the and_a_d function on the CPU
    // Example: cpu.and_a_d();
}

void EightBitALUInstructionSet::and_a_e(CPU& cpu) {
    // Placeholder: Call the and_a_e function on the CPU
    // Example: cpu.and_a_e();
}

void EightBitALUInstructionSet::and_a_h(CPU& cpu) {
    // Placeholder: Call the and_a_h function on the CPU
    // Example: cpu.and_a_h();
}

void EightBitALUInstructionSet::and_a_l(CPU& cpu) {
    // Placeholder: Call the and_a_l function on the CPU
    // Example: cpu.and_a_l();
}

void EightBitALUInstructionSet::and_a_hl(CPU& cpu) {
    // Placeholder: Call the and_a_hl function on the CPU
    // Example: cpu.and_a_hl();
}

void EightBitALUInstructionSet::and_a_a(CPU& cpu) {
    // Placeholder: Call the and_a_a function on the CPU
    // Example: cpu.and_a_a();
}

void EightBitALUInstructionSet::xor_a_b(CPU& cpu) {
    // Placeholder: Call the xor_a_b function on the CPU
    // Example: cpu.xor_a_b();
}

void EightBitALUInstructionSet::xor_a_c(CPU& cpu) {
    // Placeholder: Call the xor_a_c function on the CPU
    // Example: cpu.xor_a_c();
}

void EightBitALUInstructionSet::xor_a_d(CPU& cpu) {
    // Placeholder: Call the xor_a_d function on the CPU
    // Example: cpu.xor_a_d();
}

void EightBitALUInstructionSet::xor_a_e(CPU& cpu) {
    // Placeholder: Call the xor_a_e function on the CPU
    // Example: cpu.xor_a_e();
}

void EightBitALUInstructionSet::xor_a_h(CPU& cpu) {
    // Placeholder: Call the xor_a_h function on the CPU
    // Example: cpu.xor_a_h();
}

void EightBitALUInstructionSet::xor_a_l(CPU& cpu) {
    // Placeholder: Call the xor_a_l function on the CPU
    // Example: cpu.xor_a_l();
}

void EightBitALUInstructionSet::xor_a_hl(CPU& cpu) {
    // Placeholder: Call the xor_a_hl function on the CPU
    // Example: cpu.xor_a_hl();
}

void EightBitALUInstructionSet::xor_a_a(CPU& cpu) {
    // Placeholder: Call the xor_a_a function on the CPU
    // Example: cpu.xor_a_a();
}

void EightBitALUInstructionSet::or_a_b(CPU& cpu) {
    // Placeholder: Call the or_a_b function on the CPU
    // Example: cpu.or_a_b();
}

void EightBitALUInstructionSet::or_a_c(CPU& cpu) {
    // Placeholder: Call the or_a_c function on the CPU
    // Example: cpu.or_a_c();
}

void EightBitALUInstructionSet::or_a_d(CPU& cpu) {
    // Placeholder: Call the or_a_d function on the CPU
    // Example: cpu.or_a_d();
}

void EightBitALUInstructionSet::or_a_e(CPU& cpu) {
    // Placeholder: Call the or_a_e function on the CPU
    // Example: cpu.or_a_e();
}

void EightBitALUInstructionSet::or_a_h(CPU& cpu) {
    // Placeholder: Call the or_a_h function on the CPU
    // Example: cpu.or_a_h();
}

void EightBitALUInstructionSet::or_a_l(CPU& cpu) {
    // Placeholder: Call the or_a_l function on the CPU
    // Example: cpu.or_a_l();
}

void EightBitALUInstructionSet::or_a_hl(CPU& cpu) {
    // Placeholder: Call the or_a_hl function on the CPU
    // Example: cpu.or_a_hl();
}

void EightBitALUInstructionSet::or_a_a(CPU& cpu) {
    // Placeholder: Call the or_a_a function on the CPU
    // Example: cpu.or_a_a();
}

void EightBitALUInstructionSet::cp_a_b(CPU& cpu) {
    // Placeholder: Call the cp_a_b function on the CPU
    // Example: cpu.cp_a_b();
}

void EightBitALUInstructionSet::cp_a_c(CPU& cpu) {
    // Placeholder: Call the cp_a_c function on the CPU
    // Example: cpu.cp_a_c();
}

void EightBitALUInstructionSet::cp_a_d(CPU& cpu) {
    // Placeholder: Call the cp_a_d function on the CPU
    // Example: cpu.cp_a_d();
}

void EightBitALUInstructionSet::cp_a_e(CPU& cpu) {
    // Placeholder: Call the cp_a_e function on the CPU
    // Example: cpu.cp_a_e();
}

void EightBitALUInstructionSet::cp_a_h(CPU& cpu) {
    // Placeholder: Call the cp_a_h function on the CPU
    // Example: cpu.cp_a_h();
}

void EightBitALUInstructionSet::cp_a_l(CPU& cpu) {
    // Placeholder: Call the cp_a_l function on the CPU
    // Example: cpu.cp_a_l();
}

void EightBitALUInstructionSet::cp_a_hl(CPU& cpu) {
    // Placeholder: Call the cp_a_hl function on the CPU
    // Example: cpu.cp_a_hl();
}

void EightBitALUInstructionSet::cp_a_a(CPU& cpu) {
    // Placeholder: Call the cp_a_a function on the CPU
    // Example: cpu.cp_a_a();
}

void EightBitALUInstructionSet::add_a_n8(CPU& cpu) {
    // Placeholder: Call the add_a_n8 function on the CPU
    // Example: cpu.add_a_n8();
}

void EightBitALUInstructionSet::sub_a_n8(CPU& cpu) {
    // Placeholder: Call the sub_a_n8 function on the CPU
    // Example: cpu.sub_a_n8();
}

void EightBitALUInstructionSet::adc_a_n8(CPU& cpu) {
    // Placeholder: Call the adc_a_n8 function on the CPU
    // Example: cpu.adc_a_n8();
}

void EightBitALUInstructionSet::sbc_a_n8(CPU& cpu) {
    // Placeholder: Call the sbc_a_n8 function on the CPU
    // Example: cpu.sbc_a_n8();
}

void EightBitALUInstructionSet::and_a_n8(CPU& cpu) {
    // Placeholder: Call the and_a_n8 function on the CPU
    // Example: cpu.and_a_n8();
}

void EightBitALUInstructionSet::xor_a_n8(CPU& cpu) {
    // Placeholder: Call the xor_a_n8 function on the CPU
    // Example: cpu.xor_a_n8();
}

void EightBitALUInstructionSet::or_a_n8(CPU& cpu) {
    // Placeholder: Call the or_a_n8 function on the CPU
    // Example: cpu.or_a_n8();
}

void EightBitALUInstructionSet::cp_a_n8(CPU& cpu) {
    // Placeholder: Call the cp_a_n8 function on the CPU
    // Example: cpu.cp_a_n8();
}