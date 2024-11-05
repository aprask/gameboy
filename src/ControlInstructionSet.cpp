#include "include/ControlInstructionSet.h"

bool ControlInstructionSet::execute_prefix(uint16_t opcode, CPU& cpu) {
        return false;
}

bool ControlInstructionSet::execute(uint8_t opcode, CPU& cpu) {
    switch (opcode) {
        case NOP:
            nop();
            return true;
        case HALT:
            halt(cpu);
            return true;
        case STOP:
            stop(cpu);
            return true;
        case PREFIX_CB:
            prefix_cb(cpu);
            return true;
        case DI:
            di(cpu);
            return true;
        case EI:
            ei(cpu);
            return true;
        default:
            return false; // Opcode not handled by ControlInstructionSet
    }
}

void ControlInstructionSet::nop() {
    // No operation
}

void ControlInstructionSet::halt(CPU& cpu) {
    // Placeholder: Call the halt function on the CPU
    // Example: cpu.halt();
}

void ControlInstructionSet::stop(CPU& cpu) {
    // Placeholder: Call the stop function on the CPU
    // Example: cpu.stop();
}

void ControlInstructionSet::prefix_cb(CPU& cpu) {
    // Placeholder for PREFIX_CB functionality
    // Example: cpu.prefix_cb();
}

void ControlInstructionSet::di(CPU& cpu) {
    // Placeholder for DI functionality, such as disabling interrupts
    // Example: cpu.disableInterrupts();
}

void ControlInstructionSet::ei(CPU& cpu) {
    // Placeholder for EI functionality, such as enabling interrupts
    // Example: cpu.enableInterrupts();
}