#ifndef CPU_H
// clang-format off
#include <stdint.h>
#include <asm_wrappers.h>
#include <compiler_macros.h>
#include <core_defines.h>

struct cpu_pushad {
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t esp;
  uint32_t ebx;
  uint32_t edx;
  uint32_t ecx;
  uint32_t eax;
} PACKED;


struct interrupt_stub_args {
  uint32_t vector;
  uint32_t error_code; // might me a dummy
  uint32_t eip;
  uint32_t cs;
  uint32_t eflags;
} PACKED;

#endif // !CPU_H

