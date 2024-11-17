#ifndef INSTRUCTION_SET_H
#define INSTRUCTION_SET_H
#include <cstdint>
#include "cpu.h"
class InstructionSet {
public:
    virtual void initializeInstructionTable(CPU& cpu) = 0;
};
#endif // INSTRUCTION_SET_H
