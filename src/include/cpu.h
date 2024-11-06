#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdint.h>
#include "bus.h"

#define FLAG_ZER0 0b10000000
#define FLAG_SUBTRACT 0b01000000
#define FLAG_HALF_CARRY 0b00100000
#define FLAG_CARRY 0b00010000

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

typedef struct {
    Word program_counter;
    Word stack_pointer;

    // Special purpose registers
    Byte instruction_register;
    Byte interrupt_enable;

    // General purpose registers
    Byte a_register;
    Byte flag_register; // Four least-significant bits will ALWAYS be zero.
    Byte bc_registers[2];
    Byte de_registers[2];
    Byte hl_registers[2];

    void set_flag(Byte flag, bool value) {
        if (value) {
            flag_register |= flag;
        } else {
            flag_register &= ~flag;
        }
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
};

#endif // CPU_H
