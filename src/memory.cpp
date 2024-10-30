#include <stdio.h>
#include <stdint.h>

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

typedef struct {
    // ROM Bank 00 - 0x0000 - 0x3FFF (From cartridge)
    Byte rom_bank_00[4096];

    // ROM Bank 01 - NN - 0x4000 - 0x7FFF (From cartridge)
    Byte rom_bank_nn[4096];

    // VRAM - 0x8000 - 0x9FFF 
    Byte vram[8192];

    // External RAM - 0xA000 - 0xBFFF (From cartridge, if available)
    Byte external_ram[8192];

    // WRAM Bank 0 - 0xC000 - 0xCFFF
    Byte wram_bank_0[4096];

    // WRAM Bank 1 - 0xD000 - 0xDFFF
    Byte wram_bank_1[4096];

    // Echo RAM - 0xE000 - 0xFDFF (Copy of C000 - DDFF, use is prohibited by Nintendo)
    Byte echo_ram[7680];

    // OAM - 0xFE00 - 0xFE9F
    Byte object_attribute_memory[160];

    // Not Usable - 0xFEA0 - 0xFEFF (Prohibited by Nintendo)
    Byte not_usable[96];

    // IO Registers - 0xFF00 - 0xFF7F
    Byte joypad; // P1/JOYP - 0xFF00
    Byte serial_transfer_data; // SB - 0xFF01
    Byte serial_transfer_control; // SC - 0xFF02
    Byte divider; // DIV - 0xFF04
    Byte timer_counter; // TIMA - 0xFF05
    Byte timer_modulo; // TMA - 0xFF06
    Byte timer_control; // TAC - 0xFF07
    Byte interrupt_flag; // IF - 0xFF0F
    Byte NR1x[5]; // Pulse w/ sweep - 0xFF10 - 0xFF14
    Byte NR2x[5]; // Pulse  - 0xFF15 - 0xFF19
    Byte NR3x[5]; // Wave output - 0xFF1A - 0xFF1E
    Byte NR4x[5]; // Noise - 0xFF1F - 0xFF23
    Byte NR5x[3]; // Sound control - 0xFF24 - 0xFF26
    Byte WAV[16]; // Wave pattern RAM - 0xFF30 - 0xFF3F
    Byte lcd_control; // LCDC - 0xFF40
    Byte lcd_y; // LY (read-only) - 0xFF44
    Byte lcd_y_compare; // LYC - 0xFF45
    Byte lcd_status; // STAT - 0xFF41
    Byte scroll_y; // SCY - 0xFF42
    Byte scroll_x; // SCX - 0xFF43
    Byte window_y; // WY - 0xFF4A
    Byte window_x; // WX - 0xFF4B
    Byte dma_transfer; // DMA - 0xFF46
    Byte bg_palette; // BGP - 0xFF47
    Byte obj_palette_0; // OBP0 - 0xFF48
    Byte obj_palette_1; // OBP1 - 0xFF49
    Byte boot_disable; // BANK - 0xFF50
    Byte ir_communications; // RP - 0xFF56

    // HRAM - 0xFF80 - 0xFFFE
    Byte hram[127];

    // Interrupt Enable Register - 0xFFFF
    Byte interrupt_enable;
} MemoryMap;