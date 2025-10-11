#include <gdt.h>
#include <asm_wrappers.h>

static struct gdt_entry entries[3] = {
    {0},
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x9A, .limit_and_flag = 0xCF, .base_high = 0x00},
    {.limit = 0xFFFF, .base = 0x0000, .base_mid = 0x00, .access = 0x92, .limit_and_flag = 0xCF, .base_high = 0x00}
};

static struct gdt_table table = {
    .size = (uint32_t) sizeof(entries) - 1,
    .offset = (uint32_t) entries,
};

void load_gdt(void) {
    load_gdt_table(&table);

   // asm volatile("lgdt (%0)" : : "r" (&table));
   return;
}

