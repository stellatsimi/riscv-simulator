#include "register_file.h"

RegisterFile::RegisterFile() {
    for (int i = 0; i < 32; i++) {
        regs[i] = 0;
    }
}

int32_t RegisterFile::read(int index) const {
    return regs[index];
}

void RegisterFile::write(int index, int32_t value) {
    if (index != 0) { // x0 always 0
        regs[index] = value;
    }
}