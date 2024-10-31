#include "include/bus.h"

Bus::Bus(Memory& memory) : memory(memory) {
    data = 0x00;
    address = 0x0000;
    rw = false;
}

Byte Bus::read(Word address) {
    this->address = address;
    this->rw = true;
    memory.access(address, rw, &data);
    return data;
}

void Bus::write(Word address, Byte data) {
    this->address = address;
    this->data = data;
    this->rw = false;
    memory.access(address, rw, &data);
}
