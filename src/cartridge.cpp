#include <iostream>
#include <fstream>
#include "include/cpu.h"

auto get_mbc_name(Byte cart_type) {
    switch (cart_type) {
        case 0x00: return "ROM ONLY";
        case 0x01: return "MBC1";
        case 0x02: return "MBC1+RAM";
        case 0x03: return "MBC1+RAM+BATTERY";
        case 0x05: return "MBC2";
        case 0x06: return "MBC2+BATTERY";
        case 0x08: return "ROM+RAM";
        case 0x09: return "ROM+RAM+BATTERY";
        case 0x0B: return "MMM01";
        case 0x0C: return "MMM01+RAM";
        case 0x0D: return "MMM01+RAM+BATTERY";
        case 0x0F: return "MBC3+TIMER+BATTERY";
        case 0x10: return "MBC3+TIMER+RAM+BATTERY";
        case 0x11: return "MBC3";
        case 0x12: return "MBC3+RAM";
        case 0x13: return "MBC3+RAM+BATTERY";
        case 0x19: return "MBC5";
        case 0x1A: return "MBC5+RAM";
        case 0x1B: return "MBC5+RAM+BATTERY";
        case 0x1C: return "MBC5+RUMBLE";
        case 0x1D: return "MBC5+RUMBLE+RAM";
        case 0x1E: return "MBC5+RUMBLE+RAM+BATTERY";
        case 0x20: return "MBC6";
        case 0x22: return "MBC7+SENSOR+RUMBLE+RAM+BATTERY";
        default: return "Unknown MBC";
    }
}


auto parse_rom(char* cart_path) {
    std::ifstream rom_file(cart_path, std::ios::binary); // open ROM in binary mode
    if (!rom_file.is_open()) {
        std::cerr << "Error: Could not open ROM file." << std::endl;
        return nullptr;
    }
    rom_file.seekg(0x0147); // jumping to memory location for cart type
    Byte cart_type;
    // this is complicated (not really -- but it looks odd)
    // really all we're doing is reading the values from the binary as a char*
    // char* are pointers to raw memory guaranteed to be 1 byte
    // std::ifstream::read requires a char*
    // we are basically saying "treat this location as a char* so we can read it but really its a Byte*"
    rom_file.read(reinterpret_cast<char*>(&cart_type), sizeof(Byte)); // https://en.cppreference.com/w/cpp/language/reinterpret_cast
    auto mbc_name = get_mbc_name(cart_type);
    std::cout << "Cart Type: " << mbc_name << std::endl;
    rom_file.close();
    return nullptr;
}