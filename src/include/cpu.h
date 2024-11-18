#ifndef CPU_H
#define CPU_H

#include <stdlib.h>
#include <stdint.h>
#include <unordered_map>
#include <functional>
#include "bus.h"

const int Z = 7;
const int N = 6;
const int H = 5;
const int C = 4;

const int AF = 0;
const int BC = 1;
const int DE = 2;
const int HL = 3;

using Instruction = std::function<void()>;
using Byte = uint8_t; // 8 bits
using Word = uint16_t; // 16 bits

typedef struct {
    bool enabled;
    bool requested;
    uint16_t handlerAddr;
} Interrupt;

typedef struct {
    Word program_counter;
    Word stack_pointer;

    // Special purpose registers
    Byte instruction_register;
    Byte interrupt_enable;
    Byte a; // Accumulator
    Byte f; // Four least-significant bits will ALWAYS be zero.

    // General purpose registers
    Byte b;
    Byte c;
    Byte d;
    Byte e;
    Byte h; // High register
    Byte l; // Low register

} Registers;

class CPU {
public:
    Registers registers;
    Bus bus;
    bool IME_FLAG;
    bool HALT_FLAG;
    bool STOP_FLAG;
    Interrupt vblank;
    Interrupt lcdStat;
    Interrupt timer;
    Interrupt serial;
    Interrupt joypad;

    // Register functions
    Byte readPair(int pair);
    void writePair(int pair, Byte value);
    Word getPair(int pair);
    void setPair(int pair, Word value);
    bool getBit(Byte& reg, Byte bit);
    void setBit(Byte& reg, unsigned int bit, bool value);
    Word fetchPC();

    CPU(Bus& bus);
    void reset();
    void cycle();
    void write(Word address, Byte data);
    Byte read(Word address);
    void handleInterrupts();
    void addInstruction(Word opcode, Instruction instruction);
    void initializeInstructionTable();
    bool execute(Word opcode);

private:
    std::unordered_map<Word, Instruction> instruction_table;
};

#endif // CPU_H
