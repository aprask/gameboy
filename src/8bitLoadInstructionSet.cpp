#include "include/8bitLoadInstructionSet.h"

bool EightBitLoadInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case LD_BC_A:
            ld_bc_a(cpu);
            return true;
        case LD_B_n8:
            ld_b_n8(cpu);
            return true;
        case LD_A_BC:
            ld_a_bc(cpu);
            return true;
        case LD_C_n8:
            ld_c_n8(cpu);
            return true;
        case LD_DE_A:
            ld_de_a(cpu);
            return true;
        case LD_D_n8:
            ld_d_n8(cpu);
            return true;
        case LD_A_DE:
            ld_a_de(cpu);
            return true;
        case LD_E_n8:
            ld_e_n8(cpu);
            return true;
        case LD_HL_INC_A:
            ld_hl_inc_a(cpu);
            return true;
        case LD_H_n8:
            ld_h_n8(cpu);
            return true;
        case LD_A_HL_INC:
            ld_a_hl_inc(cpu);
            return true;
        case LD_L_n8:
            ld_l_n8(cpu);
            return true;
        case LD_HL_DEC_A:
            ld_hl_dec_a(cpu);
            return true;
        case LD_HL_n8:
            ld_hl_n8(cpu);
            return true;
        case LD_A_HL_DEC:
            ld_a_hl_dec(cpu);
            return true;
        case LD_A_n8:
            ld_a_n8(cpu);
            return true;
        case LD_B_B:
            ld_b_b(cpu);
            return true;
        case LD_B_C:
            ld_b_c(cpu);
            return true;
        case LD_B_D:
            ld_b_d(cpu);
            return true;
        case LD_B_E:
            ld_b_e(cpu);
            return true;
        case LD_B_H:
            ld_b_h(cpu);
            return true;
        case LD_B_L:
            ld_b_l(cpu);
            return true;
        case LD_B_HL:
            ld_b_hl(cpu);
            return true;
        case LD_B_A:
            ld_b_a(cpu);
            return true;
        case LD_C_B:
            ld_c_b(cpu);
            return true;
        case LD_C_C:
            ld_c_c(cpu);
            return true;
        case LD_C_D:
            ld_c_d(cpu);
            return true;
        case LD_C_E:
            ld_c_e(cpu);
            return true;
        case LD_C_H:
            ld_c_h(cpu);
            return true;
        case LD_C_L:
            ld_c_l(cpu);
            return true;
        case LD_C_HL:
            ld_c_hl(cpu);
            return true;
        case LD_C_A:
            ld_c_a(cpu);
            return true;
        case LD_D_B:
            ld_d_b(cpu);
            return true;
        case LD_D_C:
            ld_d_c(cpu);
            return true;
        case LD_D_D:
            ld_d_d(cpu);
            return true;
        case LD_D_E:
            ld_d_e(cpu);
            return true;
        case LD_D_H:
            ld_d_h(cpu);
            return true;
        case LD_D_L:
            ld_d_l(cpu);
            return true;
        case LD_D_HL:
            ld_d_hl(cpu);
            return true;
        case LD_D_A:
            ld_d_a(cpu);
            return true;
        case LD_E_B:
            ld_e_b(cpu);
            return true;
        case LD_E_C:
            ld_e_c(cpu);
            return true;
        case LD_E_D:
            ld_e_d(cpu);
            return true;
        case LD_E_E:
            ld_e_e(cpu);
            return true;
        case LD_E_H:    
            ld_e_h(cpu);
            return true;
        case LD_E_L:
            ld_e_l(cpu);
            return true;
        case LD_E_HL:
            ld_e_hl(cpu);
            return true;
        case LD_E_A:    
            ld_e_a(cpu);
            return true;
        case LD_H_B:
            ld_h_b(cpu);
            return true;
        case LD_H_C:
            ld_h_c(cpu);
            return true;
        case LD_H_D:
            ld_h_d(cpu);
            return true;
        case LD_H_E:
            ld_h_e(cpu);
            return true;
        case LD_H_H:
            ld_h_h(cpu);
            return true;
        case LD_H_L:  
            ld_h_l(cpu);
            return true;
        case LD_H_HL:
            ld_h_hl(cpu);
            return true;
        case LD_H_A:
            ld_h_a(cpu);
            return true;
        case LD_L_B:
            ld_l_b(cpu);
            return true;
        case LD_L_C:
            ld_l_c(cpu);
            return true;
        case LD_L_D:
            ld_l_d(cpu);
            return true;
        case LD_L_E:
            ld_l_e(cpu);
            return true;
        case LD_L_H:
            ld_l_h(cpu);
            return true;
        case LD_L_L:
            ld_l_l(cpu);
            return true;
        case LD_L_HL:
            ld_l_hl(cpu);
            return true;
        case LD_L_A:
            ld_l_a(cpu);
            return true;
        case LD_HL_B:
            ld_hl_b(cpu);
            return true;
        case LD_HL_C:
            ld_hl_c(cpu);
            return true;
        case LD_HL_D:
            ld_hl_d(cpu);
            return true;
        case LD_HL_E:
            ld_hl_e(cpu);
            return true;
        case LD_HL_H:
            ld_hl_h(cpu);
            return true;
        case LD_HL_L:
            ld_hl_l(cpu);
            return true;
        case LD_HL_A:
            ld_hl_a(cpu);
            return true;
        case LD_A_B:    
            ld_a_b(cpu);
            return true;
        case LD_A_C:    
            ld_a_c(cpu);
            return true;
        case LD_A_D:    
            ld_a_d(cpu);
            return true;
        case LD_A_E:
            ld_a_e(cpu);
            return true;
        case LD_A_H:
            ld_a_h(cpu);
            return true;
        case LD_A_L:
            ld_a_l(cpu);
            return true;
        case LD_A_HL:
            ld_a_hl(cpu);
            return true;
        case LD_A_A:
            ld_a_a(cpu);
            return true;
        default:
            return false; // Opcode not handled by EightBitLoadInstructionSet
    }
};

// Is this the best way to do this? It will be painful when we get to shifts!

void EightBitLoadInstructionSet::ld_bc_a(CPU& cpu) {
    // Placeholder for LD_BC_A functionality
    // Example: cpu.ld_bc_a();
}

void EightBitLoadInstructionSet::ld_b_n8(CPU& cpu) {
    // Placeholder for LD_B_n8 functionality
    // Example: cpu.ld_b_n8();
}

void EightBitLoadInstructionSet::ld_a_bc(CPU& cpu) {
    // Placeholder for LD_A_BC functionality
    // Example: cpu.ld_a_bc();
}

void EightBitLoadInstructionSet::ld_c_n8(CPU& cpu) {
    // Placeholder for LD_C_n8 functionality
    // Example: cpu.ld_c_n8();
}

void EightBitLoadInstructionSet::ld_de_a(CPU& cpu) {
    // Placeholder for LD_DE_A functionality
    // Example: cpu.ld_de_a();
}

void EightBitLoadInstructionSet::ld_d_n8(CPU& cpu) {
    // Placeholder for LD_D_n8 functionality
    // Example: cpu.ld_d_n8();
}

void EightBitLoadInstructionSet::ld_a_de(CPU& cpu) {
    // Placeholder for LD_A_DE functionality
    // Example: cpu.ld_a_de();
}

void EightBitLoadInstructionSet::ld_e_n8(CPU& cpu) {
    // Placeholder for LD_E_n8 functionality
    // Example: cpu.ld_e_n8();
}

void EightBitLoadInstructionSet::ld_hl_inc_a(CPU& cpu) {
    // Placeholder for LD_HL_INC_A functionality
    // Example: cpu.ld_hl_inc_a();
}

void EightBitLoadInstructionSet::ld_h_n8(CPU& cpu) {
    // Placeholder for LD_H_n8 functionality
    // Example: cpu.ld_h_n8();
}

void EightBitLoadInstructionSet::ld_a_hl_inc(CPU& cpu) {
    // Placeholder for LD_A_HL_INC functionality
    // Example: cpu.ld_a_hl_inc();
}

void EightBitLoadInstructionSet::ld_l_n8(CPU& cpu) {
    // Placeholder for LD_L_n8 functionality
    // Example: cpu.ld_l_n8();
}

void EightBitLoadInstructionSet::ld_hl_dec_a(CPU& cpu) {
    // Placeholder for LD_HL_DEC_A functionality
    // Example: cpu.ld_hl_dec_a();
}

void EightBitLoadInstructionSet::ld_hl_n8(CPU& cpu) {
    // Placeholder for LD_HL_n8 functionality
    // Example: cpu.ld_hl_n8();
}

void EightBitLoadInstructionSet::ld_a_hl_dec(CPU& cpu) {
    // Placeholder for LD_A_HL_DEC functionality
    // Example: cpu.ld_a_hl_dec();
}

void EightBitLoadInstructionSet::ld_a_n8(CPU& cpu) {
    // Placeholder for LD_A_n8 functionality
    // Example: cpu.ld_a_n8();
}

void EightBitLoadInstructionSet::ld_b_b(CPU& cpu) {
    // Placeholder for LD_B_B functionality
    // Example: cpu.ld_b_b();
}

void EightBitLoadInstructionSet::ld_b_c(CPU& cpu) {
    // Placeholder for LD_B_C functionality
    // Example: cpu.ld_b_c();
}

void EightBitLoadInstructionSet::ld_b_d(CPU& cpu) {
    // Placeholder for LD_B_D functionality
    // Example: cpu.ld_b_d();
}

void EightBitLoadInstructionSet::ld_b_e(CPU& cpu) {
    // Placeholder for LD_B_E functionality
    // Example: cpu.ld_b_e();
}

void EightBitLoadInstructionSet::ld_b_h(CPU& cpu) {
    // Placeholder for LD_B_H functionality
    // Example: cpu.ld_b_h();
}

void EightBitLoadInstructionSet::ld_b_l(CPU& cpu) {
    // Placeholder for LD_B_L functionality
    // Example: cpu.ld_b_l();
}

void EightBitLoadInstructionSet::ld_b_hl(CPU& cpu) {
    // Placeholder for LD_B_HL functionality
    // Example: cpu.ld_b_hl();
}

void EightBitLoadInstructionSet::ld_b_a(CPU& cpu) {
    // Placeholder for LD_B_A functionality
    // Example: cpu.ld_b_a();
}

void EightBitLoadInstructionSet::ld_c_b(CPU& cpu) {
    // Placeholder for LD_C_B functionality
    // Example: cpu.ld_c_b();
}

void EightBitLoadInstructionSet::ld_c_c(CPU& cpu) {
    // Placeholder for LD_C_C functionality
    // Example: cpu.ld_c_c();
}

void EightBitLoadInstructionSet::ld_c_d(CPU& cpu) {
    // Placeholder for LD_C_D functionality
    // Example: cpu.ld_c_d();
}

void EightBitLoadInstructionSet::ld_c_e(CPU& cpu) {
    // Placeholder for LD_C_E functionality
    // Example: cpu.ld_c_e();
}

void EightBitLoadInstructionSet::ld_c_h(CPU& cpu) {
    // Placeholder for LD_C_H functionality
    // Example: cpu.ld_c_h();
}

void EightBitLoadInstructionSet::ld_c_l(CPU& cpu) {
    // Placeholder for LD_C_L functionality
    // Example: cpu.ld_c_l();
}

void EightBitLoadInstructionSet::ld_c_hl(CPU& cpu) {
    // Placeholder for LD_C_HL functionality
    // Example: cpu.ld_c_hl();
}

void EightBitLoadInstructionSet::ld_c_a(CPU& cpu) {
    // Placeholder for LD_C_A functionality
    // Example: cpu.ld_c_a();
}

void EightBitLoadInstructionSet::ld_d_b(CPU& cpu) {
    // Placeholder for LD_D_B functionality
    // Example: cpu.ld_d_b();
}

void EightBitLoadInstructionSet::ld_d_c(CPU& cpu) {
    // Placeholder for LD_D_C functionality
    // Example: cpu.ld_d_c();
}

void EightBitLoadInstructionSet::ld_d_d(CPU& cpu) {
    // Placeholder for LD_D_D functionality
    // Example: cpu.ld_d_d();
}

void EightBitLoadInstructionSet::ld_d_e(CPU& cpu) {
    // Placeholder for LD_D_E functionality
    // Example: cpu.ld_d_e();
}

void EightBitLoadInstructionSet::ld_d_h(CPU& cpu) {
    // Placeholder for LD_D_H functionality
    // Example: cpu.ld_d_h();
}

void EightBitLoadInstructionSet::ld_d_l(CPU& cpu) {
    // Placeholder for LD_D_L functionality
    // Example: cpu.ld_d_l();
}

void EightBitLoadInstructionSet::ld_d_hl(CPU& cpu) {
    // Placeholder for LD_D_HL functionality
    // Example: cpu.ld_d_hl();
}

void EightBitLoadInstructionSet::ld_d_a(CPU& cpu) {
    // Placeholder for LD_D_A functionality
    // Example: cpu.ld_d_a();
}

void EightBitLoadInstructionSet::ld_e_b(CPU& cpu) {
    // Placeholder for LD_E_B functionality
    // Example: cpu.ld_e_b();
}

void EightBitLoadInstructionSet::ld_e_c(CPU& cpu) {
    // Placeholder for LD_E_C functionality
    // Example: cpu.ld_e_c();
}

void EightBitLoadInstructionSet::ld_e_d(CPU& cpu) {
    // Placeholder for LD_E_D functionality
    // Example: cpu.ld_e_d();
}

void EightBitLoadInstructionSet::ld_e_e(CPU& cpu) {
    // Placeholder for LD_E_E functionality
    // Example: cpu.ld_e_e();
}

void EightBitLoadInstructionSet::ld_e_h(CPU& cpu) {
    // Placeholder for LD_E_H functionality
    // Example: cpu.ld_e_h();
}

void EightBitLoadInstructionSet::ld_e_l(CPU& cpu) {
    // Placeholder for LD_E_L functionality
    // Example: cpu.ld_e_l();
}

void EightBitLoadInstructionSet::ld_e_hl(CPU& cpu) {
    // Placeholder for LD_E_HL functionality
    // Example: cpu.ld_e_hl();
}

void EightBitLoadInstructionSet::ld_e_a(CPU& cpu) {
    // Placeholder for LD_E_A functionality
    // Example: cpu.ld_e_a();
}

void EightBitLoadInstructionSet::ld_h_b(CPU& cpu) {
    // Placeholder for LD_H_B functionality
    // Example: cpu.ld_h_b();
}

void EightBitLoadInstructionSet::ld_h_c(CPU& cpu) {
    // Placeholder for LD_H_C functionality
    // Example: cpu.ld_h_c();
}

void EightBitLoadInstructionSet::ld_h_d(CPU& cpu) {
    // Placeholder for LD_H_D functionality
    // Example: cpu.ld_h_d();
}

void EightBitLoadInstructionSet::ld_h_e(CPU& cpu) {
    // Placeholder for LD_H_E functionality
    // Example: cpu.ld_h_e();
}

void EightBitLoadInstructionSet::ld_h_h(CPU& cpu) {
    // Placeholder for LD_H_H functionality
    // Example: cpu.ld_h_h();
}

void EightBitLoadInstructionSet::ld_h_l(CPU& cpu) {
    // Placeholder for LD_H_L functionality
    // Example: cpu.ld_h_l();
}

void EightBitLoadInstructionSet::ld_h_hl(CPU& cpu) {
    // Placeholder for LD_H_HL functionality
    // Example: cpu.ld_h_hl();
}

void EightBitLoadInstructionSet::ld_h_a(CPU& cpu) {
    // Placeholder for LD_H_A functionality
    // Example: cpu.ld_h_a();
}

void EightBitLoadInstructionSet::ld_l_b(CPU& cpu) {
    // Placeholder for LD_L_B functionality
    // Example: cpu.ld_l_b();
}

void EightBitLoadInstructionSet::ld_l_c(CPU& cpu) {
    // Placeholder for LD_L_C functionality
    // Example: cpu.ld_l_c();
}

void EightBitLoadInstructionSet::ld_l_d(CPU& cpu) {
    // Placeholder for LD_L_D functionality
    // Example: cpu.ld_l_d();
}

void EightBitLoadInstructionSet::ld_l_e(CPU& cpu) {
    // Placeholder for LD_L_E functionality
    // Example: cpu.ld_l_e();
}

void EightBitLoadInstructionSet::ld_l_h(CPU& cpu) {
    // Placeholder for LD_L_H functionality
    // Example: cpu.ld_l_h();
}

void EightBitLoadInstructionSet::ld_l_l(CPU& cpu) {
    // Placeholder for LD_L_L functionality
    // Example: cpu.ld_l_l();
}

void EightBitLoadInstructionSet::ld_l_hl(CPU& cpu) {
    // Placeholder for LD_L_HL functionality
    // Example: cpu.ld_l_hl();
}

void EightBitLoadInstructionSet::ld_l_a(CPU& cpu) {
    // Placeholder for LD_L_A functionality
    // Example: cpu.ld_l_a();
}

void EightBitLoadInstructionSet::ld_hl_b(CPU& cpu) {
    // Placeholder for LD_HL_B functionality
    // Example: cpu.ld_hl_b();
}

void EightBitLoadInstructionSet::ld_hl_c(CPU& cpu) {
    // Placeholder for LD_HL_C functionality
    // Example: cpu.ld_hl_c();
}

void EightBitLoadInstructionSet::ld_hl_d(CPU& cpu) {
    // Placeholder for LD_HL_D functionality
    // Example: cpu.ld_hl_d();
}

void EightBitLoadInstructionSet::ld_hl_e(CPU& cpu) {
    // Placeholder for LD_HL_E functionality
    // Example: cpu.ld_hl_e();
}

void EightBitLoadInstructionSet::ld_hl_h(CPU& cpu) {
    // Placeholder for LD_HL_H functionality
    // Example: cpu.ld_hl_h();
}

void EightBitLoadInstructionSet::ld_hl_l(CPU& cpu) {
    // Placeholder for LD_HL_L functionality
    // Example: cpu.ld_hl_l();
}

void EightBitLoadInstructionSet::ld_hl_a(CPU& cpu) {
    // Placeholder for LD_HL_A functionality
    // Example: cpu.ld_hl_a();
}

void EightBitLoadInstructionSet::ld_a_b(CPU& cpu) {
    // Placeholder for LD_A_B functionality
    // Example: cpu.ld_a_b();
}

void EightBitLoadInstructionSet::ld_a_c(CPU& cpu) {
    // Placeholder for LD_A_C functionality
    // Example: cpu.ld_a_c();
}

void EightBitLoadInstructionSet::ld_a_d(CPU& cpu) {
    // Placeholder for LD_A_D functionality
    // Example: cpu.ld_a_d();
}

void EightBitLoadInstructionSet::ld_a_e(CPU& cpu) {
    // Placeholder for LD_A_E functionality
    // Example: cpu.ld_a_e();
}

void EightBitLoadInstructionSet::ld_a_h(CPU& cpu) {
    // Placeholder for LD_A_H functionality
    // Example: cpu.ld_a_h();
}

void EightBitLoadInstructionSet::ld_a_l(CPU& cpu) {
    // Placeholder for LD_A_L functionality
    // Example: cpu.ld_a_l();
}

void EightBitLoadInstructionSet::ld_a_hl(CPU& cpu) {
    // Placeholder for LD_A_HL functionality
    // Example: cpu.ld_a_hl();
}

void EightBitLoadInstructionSet::ld_a_a(CPU& cpu) {
    // Placeholder for LD_A_A functionality
    // Example: cpu.ld_a_a();
}

void EightBitLoadInstructionSet::ldh_a8_a(CPU& cpu) {
    // Placeholder for LDH_A8_A functionality
    // Example: cpu.ldh_a8_a();
}

void EightBitLoadInstructionSet::ld__c_a(CPU& cpu) {
    // Placeholder for LD__C_A functionality
    // Example: cpu.ld__c_a();
}

void EightBitLoadInstructionSet::ld_a16_a(CPU& cpu) {
    // Placeholder for LD_A16_A functionality
    // Example: cpu.ld_a16_a();
}

void EightBitLoadInstructionSet::ldh_a_a8(CPU& cpu) {
    // Placeholder for LDH_A_A8 functionality
    // Example: cpu.ldh_a_a8();
}

void EightBitLoadInstructionSet::ld_a__c(CPU& cpu) {
    // Placeholder for LD_A__C functionality
    // Example: cpu.ld_a__c();
}

void EightBitLoadInstructionSet::ld_a_a16(CPU& cpu) {
    // Placeholder for LD_A_A16 functionality
    // Example: cpu.ld_a_a16();
}