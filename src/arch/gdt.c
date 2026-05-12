#include <gdt.h>
#include <asm_wrappers.h>

/**
 * @file gdt.c
 * @brief Implementation of the Global Descriptor Table (GDT) setup.
 */

/**
 * @brief The entries defining the various segments in the GDT.
 * 
 * Includes the null descriptor, kernel code, kernel data, and the Task State Segment (TSS).
 */
static struct gdt_entry entries[4] = {

    // Null entry (required as the first element)
    {0},

    // Kernel Code Segment
    // Base: 0x0, Limit: ~0, Access: 0x9B (Present, Ring0, Code/Exec), Flags: 0xCF (4KB granular, 32-bit)
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x9B, .limit_and_flag = 0xCF, .base_high = 0x00},

    // Kernel Data Segment
    // Base: 0x0, Limit: ~0, Access: 0x93 (Present, Ring0, Data/Read-Write), Flags: 0xCF
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x93, .limit_and_flag = 0xCF, .base_high = 0x00},

    // Task State Segment (TSS)
    // Base: 0x0, Limit: ~0, Access: 0x89 (Present, Ring0, Available 32-bit TSS), Flags: 0x00
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x89, .limit_and_flag = 0x00, .base_high = 0x00}  
};

/**
 * @brief The actual GDT pointer used by the `lgdt` instruction.
 */
static struct gdt_table table = {
    .size = (uint32_t) sizeof(entries) - 1,
    .offset = (uint32_t) entries,
};


/**
 * @brief Wrapper for the assembly function defined in `src/arch/tables.asm` to load the GDT.
 */
void load_gdt(void) {
    load_gdt_table(&table);
   return;
}

