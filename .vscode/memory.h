#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <cstdint>

class Memory {
public:
    Memory(size_t size);

    uint32_t loadWord(uint32_t addr);
    void storeWord(uint32_t addr, uint32_t value);

private:
    std::vector<uint8_t> mem; // byte-addressable memory
};

#endif