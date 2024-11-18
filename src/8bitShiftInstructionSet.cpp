#include "include/8bitShiftInstructionSet.h"

void EightBitShiftInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x07, [this, &cpu] { this->rlca(cpu); });
    cpu.addInstruction(0x0F, [this, &cpu] { this->rrca(cpu); });
    cpu.addInstruction(0x17, [this, &cpu] { this->rla(cpu); });
    cpu.addInstruction(0x1F, [this, &cpu] { this->rra(cpu); });
    cpu.addInstruction(0xCB00, [this, &cpu] { this->rlc_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB01, [this, &cpu] { this->rlc_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB02, [this, &cpu] { this->rlc_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB03, [this, &cpu] { this->rlc_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB04, [this, &cpu] { this->rlc_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB05, [this, &cpu] { this->rlc_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB06, [this, &cpu] { this->rlc_hl_indirect(cpu); });
    cpu.addInstruction(0xCB07, [this, &cpu] { this->rlc_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB08, [this, &cpu] { this->rrc_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB09, [this, &cpu] { this->rrc_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB0A, [this, &cpu] { this->rrc_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB0B, [this, &cpu] { this->rrc_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB0C, [this, &cpu] { this->rrc_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB0D, [this, &cpu] { this->rrc_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB0E, [this, &cpu] { this->rrc_hl_indirect(cpu); });
    cpu.addInstruction(0xCB0F, [this, &cpu] { this->rrc_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB10, [this, &cpu] { this->rl_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB11, [this, &cpu] { this->rl_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB12, [this, &cpu] { this->rl_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB13, [this, &cpu] { this->rl_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB14, [this, &cpu] { this->rl_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB15, [this, &cpu] { this->rl_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB16, [this, &cpu] { this->rl_hl_indirect(cpu); });
    cpu.addInstruction(0xCB17, [this, &cpu] { this->rl_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB18, [this, &cpu] { this->rr_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB19, [this, &cpu] { this->rr_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB1A, [this, &cpu] { this->rr_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB1B, [this, &cpu] { this->rr_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB1C, [this, &cpu] { this->rr_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB1D, [this, &cpu] { this->rr_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB1E, [this, &cpu] { this->rr_hl_indirect(cpu); });
    cpu.addInstruction(0xCB1F, [this, &cpu] { this->rr_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB20, [this, &cpu] { this->sla_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB21, [this, &cpu] { this->sla_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB22, [this, &cpu] { this->sla_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB23, [this, &cpu] { this->sla_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB24, [this, &cpu] { this->sla_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB25, [this, &cpu] { this->sla_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB26, [this, &cpu] { this->sla_hl_indirect(cpu); });
    cpu.addInstruction(0xCB27, [this, &cpu] { this->sla_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB28, [this, &cpu] { this->sra_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB29, [this, &cpu] { this->sra_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB2A, [this, &cpu] { this->sra_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB2B, [this, &cpu] { this->sra_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB2C, [this, &cpu] { this->sra_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB2D, [this, &cpu] { this->sra_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB2E, [this, &cpu] { this->sra_hl_indirect(cpu); });
    cpu.addInstruction(0xCB2F, [this, &cpu] { this->sra_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB30, [this, &cpu] { this->swap_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB31, [this, &cpu] { this->swap_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB32, [this, &cpu] { this->swap_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB33, [this, &cpu] { this->swap_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB34, [this, &cpu] { this->swap_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB35, [this, &cpu] { this->swap_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB36, [this, &cpu] { this->swap_hl_indirect(cpu); });
    cpu.addInstruction(0xCB37, [this, &cpu] { this->swap_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB38, [this, &cpu] { this->srl_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB39, [this, &cpu] { this->srl_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB3A, [this, &cpu] { this->srl_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB3B, [this, &cpu] { this->srl_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB3C, [this, &cpu] { this->srl_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB3D, [this, &cpu] { this->srl_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB3E, [this, &cpu] { this->srl_hl_indirect(cpu); });
    cpu.addInstruction(0xCB3F, [this, &cpu] { this->srl_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB40, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB41, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB42, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB43, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB44, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB45, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB46, [this, &cpu] { this->bit_n_hl_indirect(0, cpu); });
    cpu.addInstruction(0xCB47, [this, &cpu] { this->bit_n_r(0, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB48, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB49, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB4A, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB4B, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB4C, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB4D, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB4E, [this, &cpu] { this->bit_n_hl_indirect(1, cpu); });
    cpu.addInstruction(0xCB4F, [this, &cpu] { this->bit_n_r(1, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB50, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB51, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB52, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB53, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB54, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB55, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB56, [this, &cpu] { this->bit_n_hl_indirect(2, cpu); });
    cpu.addInstruction(0xCB57, [this, &cpu] { this->bit_n_r(2, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB58, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB59, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB5A, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB5B, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB5C, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB5D, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB5E, [this, &cpu] { this->bit_n_hl_indirect(3, cpu); });
    cpu.addInstruction(0xCB5F, [this, &cpu] { this->bit_n_r(3, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB60, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB61, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB62, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB63, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB64, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB65, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB66, [this, &cpu] { this->bit_n_hl_indirect(4, cpu); });
    cpu.addInstruction(0xCB67, [this, &cpu] { this->bit_n_r(4, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB68, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB69, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB6A, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB6B, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB6C, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB6D, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB6E, [this, &cpu] { this->bit_n_hl_indirect(5, cpu); });
    cpu.addInstruction(0xCB6F, [this, &cpu] { this->bit_n_r(5, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB70, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB71, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB72, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB73, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB74, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB75, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB76, [this, &cpu] { this->bit_n_hl_indirect(6, cpu); });
    cpu.addInstruction(0xCB77, [this, &cpu] { this->bit_n_r(6, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB78, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB79, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB7A, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB7B, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB7C, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB7D, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB7E, [this, &cpu] { this->bit_n_hl_indirect(7, cpu); });
    cpu.addInstruction(0xCB7F, [this, &cpu] { this->bit_n_r(7, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB80, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB81, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB82, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB83, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB84, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB85, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB86, [this, &cpu] { this->res_n_hl_indirect(0, cpu); });
    cpu.addInstruction(0xCB87, [this, &cpu] { this->res_n_r(0, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB88, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB89, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB8A, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB8B, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB8C, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB8D, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB8E, [this, &cpu] { this->res_n_hl_indirect(1, cpu); });
    cpu.addInstruction(0xCB8F, [this, &cpu] { this->res_n_r(1, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB90, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB91, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB92, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB93, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB94, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB95, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB96, [this, &cpu] { this->res_n_hl_indirect(2, cpu); });
    cpu.addInstruction(0xCB97, [this, &cpu] { this->res_n_r(2, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCB98, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCB99, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCB9A, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCB9B, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCB9C, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCB9D, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCB9E, [this, &cpu] { this->res_n_hl_indirect(3, cpu); });
    cpu.addInstruction(0xCB9F, [this, &cpu] { this->res_n_r(3, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBA0, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBA1, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBA2, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBA3, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBA4, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBA5, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBA6, [this, &cpu] { this->res_n_hl_indirect(4, cpu); });
    cpu.addInstruction(0xCBA7, [this, &cpu] { this->res_n_r(4, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBA8, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBA9, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBAA, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBAB, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBAC, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBAD, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBAE, [this, &cpu] { this->res_n_hl_indirect(5, cpu); });
    cpu.addInstruction(0xCBAF, [this, &cpu] { this->res_n_r(5, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBB0, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBB1, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBB2, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBB3, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBB4, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBB5, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBB6, [this, &cpu] { this->res_n_hl_indirect(6, cpu); });
    cpu.addInstruction(0xCBB7, [this, &cpu] { this->res_n_r(6, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBB8, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBB9, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBBA, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBBB, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBBC, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBBD, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBBE, [this, &cpu] { this->res_n_hl_indirect(7, cpu); });
    cpu.addInstruction(0xCBBF, [this, &cpu] { this->res_n_r(7, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBC0, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBC1, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBC2, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBC3, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBC4, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBC5, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBC6, [this, &cpu] { this->set_n_hl_indirect(0, cpu); });
    cpu.addInstruction(0xCBC7, [this, &cpu] { this->set_n_r(0, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBC8, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBC9, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBCA, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBCB, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBCC, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBCD, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBCE, [this, &cpu] { this->set_n_hl_indirect(1, cpu); });
    cpu.addInstruction(0xCBCF, [this, &cpu] { this->set_n_r(1, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBD0, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBD1, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBD2, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBD3, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBD4, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBD5, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBD6, [this, &cpu] { this->set_n_hl_indirect(2, cpu); });
    cpu.addInstruction(0xCBD7, [this, &cpu] { this->set_n_r(2, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBD8, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBD9, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBDA, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBDB, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBDC, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBDD, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBDE, [this, &cpu] { this->set_n_hl_indirect(3, cpu); });
    cpu.addInstruction(0xCBDF, [this, &cpu] { this->set_n_r(3, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBE0, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBE1, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBE2, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBE3, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBE4, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBE5, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBE6, [this, &cpu] { this->set_n_hl_indirect(4, cpu); });
    cpu.addInstruction(0xCBE7, [this, &cpu] { this->set_n_r(4, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBE8, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBE9, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBEA, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBEB, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBEC, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBED, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBEE, [this, &cpu] { this->set_n_hl_indirect(5, cpu); });
    cpu.addInstruction(0xCBEF, [this, &cpu] { this->set_n_r(5, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBF0, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBF1, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBF2, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBF3, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBF4, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBF5, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBF6, [this, &cpu] { this->set_n_hl_indirect(6, cpu); });
    cpu.addInstruction(0xCBF7, [this, &cpu] { this->set_n_r(6, cpu, cpu.registers.a); });
    cpu.addInstruction(0xCBF8, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.b); });
    cpu.addInstruction(0xCBF9, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.c); });
    cpu.addInstruction(0xCBFA, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.d); });
    cpu.addInstruction(0xCBFB, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.e); });
    cpu.addInstruction(0xCBFC, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.h); });
    cpu.addInstruction(0xCBFD, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.l); });
    cpu.addInstruction(0xCBFE, [this, &cpu] { this->set_n_hl_indirect(7, cpu); });
    cpu.addInstruction(0xCBFF, [this, &cpu] { this->set_n_r(7, cpu, cpu.registers.a); });
}

void EightBitShiftInstructionSet::rrca(CPU& cpu) {
    bool lsb = cpu.getBit(cpu.registers.a, 0);
    cpu.registers.a = cpu.registers.a >> 1;
    cpu.registers.a = cpu.registers.a | (lsb << 7);

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, lsb);
}

void EightBitShiftInstructionSet::rlca(CPU& cpu) {
    bool msb = cpu.registers.a >> 7;
    cpu.registers.a = cpu.registers.a << 1;
    cpu.registers.a = cpu.registers.a | msb;

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, msb);
}

void EightBitShiftInstructionSet::rra(CPU& cpu) {
    bool carry = cpu.getBit(cpu.registers.f, C);
    bool lsb = cpu.getBit(cpu.registers.a, 0);
    cpu.registers.a = cpu.registers.a >> 1;
    cpu.registers.a = cpu.registers.a | (carry << 7);

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, lsb);
}

void EightBitShiftInstructionSet::rla(CPU& cpu) {
    bool carry = cpu.getBit(cpu.registers.f, C);
    bool msb = cpu.registers.a >> 7;
    cpu.registers.a = cpu.registers.a << 1;
    cpu.registers.a = cpu.registers.a | carry;

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, msb);
}

void EightBitShiftInstructionSet::rlc_r(CPU& cpu, Byte& reg) {
    bool msb = reg >> 7;
    reg = reg << 1;
    reg = reg | msb;
    
    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, msb);
}

void EightBitShiftInstructionSet::rlc_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    rlc_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::rrc_r(CPU& cpu, Byte& reg) {
    bool lsb = cpu.getBit(reg, 0);
    reg = reg >> 1;
    reg = reg | (lsb << 7);

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, lsb);
}

void EightBitShiftInstructionSet::rrc_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    rrc_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::rl_r(CPU& cpu, Byte& reg) {
    bool carry = cpu.getBit(cpu.registers.f, C);
    bool msb = reg >> 7;
    reg = reg << 1;
    reg = reg | carry;

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, msb);
}

void EightBitShiftInstructionSet::rl_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    rl_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::rr_r(CPU& cpu, Byte& reg) {
    bool carry = cpu.getBit(cpu.registers.f, C);
    bool lsb = cpu.getBit(reg, 0);
    reg = reg >> 1;
    reg = reg | (carry << 7);

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, lsb);
}

void EightBitShiftInstructionSet::rr_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    rr_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::sla_r(CPU& cpu, Byte& reg) {
    bool msb = reg >> 7;
    reg = reg << 1;

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, msb);
}

void EightBitShiftInstructionSet::sla_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    sla_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::sra_r(CPU& cpu, Byte& reg) {
    bool lsb = cpu.getBit(reg, 0);
    bool msb = reg >> 7;
    reg = reg >> 1;
    reg = reg | (msb << 7);

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, lsb);
}

void EightBitShiftInstructionSet::sra_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    sra_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::swap_r(CPU& cpu, Byte& reg) {
    reg = (reg >> 4) | (reg << 4);

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, 0);
}

void EightBitShiftInstructionSet::swap_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    swap_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::srl_r(CPU& cpu, Byte& reg) {
    bool lsb = cpu.getBit(reg, 0);
    reg = reg >> 1;

    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 0);
    cpu.setBit(cpu.registers.f, C, lsb);
}

void EightBitShiftInstructionSet::srl_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    srl_r(cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::bit_n_r(uint8_t n, CPU& cpu, Byte& reg) {
    cpu.setBit(cpu.registers.f, Z, cpu.getBit(reg, n));
    cpu.setBit(cpu.registers.f, N, 0);
    cpu.setBit(cpu.registers.f, H, 1);
}

void EightBitShiftInstructionSet::bit_n_hl_indirect(uint8_t n, CPU& cpu) {
    Byte data = cpu.readPair(HL);
    bit_n_r(n, cpu, data);
}

void EightBitShiftInstructionSet::set_n_r(uint8_t n, CPU& cpu, Byte& reg) {
    cpu.setBit(reg, n, 1);
}

void EightBitShiftInstructionSet::set_n_hl_indirect(uint8_t n, CPU& cpu) {
    Byte data = cpu.readPair(HL);
    set_n_r(n, cpu, data);
    cpu.writePair(HL, data);
}

void EightBitShiftInstructionSet::res_n_r(uint8_t n, CPU& cpu, Byte& reg) {
    cpu.setBit(reg, n, 0);
}

void EightBitShiftInstructionSet::res_n_hl_indirect(uint8_t n, CPU& cpu) {
    Byte data = cpu.readPair(HL);
    res_n_r(n, cpu, data);
    cpu.writePair(HL, data);
}