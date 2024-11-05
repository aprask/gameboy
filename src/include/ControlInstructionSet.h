#ifndef CONTROL_INSTRUCTION_SET_H
#define CONTROL_INSTRUCTION_SET_H

#include "InstructionSet.h"
#include "cpu.h"

#define NOP 0x00
#define HALT 0x76
#define STOP 0x10
#define PREFIX_CB 0xCB
#define DI 0xF3
#define EI 0xFB

class ControlInstructionSet : public InstructionSet {
public:
    bool execute(uint8_t opcode, CPU& cpu) override;
    bool execute_prefix(uint16_t opcode, CPU& cpu) override;
    
private:
    void nop();
    void halt(CPU& cpu);
    void stop(CPU& cpu);
    void prefix_cb(CPU& cpu);
    void di(CPU& cpu);
    void ei(CPU& cpu);

};
#endif // CONTROL_INSTRUCTION_SET_H
