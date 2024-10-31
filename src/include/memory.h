#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
#include <stdint.h>

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

class Memory {
public:
    Byte memory[65536]; // 64KB of memory

    Memory();
    void access(Word address, bool rw, Byte* data);
};

#endif // MEMORY_H
