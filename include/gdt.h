#pragma once
#include <stdint.h>

struct gdt_entry {
    uint16_t limit;
    uint16_t base;
    uint8_t  base_mid;
    uint8_t  access;
    uint8_t  limit_and_flag;
    uint8_t  base_high;
}__attribute__((packed));

struct gdt_table {
    uint16_t    size;
    uint32_t    offset;
} __attribute__((packed));

void load_gdt(void);