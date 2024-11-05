#include "include/8bitALUInstructionSet.h"

bool EightBitALUInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
        return false;
}

bool EightBitALUInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case INC_B:
            inc_b(cpu);
            return true;
        case DEC_B:
            dec_b(cpu);
            return true;
        case INC_C:
            inc_c(cpu);
            return true;
        case DEC_C:
            dec_c(cpu);
            return true;
        case INC_D:
            inc_d(cpu);
            return true;
        case DEC_D:
            dec_d(cpu);
            return true;
        case INC_E:
            inc_e(cpu);
            return true;
        case DEC_E:
            dec_e(cpu);
            return true;
        case INC_H:
            inc_h(cpu);
            return true;
        case DEC_H:
            dec_h(cpu);
            return true;
        case DAA:
            daa(cpu);
            return true;
        case INC_L:
            inc_l(cpu);
            return true;
        case DEC_L:
            dec_l(cpu);
            return true;
        case CPL:
            cpl(cpu);
            return true;
        case INC_HL_PTR:
            inc_hl(cpu);
            return true;
        case DEC_HL_PTR:
            dec_hl(cpu);
            return true;
        case SCF:
            scf(cpu);
            return true;
        case INC_A:
            inc_a(cpu);
            return true;
        case DEC_A:
            dec_a(cpu);
            return true;
        case CCF:
            ccf(cpu);
            return true;
        case ADD_A_B:
            add_a_b(cpu);
            return true;
        case ADD_A_C:
            add_a_c(cpu);
            return true;
        case ADD_A_D:
            add_a_d(cpu);
            return true;
        case ADD_A_E:
            add_a_e(cpu);
            return true;
        case ADD_A_H:
            add_a_h(cpu);
            return true;
        case ADD_A_L:
            add_a_l(cpu);
            return true;
        case ADD_A_HL:
            add_a_hl(cpu);
            return true;
        case ADD_A_A:
            add_a_a(cpu);
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
}

void EightBitALUInstructionSet::inc_b(CPU& cpu) {
    // Placeholder: Call the inc_b function on the CPU
    // Example: cpu.inc_b();
}

void EightBitALUInstructionSet::dec_b(CPU& cpu) {
    // Placeholder: Call the dec_b function on the CPU
    // Example: cpu.dec_b();
}

void EightBitALUInstructionSet::inc_c(CPU& cpu) {
    // Placeholder: Call the inc_c function on the CPU
    // Example: cpu.inc_c();
}

void EightBitALUInstructionSet::dec_c(CPU& cpu) {
    // Placeholder: Call the dec_c function on the CPU
    // Example: cpu.dec_c();
}

void EightBitALUInstructionSet::inc_d(CPU& cpu) {
    // Placeholder: Call the inc_d function on the CPU
    // Example: cpu.inc_d();
}

void EightBitALUInstructionSet::dec_d(CPU& cpu) {
    // Placeholder: Call the dec_d function on the CPU
    // Example: cpu.dec_d();
}

void EightBitALUInstructionSet::inc_e(CPU& cpu) {
    // Placeholder: Call the inc_e function on the CPU
    // Example: cpu.inc_e();
}

void EightBitALUInstructionSet::dec_e(CPU& cpu) {
    // Placeholder: Call the dec_e function on the CPU
    // Example: cpu.dec_e();
}

void EightBitALUInstructionSet::inc_h(CPU& cpu) {
    // Placeholder: Call the inc_h function on the CPU
    // Example: cpu.inc_h();
}

void EightBitALUInstructionSet::dec_h(CPU& cpu) {
    // Placeholder: Call the dec_h function on the CPU
    // Example: cpu.dec_h();
}

void EightBitALUInstructionSet::daa(CPU& cpu) {
    // Placeholder: Call the daa function on the CPU
    // Example: cpu.daa();
}

void EightBitALUInstructionSet::inc_l(CPU& cpu) {
    // Placeholder: Call the inc_l function on the CPU
    // Example: cpu.inc_l();
}

void EightBitALUInstructionSet::dec_l(CPU& cpu) {
    // Placeholder: Call the dec_l function on the CPU
    // Example: cpu.dec_l();
}

void EightBitALUInstructionSet::cpl(CPU& cpu) {
    // Placeholder: Call the cpl function on the CPU
    // Example: cpu.cpl();
}

void EightBitALUInstructionSet::inc_hl(CPU& cpu) {
    // Placeholder: Call the inc_hl function on the CPU
    // Example: cpu.inc_hl();
}

void EightBitALUInstructionSet::dec_hl(CPU& cpu) {
    // Placeholder: Call the dec_hl function on the CPU
    // Example: cpu.dec_hl();
}

void EightBitALUInstructionSet::scf(CPU& cpu) {
    // Placeholder: Call the scf function on the CPU
    // Example: cpu.scf();
}

void EightBitALUInstructionSet::inc_a(CPU& cpu) {
    // Placeholder: Call the inc_a function on the CPU
    // Example: cpu.inc_a();
}

void EightBitALUInstructionSet::dec_a(CPU& cpu) {
    // Placeholder: Call the dec_a function on the CPU
    // Example: cpu.dec_a();
}

void EightBitALUInstructionSet::ccf(CPU& cpu) {
    // Placeholder: Call the ccf function on the CPU
    // Example: cpu.ccf();
}

void EightBitALUInstructionSet::add_a_b(CPU& cpu) {
    // Placeholder: Call the add_a_b function on the CPU
    // Example: cpu.add_a_b();
}

void EightBitALUInstructionSet::add_a_c(CPU& cpu) {
    // Placeholder: Call the add_a_c function on the CPU
    // Example: cpu.add_a_c();
}

void EightBitALUInstructionSet::add_a_d(CPU& cpu) {
    // Placeholder: Call the add_a_d function on the CPU
    // Example: cpu.add_a_d();
}

void EightBitALUInstructionSet::add_a_e(CPU& cpu) {
    // Placeholder: Call the add_a_e function on the CPU
    // Example: cpu.add_a_e();
}

void EightBitALUInstructionSet::add_a_h(CPU& cpu) {
    // Placeholder: Call the add_a_h function on the CPU
    // Example: cpu.add_a_h();
}

void EightBitALUInstructionSet::add_a_l(CPU& cpu) {
    // Placeholder: Call the add_a_l function on the CPU
    // Example: cpu.add_a_l();
}

void EightBitALUInstructionSet::add_a_hl(CPU& cpu) {
    // Placeholder: Call the add_a_hl function on the CPU
    // Example: cpu.add_a_hl();
}

void EightBitALUInstructionSet::add_a_a(CPU& cpu) {
    // Placeholder: Call the add_a_a function on the CPU
    // Example: cpu.add_a_a();
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