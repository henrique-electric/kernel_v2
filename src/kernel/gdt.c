#include <gdt.h>
#include <asm_wrappers.h>


/*
    The entries of each segment on the gdt
*/
static struct gdt_entry entries[4] = {

    // Null entry (must have)
    {0},

    // Kernel Code Segment
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x9B, .limit_and_flag = 0xCF, .base_high = 0x00},

    // Kernel Data Segment
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x93, .limit_and_flag = 0xCF, .base_high = 0x00},

    // Task Statement Segment
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x89, .limit_and_flag = 0x00, .base_high = 0x00}  
};

/*
    The actual GDT
    .size = The size of the entire table in bits
    .offset = Address of the beginning of the table
*/
static struct gdt_table table = {
    .size = (uint32_t) sizeof(entries) - 1,
    .offset = (uint32_t) entries,
};


// Wrapper for the function defined on src/arch/tables.asm
void load_gdt(void) {
    load_gdt_table(&table);
   return;
}

