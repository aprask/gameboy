#include "include/bus.h"
#include "include/memory.h"

using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

class Bus {
public:
    Memory memory;
    Byte data;
    Word address;
    bool rw;

    Bus(Memory& memory) : memory(memory) {
        data = 0x00;
        address = 0x0000;
        rw = false;
    }

    Byte read(Word address) {
        this->address = address;
        this->rw = true;
        memory.access(address, rw, &data);
        return data;
    }

    void write(Word address, Byte data) {
        this->address = address;
        this->data = data;
        this->rw = false;
        memory.access(address, rw, &data);
    }

};
