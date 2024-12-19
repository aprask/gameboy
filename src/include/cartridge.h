#ifndef CARTRIDGE_H
#define CARTRIDGE_H
#include <iostream>
#include <fstream>

using Byte = uint8_t;
using Word = uint16_t;

class Cartridge {
    public:
        void parse_rom(const char* cart_path);
        auto get_mbc_name(Byte cart_type);
};

#endif // CARTRIDGE_H
