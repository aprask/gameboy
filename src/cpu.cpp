#include "include/cpu.h"

class CPU {
    public:
        Registers registers;
        Bus bus;

        CPU(Bus& bus) : bus(bus) {
        }

        void reset() {
        }

        void cycle() {
        }

        void write(Word address, Byte data) {
            bus.write(address, data);
        }

        Byte read(Word address) {
            return bus.read(address);
        }
};