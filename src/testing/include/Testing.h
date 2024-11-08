#ifndef TESTING_H
#define TESTING_H

#include <iostream>
#include <stdint.h>
#include "../../include/cpu.h"
#include "../../include/memory.h"
#include "../../include/bus.h"

class Testing {
public:
    virtual void run(CPU& cpu);

    void assertEqual(uint8_t expected, uint8_t actual, std::string message);
    void assertEqual(uint16_t expected, uint16_t actual, std::string message);
    void assert(bool condition, std::string message);
};

#endif // TESTING_H