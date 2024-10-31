#ifndef BUS_H
#define BUS_H

#include <stdint.h>
#include "memory.h"

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

class Bus {
public:
    Memory memory;
    Byte data;
    Word address;
    bool rw;

    Bus(Memory& memory);
    Byte read(Word address);
    void write(Word address, Byte data);
};

#endif // BUS_H
