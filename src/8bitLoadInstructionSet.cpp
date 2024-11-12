#include "include/8bitLoadInstructionSet.h"

void EightBitLoadInstructionSet::initializeInstructionTable(CPU& cpu) {
    // Hold on...
}

void EightBitLoadInstructionSet::ld_r_r(CPU& cpu, Byte& source, Byte& destination) {
    destination = source;
}
