#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdint.h>
#include "bus.h"

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
} Registers;

class CPU {
    public:
        Registers registers;
        Bus bus;

        CPU(Bus& bus) : bus(bus) {
        }

        void reset() {
        }

        void cycle() {
        }

        void write(Word address, Byte data) {
            bus.write(address, data);
        }

        Byte read(Word address) {
            return bus.read(address);
        }
};

#endif // CPU_H