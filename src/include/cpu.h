#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdint.h>
#include <unordered_map>
#include <functional>
#include "bus.h"

#define Z 7;
#define N 6;
#define H 5;
#define C 4;

// TO BE REMOVED -- THIS IS SO EVERYTHING CAN STILL WORK
#define FLAG_ZERO 0b10000000
#define FLAG_SUBTRACT 0b01000000
#define FLAG_HALF_CARRY 0b00100000
#define FLAG_CARRY 0b00010000

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits
using InstructionHandler = std::function<void(InstructionContext)>;

typedef struct {
    CPU* cpu;
    Byte* reg;
    bool bit;
} InstructionContext;

typedef struct {
    Word program_counter;
    Word stack_pointer;

    // Special purpose registers
    Byte instruction_register;
    Byte interrupt_enable;
    Byte a_register; // Accumulator
    Byte flag_register; // Four least-significant bits will ALWAYS be zero.

    // General purpose registers
    Byte b_register;
    Byte c_register;
    Byte d_register;
    Byte e_register;
    Byte h_register; // High register
    Byte l_register; // Low register

    // TO BE REMOVED -- THIS IS SO EVERYTHING CAN STILL WORK
    void set_flag(Byte flag, bool value) {
        if (value) {
            set_bit(flag_register, flag);
        } else {
            res_bit(flag_register, flag);
        }
    }

    Word get_pair(Byte high, Byte low) {
        return (high << 8) | low;
    }

    void set_pair(Word value, Byte& high, Byte& low) {
        high = (value & 0xFF00) >> 8;
        low = value & 0x00FF;
    }

    bool get_bit(Byte reg, Byte bit) {
        return (reg >> bit) & 1;
    }

    void set_bit(Byte& reg, Byte bit) {
        reg |= (1 << bit);
    }

    void res_bit(Byte& reg, Byte bit) {
        reg &= ~(1 << bit);
    }
} Registers;

class CPU {
public:
    Registers registers;
    Bus bus;

    CPU(Bus& bus);
    void reset();
    void cycle();
    void write(Word address, Byte data);
    Byte read(Word address);

    void initializeInstructionTable();
    bool executeInstruction(Word opcode);

private:
    std::unordered_map<Word, InstructionHandler> instructionTable;
};

#endif // CPU_H
