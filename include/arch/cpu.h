#ifndef CPU_H
// clang-format off
#include <stdint.h>
#include <asm_wrappers.h>
#include <compiler_macros.h>


struct cpu_interrupt_state {
  uint32_t error_code;
  uint32_t eip;
  uint16_t cs;
  uint32_t eflags;
  uint16_t gs;
  uint16_t fs;
  uint16_t es;
  uint16_t ds;
  uint32_t edi;
  uint32_t esi;
  uint32_t ebp;
  uint32_t esp;
  uint32_t ebx;
  uint32_t edx;
  uint32_t ecx;
  uint32_t eax;
} PACKED;


#endif // !CPU_H

