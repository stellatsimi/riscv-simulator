#ifndef DECODER_H
#define DECODER_H

#include "instruction.h"

Instruction decode(uint32_t raw); // Decode a 32-bit instruction into an Instruction struct

#endif