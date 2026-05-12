#pragma once
#include <stdint.h>
#include <compiler_macros.h>

/**
 * @file gdt.h
 * @brief Global Descriptor Table (GDT) definitions and structures.
 *
 * The GDT defines the characteristics of the various memory segments used during execution, 
 * including the base address, the size, and access privileges like executability and writability.
 */

/**
 * @struct gdt_entry
 * @brief Defines a single entry in the Global Descriptor Table.
 */
struct gdt_entry {
    uint16_t limit;          /**< Lower 16 bits of the limit */
    uint16_t base;           /**< Lower 16 bits of the base */
    uint8_t  base_mid;       /**< Middle 8 bits of the base */
    uint8_t  access;         /**< Access flags (determines ring level, read/write privileges) */
    uint8_t  limit_and_flag; /**< Upper 4 bits of the limit and 4-bit flags (granularity, size) */
    uint8_t  base_high;      /**< Highest 8 bits of the base */
} PACKED;

/**
 * @struct gdt_table
 * @brief Special pointer structure required to load the GDT via `lgdt`.
 */
struct gdt_table {
    uint16_t    size;   /**< Size of the GDT in bytes minus 1 */
    uint32_t    offset; /**< Linear address of the GDT */
} PACKED; 

/**
 * @brief Initializes and loads the GDT into the CPU.
 */
extern void load_gdt(void);
