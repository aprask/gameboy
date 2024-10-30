#include <stdlib.h>
#include <stdint.h>

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

Word address_bus; // 16 bits
Byte data_bus; // 8 bits

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
} Registers;

typedef struct {
    Byte memory[65536]; // Testing this for now, may be more efficient than mapping out parts separately.
} Memory;

Memory memory;
Registers registers;

void access(Word address, bool rw, Byte* data) {
        switch (address) {
            case 0x8000 ... 0x9FFF: // VRAM
            case 0xA000 ... 0xBFFF: // External RAM (this is stored in the cartridge and can return garbage if not present)
            case 0xC000 ... 0xDFFF: // Work RAM
            case 0xFE00 ... 0xFE9F: // OAM
            case 0xFF80 ... 0xFFFE: // High RAM
            case 0xFFFF: // Interrupt Enable Register
                if (rw) {
                    // Read
                    *data = memory.memory[address];
                } else {
                    // Write
                    memory.memory[address] = *data;
                }
                break;
            case 0x0000 ... 0x7FFF: // ROM (read only)
                if (rw) {
                    // Read
                    *data = memory.memory[address];
                }
                break;
            case 0xE000 ... 0xFDFF: // Echo RAM (echoes C000 - DDFF)
                if (rw) {
                    // Read
                    *data = memory.memory[address - 0x2000];
                } else {
                    // Write
                    memory.memory[address - 0x2000] = *data;
                }
                break;
            case 0xFEA0 ... 0xFEFF: // Unusable memory
                break;
            case 0xFF00 ... 0xFF7F: // I/O Registers (this is separated because some I/O registers are read only)... to be added later
                if (rw) {
                    // Read
                    *data = memory.memory[address];
                } else {
                    // Write
                    memory.memory[address] = *data;
                }
                break;
        }
}
