#include "include/cpu.h"

CPU::CPU(Bus& bus) : bus(bus) {
}

void CPU::reset() {
}

void CPU::cycle() {
}

void CPU::write(Word address, Byte data) {
    bus.write(address, data);
}

Byte CPU::read(Word address) {
    return bus.read(address);
}
