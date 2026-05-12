# Kernel v2

A custom 32-bit x86 kernel written in C and Assembly for fun and learning.

## Overview

This project is an experimental i386 operating system kernel. It features standard x86 components such as:
- **Global Descriptor Table (GDT)**
- **Interrupt Descriptor Table (IDT)** and Interrupt Service Routines (ISRs)
- **Basic Memory Management**
- **VGA Text Mode Drivers** for TTY output

## Prerequisites

To build and run this kernel, you will need:
- **Podman / Docker:** Used to containerize the cross-compiler toolchain via `make cont`.
- **QEMU:** To emulate the i386 machine and run the kernel ISO.

## Build and Run

1. **Build the Kernel:**
   We use a container to provide a consistent `clang`/`nasm` build environment.
   ```bash
   make cont
   ```
   This will compile the C and Assembly files, link them into `kernel.elf`, and generate `kernel.iso` using GRUB.

2. **Run in QEMU:**
   ```bash
   make qemu
   ```

3. **Clean the Workspace:**
   ```bash
   make clean
   ```

## Documentation

The project uses **Doxygen** to generate source code documentation.
To generate HTML documentation, run:
```bash
doxygen Doxyfile
```
The output will be placed in the `docs/html/` directory.

## Current Project Structure

- `build/`: Object files generated during compilation.
- `docs/`: Technical architecture documentation and generated Doxygen HTML.
- `include/`: C header files (grouped by `arch/`, `kernel/`, `libc/`).
- `iso/`: Final GRUB filesystem tree and generated boot ISO.
- `src/`: C and Assembly source implementations.