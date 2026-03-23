#ifndef CPU_H
#define CPU_H

#include <cstdint>
#include "register_file.h"
#include "memory.h"

class CPU {
public:
    CPU();
    void run();

private:
    uint32_t pc; // program counter
    RegisterFile regs;
    Memory memory;
};

#endif