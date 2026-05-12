#ifndef ASM_WRAPPERS_H
#define ASM_WRAPPERS_H
#include <stdint.h>

/**
 * @file asm_wrappers.h
 * @brief C wrappers for inline assembly and external assembly routines.
 * 
 * Provides easy-to-use C macros and function prototypes for low-level
 * CPU instructions (like cli, sti, hlt) and port I/O operations defined in assembly.
 */

// ====== Assembly helpers ========
/** @brief Disables hardware interrupts (`cli` instruction) */
#define CLI() asm __volatile__("cli");

/** @brief Enables hardware interrupts (`sti` instruction) */
#define STI() asm __volatile__("sti");

/** @brief Halts the CPU until the next interrupt (`hlt` instruction) */
#define HLT() asm __volatile__("hlt");
// ================================

// ====== Port/IO======
/**
 * @brief Writes a byte to an I/O port.
 * @param port The I/O port number.
 * @param value The value to write.
 */
extern void outb(uint16_t port, uint16_t value);

/**
 * @brief Reads a byte from an I/O port.
 * @param port The I/O port number.
 * @return The value read from the port.
 */
extern uint16_t inb(uint16_t port);
// ====================

// ====== Tables ======
/**
 * @brief Loads the GDT and sets up segment registers.
 * @param table Pointer to the GDT table descriptor.
 */
extern void load_gdt_table(void *table);

/**
 * @brief Loads the IDT.
 * @param table Pointer to the IDTR structure.
 */
extern void load_idt_table(void *table);

/**
 * @brief Loads the TSS into the task register.
 */
extern void load_tss_table(void);

/**
 * @brief Saves the current GDTR into the provided memory address.
 * @param addr Pointer to memory where the GDTR should be saved.
 */
extern void save_gdt(void *addr);
// ====================
#endif
