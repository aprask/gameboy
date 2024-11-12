#include "include/ControlInstructionSet.h"
#include <iostream>

void ControlInstructionSet::initializeInstructionTable(CPU& cpu) {
    // I now have an appreciation for the power of lambdas
    // I was angry, but now I see that this is the way to go
    cpu.addInstruction(0x00, [this, &cpu] { this->nop(cpu); });
    cpu.addInstruction(0x76, [this, &cpu] { this->halt(cpu); });
    cpu.addInstruction(0x10, [this, &cpu] { this->stop(cpu); });
    cpu.addInstruction(0xCB, [this, &cpu] { this->prefix_cb(cpu); });
    cpu.addInstruction(0xF3, [this, &cpu] { this->di(cpu); });
    cpu.addInstruction(0xFB, [this, &cpu] { this->ei(cpu); });
}

void ControlInstructionSet::nop(CPU& cpu) {
    std::cout << "NOP" << std::endl; // NOP does not actually do anything
}

void ControlInstructionSet::halt(CPU& cpu) {
    std::cout << "HALT" << std::endl; // Placeholder: Call the halt function on the CPU
}

void ControlInstructionSet::stop(CPU& cpu) {
    std::cout << "STOP" << std::endl; // Placeholder: Call the stop function on the CPU
}

void ControlInstructionSet::prefix_cb(CPU& cpu) {
    std::cout << "PREFIX CB" << std::endl; // Placeholder: Call the prefix_cb function on the CPU
}

void ControlInstructionSet::di(CPU& cpu) {
    std::cout << "DI" << std::endl; // Placeholder: Call the di function on the CPU
}

void ControlInstructionSet::ei(CPU& cpu) {
    std::cout << "EI" << std::endl; // Placeholder: Call the ei function on the CPU
}