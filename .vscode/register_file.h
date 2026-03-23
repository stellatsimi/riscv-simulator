#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H

#include <cstdint>

class RegisterFile {
public:
    RegisterFile();

    int32_t read(int index) const;
    void write(int index, int32_t value);

private:
    int32_t regs[32]; // 32 general-purpose registers
};

#endif