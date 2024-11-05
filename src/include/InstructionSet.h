#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H
#include <cstdint>
#include "cpu.h"
class InstructionSet {
public:
    virtual bool execute(uint8_t opcode, CPU& cpu) = 0;
    virtual bool execute_prefix(uint16_t opcode, CPU& cpu) = 0;
};
#endif // INSTRUCTION_SET_H
