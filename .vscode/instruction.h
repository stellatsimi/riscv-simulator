#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>

enum class Opcode {
    ADD,
    SUB,
    LW,
    SW,
    UNKNOWN
};

struct Instruction {
    Opcode opcode;
    int rd;
    int rs1;
    int rs2;
    int imm; // immediate
};

#endif