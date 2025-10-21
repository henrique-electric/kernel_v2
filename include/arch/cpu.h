#ifndef CPU_H
// clang-format off
#include <stdint.h>
#include <asm_wrappers.h>
#include <compiler_macros.h>


/* We need to consider the fact that the members here will be placed
   at backwards when pushed onto the stack.
*/
struct cpu_interrupt_state {
  uint32_t eflags; //  First pushed
  uint16_t cs;
  uint32_t eip;
  uint32_t error_code; // Last pushed
} PACKED;

#endif // !CPU_H

