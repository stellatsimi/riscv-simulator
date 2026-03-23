#include "memory.h"

Memory::Memory(size_t size) : mem(size, 0) {} // Initialize memory with given size, filled with zeros

uint32_t Memory::loadWord(uint32_t addr) {
    return mem[addr] |
           (mem[addr + 1] << 8) |
           (mem[addr + 2] << 16) |
           (mem[addr + 3] << 24);
} // Load a 32-bit word from memory (little-endian) 

void Memory::storeWord(uint32_t addr, uint32_t value) {
    mem[addr] = value & 0xFF;
    mem[addr + 1] = (value >> 8) & 0xFF;
    mem[addr + 2] = (value >> 16) & 0xFF;
    mem[addr + 3] = (value >> 24) & 0xFF;
} // Store a 32-bit word into memory (little-endian)