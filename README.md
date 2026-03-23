# RISC-V C++ Architectural Simulator

This is an architectural-level CPU simulator inspired by the RISC-V ISA, implemented in C++.  
It models core CPU components, including registers, memory, and basic instruction execution (arithmetic and memory operations).

## Features

- **Supported instructions:**
  - Arithmetic: `ADD`, `SUB`
  - Memory: `LW`, `SW`
- **Memory-mapped simulation** with a simple array
- **Instruction decoding** including sign extension for immediates
- **Fetch-decode-execute loop** with safe stopping on unknown instructions
- **Debug outputs** showing PC, executed instructions, register and memory updates
