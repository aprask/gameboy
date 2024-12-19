#include "include/cartridge.h"

auto Cartridge::get_mbc_name(Byte cart_type) {
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


void Cartridge::parse_rom(const char* cart_path) {
    std::ifstream rom_file(cart_path, std::ios::binary); // open ROM in binary mode
    if (!rom_file.is_open()) {
        std::cerr << "Error: Could not open ROM file." << std::endl;
    }
    rom_file.seekg(0, std::ios::end);
    std::streampos file_size = rom_file.tellg();
    std::cout << "File size: " << file_size << " bytes" << std::endl;
    if (file_size < 0x0147 + 1) {
        std::cerr << "Error: File is too small to contain cartridge type at 0x0147." << std::endl;
        return;
    }
    rom_file.seekg(0x0147); // jumping to memory location for cart type
    std::cout << "File position after seek: " << rom_file.tellg() << std::endl;
    char temp_byte = 0;
    rom_file.read(&temp_byte, 1);
    Byte cart_type = static_cast<Byte>(static_cast<unsigned char>(temp_byte));
    if (rom_file.fail()) {
        std::cerr << "Error: Failed to read cartridge type." << std::endl;
        return;
    }
    std::cout << "Raw Value at 0x0147: " << std::hex << static_cast<int>(cart_type) << std::dec << std::endl;
    auto mbc_name = get_mbc_name(cart_type);
    std::cout << "Cart Type: " << mbc_name << std::endl;
    rom_file.close();
}
