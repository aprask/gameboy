#include <stdlib.h>
#include <stdint.h>

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

typedef struct {
    Word program_counter; 
    Word stack_pointer;

    // Special purpose registers
    Byte instruction_register;
    Byte interrupt_enable;

    // General purpose registers
    Byte af_registers[2];
    Byte bc_registers[2];
    Byte de_registers[2];
    Byte hl_registers[2];
} RegisterMap;