#include <iostream>
#include "decoder.h"


Instruction decode(uint32_t raw) { // Decode a 32-bit instruction into an Instruction struct
    Instruction inst{Opcode::UNKNOWN, 0, 0, 0, 0};

    uint32_t opcode = raw & 0x7F;
    uint32_t rd     = (raw >> 7) & 0x1F; // destination register index
    uint32_t funct3 = (raw >> 12) & 0x7; // function3 field for R-type
    uint32_t rs1    = (raw >> 15) & 0x1F; // source register 1 index
    uint32_t rs2    = (raw >> 20) & 0x1F; // source register 2 index
    uint32_t funct7 = (raw >> 25) & 0x7F; // function7 field for R-type

    // R-type ADD/SUB
    if (opcode == 0x33) {
        inst.rd = rd;
        inst.rs1 = rs1;
        inst.rs2 = rs2;
        if (funct3 == 0x0 && funct7 == 0x00) {
            inst.opcode = Opcode::ADD;
        } else if (funct3 == 0x0 && funct7 == 0x20) {
            inst.opcode = Opcode::SUB;
        }
    }

   else if (opcode == 0x03) {
    inst.opcode = Opcode::LW;
    inst.rd = rd;
    inst.rs1 = rs1;

    int32_t imm = (raw >> 20) & 0xFFF;

    // sign extend
    if (imm & 0x800)
        imm |= 0xFFFFF000;

    inst.imm = imm;
}
    else if (opcode == 0x23) {
        inst.opcode = Opcode::SW;
        inst.rs1 = rs1;
        inst.rs2 = rs2;

        int32_t imm = ((raw >> 25) << 5) | ((raw >> 7) & 0x1F);
        imm &= 0xFFF;

        // sign extend
        if (imm & 0x800)
            imm |= 0xFFFFF000;

        inst.imm = imm;
        std::cout << "SW decoded imm = " << inst.imm << std::endl;
    }

    return inst;
}