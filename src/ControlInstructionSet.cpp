#include "include/ControlInstructionSet.h"
#include <iostream>

void ControlInstructionSet::initializeInstructionTable(CPU& cpu) {
    // I now have an appreciation for the power of lambdas
    // I was angry, but now I see that this is the way to go
    // lest not forget the hours I poured into these 6 lines of code :(
    cpu.addInstruction(0x00, [this, &cpu] { this->nop(cpu); });
    cpu.addInstruction(0x76, [this, &cpu] { this->halt(cpu); });
    cpu.addInstruction(0x10, [this, &cpu] { this->stop(cpu); });
    cpu.addInstruction(0xCB, [this, &cpu] { this->prefix_cb(cpu); });
    cpu.addInstruction(0xF3, [this, &cpu] { this->di(cpu); });
    cpu.addInstruction(0xFB, [this, &cpu] { this->ei(cpu); });
}

void ControlInstructionSet::nop(CPU& cpu) {}

void ControlInstructionSet::halt(CPU& cpu) {
    
}

void ControlInstructionSet::stop(CPU& cpu) {

}

void ControlInstructionSet::prefix_cb(CPU& cpu) {

}

void ControlInstructionSet::di(CPU& cpu) {

}

void ControlInstructionSet::ei(CPU& cpu) {

}