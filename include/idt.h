#pragma once
#include <libc/puts.h>
#include <stdint.h>

/**
 * @file idt.h
 * @brief Interrupt Descriptor Table (IDT) definitions and structures.
 *
 * The IDT is used by the x86 processor to determine the correct response to
 * interrupts and exceptions.
 */

#define TRAP_GATE 0
#define INT_GATE 1

/**
 * @brief Function pointer type for Interrupt Service Routines (ISRs).
 */
typedef int (*isr_handler)(void);

/**
 * @struct gate_descriptor
 * @brief Represents a single entry in the IDT.
 */
struct gate_descriptor {
  uint16_t offset_low;       /**< Lower 16 bits of the ISR's address */
  uint16_t segment_selector; /**< GDT segment selector that the CPU will load into CS */
  uint8_t reserved;          /**< Set to zero */
  uint8_t flags;             /**< Type and attributes (e.g., Present, DPL, Gate Type) */
  uint16_t offset_high;      /**< Higher 16 bits of the ISR's address */
} __attribute__((packed));

/**
 * @struct idtr
 * @brief Fits the format expected by the `lidt` instruction.
 */
struct idtr {
  uint16_t size;   /**< Size of the IDT in bytes minus 1 */
  uint32_t offset; /**< Linear address of the IDT */
} __attribute__((packed));

/**
 * @brief Sets a specific entry in the IDT.
 *
 * @param handler Memory address of the interrupt service routine function.
 * @param index The index (0-255) in the IDT to populate.
 */
extern void set_entry(uint32_t handler, uint8_t index);

/**
 * @brief Loads the IDT into the processor using the `lidt` instruction.
 */
extern void load_idt(void);
