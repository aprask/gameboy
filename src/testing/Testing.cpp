#include "include/Testing.h"

void Testing::assertEqual(uint8_t expected, uint8_t actual, std::string message) {
    if (expected == actual) {
        std::cout << message << " passed" << std::endl;
    } else {
        std::cout << message << " failed" << std::endl;
    }
}

void Testing::assertEqual(uint16_t expected, uint16_t actual, std::string message) {
    if (expected == actual) {
        std::cout << message << " passed" << std::endl;
    } else {
        std::cout << message << " failed" << std::endl;
    }
}

void Testing::assert(bool condition, std::string message) {
    if (condition) {
        std::cout << message << " passed" << std::endl;
    } else {
        std::cout << message << " failed" << std::endl;
    }
}