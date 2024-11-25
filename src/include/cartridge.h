#ifndef CARTRIDGE_H
#define CARTRIDGE_H
#include "cpu.h"

typedef struct {
    Byte entry_point[4];
    Byte logo[48];
    Byte title[16];
    Byte manuf_code[4];
    Byte cgb_flag;
    Word new_lic_code;
    Byte sgb_flag;
    Byte type;
    Byte rom_size;
    Byte ram_size;
    Byte dest_code;
    Byte lic_code;
    Byte version;
    Byte checksum;
    Word global_checksum;

} rom_h;

auto parse_rom(char* cart);

#endif // CARTRIDGE_H