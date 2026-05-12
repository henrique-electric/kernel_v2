#ifndef CPU_H
#define CPU_H
#include <stdint.h>
#include <asm_wrappers.h>
#include <compiler_macros.h>

/**
 * @file cpu.h
 * @brief CPU state and interrupt frame structures.
 */

/**
 * @struct cpu_interrupt_state
 * @brief Represents the CPU state pushed onto the stack during an interrupt.
 *
 * We need to consider the fact that the members here will be placed
 * naturally by the CPU and backwards relative to push order when dealing with stack pointer arithmetic.
 */
struct cpu_interrupt_state {
  uint32_t eflags;     /**< EFLAGS register (First pushed by CPU) */
  uint16_t cs;         /**< Code segment selector */
  uint32_t eip;        /**< Instruction pointer */
  uint32_t error_code; /**< Error code (Last pushed by CPU, or stub pushed by ISR) */
} PACKED;

#endif // !CPU_H

