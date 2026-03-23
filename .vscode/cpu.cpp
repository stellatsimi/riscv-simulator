#include "cpu.h"
#include "decoder.h"
#include <iostream>


CPU::CPU() : pc(0), memory(1024) {
    regs.write(2, 10); // x2 = 10
    regs.write(3, 5);  // x3 = 5

    // ADD x1 = x2 + x3
    memory.storeWord(0, 0x003100B3);

    // SUB x4 = x2 - x3
    memory.storeWord(4, 0x403101B3);

    memory.storeWord(8, 0x06202223); // SW x2, 100(x0)
    memory.storeWord(12, 0x06400283); // LW x5, 100(x0)
}

void CPU::run() {
    bool running = true;
    while (running) {
        uint32_t raw = memory.loadWord(pc); // fetch
        Instruction inst = decode(raw);     // decode

        switch (inst.opcode) {               // execute
            case Opcode::ADD: {
                int val = regs.read(inst.rs1) + regs.read(inst.rs2);
                regs.write(inst.rd, val);
                std::cout << "PC=" << pc << " ADD: x" 
                          << inst.rd << " = " << val << std::endl;
                break;
            }
            case Opcode::SUB: {
                int val = regs.read(inst.rs1) - regs.read(inst.rs2);
                regs.write(inst.rd, val);
                std::cout << "PC=" << pc << " SUB: x" 
                          << inst.rd << " = " << val << std::endl;
                break;
            }
            case Opcode::LW: {
                int32_t addr = regs.read(inst.rs1) + inst.imm;
                int32_t val = memory.loadWord(addr);
                regs.write(inst.rd, val);
                std::cout << "PC=" << pc << " LW: x" << inst.rd << " = " << val 
                << " from addr " << addr << std::endl;
                break;
            }
            case Opcode::SW: {
                int32_t addr = regs.read(inst.rs1) + inst.imm;
                int32_t val = regs.read(inst.rs2);
                memory.storeWord(addr, val);
                std::cout << "PC=" << pc << " SW: x" << inst.rs2 
                << " -> addr " << addr << std::endl;
                break;
        }
           case Opcode::UNKNOWN:
            default:
                std::cout << "Stopping: Unknown instruction at PC="
                          << pc << std::endl;
                running = false;
                continue;
        }

        pc += 4; // move to next instruction

    }
}