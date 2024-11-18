#include "include/8bitALUInstructionSet.h"

void EightBitALUInstructionSet::initializeInstructionTable(CPU& cpu) {
    cpu.addInstruction(0x04, [this, &cpu] { inc_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x05, [this, &cpu] { dec_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x0C, [this, &cpu] { inc_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x0D, [this, &cpu] { dec_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x14, [this, &cpu] { inc_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x15, [this, &cpu] { dec_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x1C, [this, &cpu] { inc_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x1D, [this, &cpu] { dec_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x24, [this, &cpu] { inc_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x25, [this, &cpu] { dec_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x27, [this, &cpu] { daa(cpu); });
    cpu.addInstruction(0x2C, [this, &cpu] { inc_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x2D, [this, &cpu] { dec_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x2F, [this, &cpu] { cpl(cpu); });
    cpu.addInstruction(0x34, [this, &cpu] { inc_hl_indirect(cpu); });
    cpu.addInstruction(0x35, [this, &cpu] { dec_hl_indirect(cpu); });
    cpu.addInstruction(0x37, [this, &cpu] { scf(cpu); });
    cpu.addInstruction(0x3C, [this, &cpu] { inc_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0x3D, [this, &cpu] { dec_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0x3F, [this, &cpu] { ccf(cpu); });
    cpu.addInstruction(0x80, [this, &cpu] { add_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x81, [this, &cpu] { add_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x82, [this, &cpu] { add_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x83, [this, &cpu] { add_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x84, [this, &cpu] { add_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x85, [this, &cpu] { add_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x86, [this, &cpu] { add_hl_indirect(cpu); });
    cpu.addInstruction(0x87, [this, &cpu] { add_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0x88, [this, &cpu] { adc_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x89, [this, &cpu] { adc_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x8A, [this, &cpu] { adc_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x8B, [this, &cpu] { adc_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x8C, [this, &cpu] { adc_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x8D, [this, &cpu] { adc_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x8E, [this, &cpu] { adc_hl_indirect(cpu); });
    cpu.addInstruction(0x8F, [this, &cpu] { adc_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0x90, [this, &cpu] { sub_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x91, [this, &cpu] { sub_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x92, [this, &cpu] { sub_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x93, [this, &cpu] { sub_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x94, [this, &cpu] { sub_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x95, [this, &cpu] { sub_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x96, [this, &cpu] { sub_hl_indirect(cpu); });
    cpu.addInstruction(0x97, [this, &cpu] { sub_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0x98, [this, &cpu] { sbc_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0x99, [this, &cpu] { sbc_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0x9A, [this, &cpu] { sbc_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0x9B, [this, &cpu] { sbc_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0x9C, [this, &cpu] { sbc_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0x9D, [this, &cpu] { sbc_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0x9E, [this, &cpu] { sbc_hl_indirect(cpu); });
    cpu.addInstruction(0x9F, [this, &cpu] { sbc_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xA0, [this, &cpu] { and_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xA1, [this, &cpu] { and_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xA2, [this, &cpu] { and_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xA3, [this, &cpu] { and_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xA4, [this, &cpu] { and_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xA5, [this, &cpu] { and_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xA6, [this, &cpu] { and_hl_indirect(cpu); });
    cpu.addInstruction(0xA7, [this, &cpu] { and_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xA8, [this, &cpu] { xor_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xA9, [this, &cpu] { xor_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xAA, [this, &cpu] { xor_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xAB, [this, &cpu] { xor_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xAC, [this, &cpu] { xor_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xAD, [this, &cpu] { xor_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xAE, [this, &cpu] { xor_hl_indirect(cpu); });
    cpu.addInstruction(0xAF, [this, &cpu] { xor_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xB0, [this, &cpu] { or_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xB1, [this, &cpu] { or_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xB2, [this, &cpu] { or_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xB3, [this, &cpu] { or_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xB4, [this, &cpu] { or_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xB5, [this, &cpu] { or_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xB6, [this, &cpu] { or_hl_indirect(cpu); });
    cpu.addInstruction(0xB7, [this, &cpu] { or_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xB8, [this, &cpu] { cp_r(cpu, cpu.registers.b); });
    cpu.addInstruction(0xB9, [this, &cpu] { cp_r(cpu, cpu.registers.c); });
    cpu.addInstruction(0xBA, [this, &cpu] { cp_r(cpu, cpu.registers.d); });
    cpu.addInstruction(0xBB, [this, &cpu] { cp_r(cpu, cpu.registers.e); });
    cpu.addInstruction(0xBC, [this, &cpu] { cp_r(cpu, cpu.registers.h); });
    cpu.addInstruction(0xBD, [this, &cpu] { cp_r(cpu, cpu.registers.l); });
    cpu.addInstruction(0xBE, [this, &cpu] { cp_hl_indirect(cpu); });
    cpu.addInstruction(0xBF, [this, &cpu] { cp_r(cpu, cpu.registers.a); });
    cpu.addInstruction(0xC6, [this, &cpu] { add_n8(cpu); });
    cpu.addInstruction(0xCE, [this, &cpu] { adc_n8(cpu); });
    cpu.addInstruction(0xD6, [this, &cpu] { sub_n8(cpu); });
    cpu.addInstruction(0xDE, [this, &cpu] { sbc_n8(cpu); });
    cpu.addInstruction(0xE6, [this, &cpu] { and_n8(cpu); });
    cpu.addInstruction(0xEE, [this, &cpu] { xor_n8(cpu); });
    cpu.addInstruction(0xF6, [this, &cpu] { or_n8(cpu); });
    cpu.addInstruction(0xFE, [this, &cpu] { cp_n8(cpu); });
}

void EightBitALUInstructionSet::inc_r(CPU& cpu, Byte& reg) {
    reg++; // Increment register
    cpu.setBit(cpu.registers.f, Z, reg == 0); // Set zero flag if register is zero
    cpu.setBit(cpu.registers.f, N, false); // Reset subtract flag
    cpu.setBit(cpu.registers.f, H, reg & 0x08); // Set half carry flag if there is a carry from the 4th bit
}

void EightBitALUInstructionSet::dec_r(CPU& cpu, Byte& reg) {
    reg--; // Decrement register
    cpu.setBit(cpu.registers.f, Z, reg == 0);
    cpu.setBit(cpu.registers.f, N, true); 
    cpu.setBit(cpu.registers.f, H, reg & 0x08);
}

void EightBitALUInstructionSet::daa(CPU& cpu) {
    // DAA arithmetic operation was hardcoded into the gameboy. I don't exactly know how this works.
    // Source - https://ehaskins.com/2018-01-30%20Z80%20DAA/

    Byte a = cpu.registers.a; 

    if (cpu.getBit(cpu.registers.f, N)) { // if n
        if (cpu.getBit(cpu.registers.f, H) || (a & 0x0F) > 0x09) {
            a = (a - 0x06) & 0xFF;
        }

        if (cpu.getBit(cpu.registers.f, C) || a > 0x99) {
            a = (a - 0x60) & 0xFF;
        }
    } else { // if not n
        if ((a & 0x0F) > 0x09 || cpu.getBit(cpu.registers.f, H)) {
            a += 0x06;
        }

        if (a > 0x99 || cpu.getBit(cpu.registers.f, C)) {
            cpu.setBit(cpu.registers.f, C, true);
            a += 0x60;
        }
    }

    cpu.setBit(cpu.registers.f, Z, a == 0);
    cpu.setBit(cpu.registers.f, H, false);
}

void EightBitALUInstructionSet::cpl(CPU& cpu) {
    cpu.registers.a = ~cpu.registers.a;
    cpu.setBit(cpu.registers.f, N, true);
    cpu.setBit(cpu.registers.f, H, true);
}

void EightBitALUInstructionSet::inc_hl_indirect(CPU& cpu) {
    // hl is a 16-bit register with two eight bit elements, so we shift the first element 8 bits to the left and OR it with the second element to get the 16 bit address
    Byte data = cpu.readPair(HL);
    data++; // Increment data

    cpu.writePair(HL, data);

    cpu.setBit(cpu.registers.f, Z, data == 0);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, data & 0x08);
}

void EightBitALUInstructionSet::dec_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    data--; // Increment data

    cpu.writePair(HL, data); // address, data

    cpu.setBit(cpu.registers.f, Z, data == 0);
    cpu.setBit(cpu.registers.f, N, true);
    cpu.setBit(cpu.registers.f, H, data & 0x08);
}

void EightBitALUInstructionSet::scf(CPU& cpu) {
    // Set carry flag
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, false);
    cpu.setBit(cpu.registers.f, C, true);
}

void EightBitALUInstructionSet::ccf(CPU& cpu) {
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, false);
    cpu.setBit(cpu.registers.f, C, !cpu.getBit(cpu.registers.f, C));
}

void EightBitALUInstructionSet::add_r(CPU& cpu, Byte& reg) {
    Byte result = cpu.registers.a + reg;
    cpu.registers.a = result;

    cpu.setBit(cpu.registers.f, Z, result == 0);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, result & 0x08);
    cpu.setBit(cpu.registers.f, C, result & 0x80);
}

void EightBitALUInstructionSet::add_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    add_r(cpu, data);
}

void EightBitALUInstructionSet::adc_r(CPU& cpu, Byte& reg) {
    bool carry = cpu.getBit(cpu.registers.f, C);
    Byte result = cpu.registers.a + carry;
    cpu.registers.a = result;

    cpu.setBit(cpu.registers.f, Z, result == 0);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, result & 0x08);
    cpu.setBit(cpu.registers.f, C, result & 0x80); 
}

void EightBitALUInstructionSet::adc_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    adc_r(cpu, data);
}

void EightBitALUInstructionSet::sub_r(CPU& cpu, Byte& reg) {
    Byte result = cpu.registers.a - reg;
    cpu.registers.a = result;

    cpu.setBit(cpu.registers.f, Z, result == 0);
    cpu.setBit(cpu.registers.f, N, true);
    cpu.setBit(cpu.registers.f, H, result & 0x08);
    cpu.setBit(cpu.registers.f, C, result & 0x80);
}

void EightBitALUInstructionSet::sub_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    sub_r(cpu, data);
}

void EightBitALUInstructionSet::sbc_r(CPU& cpu, Byte& reg) {
    bool carry = cpu.getBit(cpu.registers.f, C);
    Byte result = cpu.registers.a - reg - carry;
    cpu.registers.a = result;

    cpu.setBit(cpu.registers.f, Z, result == 0);
    cpu.setBit(cpu.registers.f, N, true);
    cpu.setBit(cpu.registers.f, H, result & 0x08);
    cpu.setBit(cpu.registers.f, C, result & 0x80);
}

void EightBitALUInstructionSet::sbc_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    sbc_r(cpu, data);
}

void EightBitALUInstructionSet::and_r(CPU& cpu, Byte& reg) {
    cpu.registers.a &= reg;

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, true);
    cpu.setBit(cpu.registers.f, C, false);
}

void EightBitALUInstructionSet::and_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    and_r(cpu, data);
}

void EightBitALUInstructionSet::xor_r(CPU& cpu, Byte& reg) {
    cpu.registers.a ^= reg;

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, false);
    cpu.setBit(cpu.registers.f, C, false);
}

void EightBitALUInstructionSet::xor_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    xor_r(cpu, data);
}

void EightBitALUInstructionSet::or_r(CPU& cpu, Byte& reg) {
    cpu.registers.a |= reg;

    cpu.setBit(cpu.registers.f, Z, cpu.registers.a == 0);
    cpu.setBit(cpu.registers.f, N, false);
    cpu.setBit(cpu.registers.f, H, false);
    cpu.setBit(cpu.registers.f, C, false);
}

void EightBitALUInstructionSet::or_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    or_r(cpu, data);
}

void EightBitALUInstructionSet::cp_r(CPU& cpu, Byte& reg) {
    Byte result = cpu.registers.a - reg;

    cpu.setBit(cpu.registers.f, Z, result == 0);
    cpu.setBit(cpu.registers.f, N, true);
    cpu.setBit(cpu.registers.f, H, result & 0x08);
    cpu.setBit(cpu.registers.f, C, result & 0x80);
}

void EightBitALUInstructionSet::cp_hl_indirect(CPU& cpu) {
    Byte data = cpu.readPair(HL);
    cp_r(cpu, data);
}

void EightBitALUInstructionSet::add_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    add_r(cpu, data);
}

void EightBitALUInstructionSet::sub_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    sub_r(cpu, data);
}

void EightBitALUInstructionSet::adc_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    adc_r(cpu, data);
}

void EightBitALUInstructionSet::sbc_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    sbc_r(cpu, data);
}

void EightBitALUInstructionSet::and_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    and_r(cpu, data);
}

void EightBitALUInstructionSet::xor_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    xor_r(cpu, data);
}

void EightBitALUInstructionSet::or_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    or_r(cpu, data);
}

void EightBitALUInstructionSet::cp_n8(CPU& cpu) {
    Byte data = cpu.fetchPC();
    cp_r(cpu, data);
}