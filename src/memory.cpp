#include "include/memory.h"

Memory::Memory() {
}

void Memory::access(Word address, bool rw, Byte* data) {
            switch (address) {
                case 0x8000 ... 0x9FFF: // VRAM
                case 0xA000 ... 0xBFFF: // External RAM (this is stored in the cartridge and can return garbage if not present)
                case 0xC000 ... 0xDFFF: // Work RAM
                case 0xFE00 ... 0xFE9F: // OAM
                case 0xFF80 ... 0xFFFE: // High RAM
                case 0xFFFF: // Interrupt Enable Register
                    if (rw) {
                        // Read
                        *data = memory[address];
                    } else {
                        // Write
                        memory[address] = *data;
                    }
                    break;
                case 0x0000 ... 0x7FFF: // ROM (read only)
                    if (rw) {
                        // Read
                        *data = memory[address];
                    }
                    break;
                case 0xE000 ... 0xFDFF: // Echo RAM (echoes C000 - DDFF)
                    if (rw) {
                        // Read
                        *data = memory[address - 0x2000];
                    } else {
                        // Write
                        memory[address - 0x2000] = *data;
                    }
                    break;
                case 0xFEA0 ... 0xFEFF: // Unusable memory
                    break;
                case 0xFF00 ... 0xFF7F: // I/O Registers (this is separated because some I/O registers are read only)... to be added later
                    if (rw) {
                        // Read
                        *data = memory[address];
                    } else {
                        // Write
                        memory[address] = *data;
                    }
                    break;
            }
        }
