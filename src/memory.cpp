#include <stdio.h>
#include <stdint.h>

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

typedef struct {
    Byte port_1; // P1
    Byte serial_data; // SB
    Byte serial_control; // SC
    Byte divider; // DIV
    Byte timer_counter; // TIMA
    Byte timer_modulo; // TMA
    Byte timer_control; // TAC
    Byte interrupt_flag; // IF
    Byte NR[22]; // Sound registers
    Byte WAV[16]; // Waveform RAM
    Byte lcd_control; // LCDC
    Byte lcd_status; // STAT
    Byte scroll_y; // SCY
    Byte scroll_x; // SCX
    Byte lcd_y; // LY
    Byte lcd_y_compare; // LYC
    Byte dma_transfer; // DMA
    Byte bg_palette; // BGP
    Byte obj_palette_0; // OBP0
    Byte obj_palette_1; // OBP1
    Byte window_y; // WY
    Byte window_x; // WX
    Byte prepare_speed_switch; //KEY1
    Byte vram_bank; // VBK
    Byte boot; // BOOT
    Byte hdma[5]; // HDMA1-5
    Byte ir_communications; // RP
    Byte background_palette_index; // BCPS
    Byte background_palette_data; // BCPD
    Byte object_palette_index; // OCPS
    Byte object_palette_data; // OCPD
    Byte wram_bank; // SVBK
    Byte audio_digital_12; // PCM12
    Byte audio_digital_34; // PCM34
    Byte interrupt_enable; // IE
} MemoryMap;