#pragma once
#include <libc/puts.h>
#include <stdint.h>

#define TRAP_GATE 0
#define INT_GATE 1

typedef int (*isr_handler)(void);

struct gate_descriptor {
  uint16_t offset_low;
  uint16_t segment_selector;
  uint8_t reserved;
  uint8_t flags;
  uint16_t offset_high;
} __attribute__((packed));

struct idtr {
  uint16_t size;
  uint32_t offset;
} __attribute__((packed));

void set_entry(uint32_t handler, uint8_t index);
void load_idt(void);
