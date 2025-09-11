#pragma once
#include <stdint.h>

#define TRAP_GATE 0
#define INT_GATE  1


#pragma packed
struct gate_descriptor
{
    uint16_t offset_low;
    uint16_t segment_selector;
    uint8_t reserved;
    uint8_t ist;
    uint16_t offset_high;
};

#pragma packed
struct idtr
{
    uint16_t size;
    uint32_t offset;
};

void set_entry(uint32_t handler, uint16_t index);
void load_idt(void);