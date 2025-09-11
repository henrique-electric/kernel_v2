#include <idt.h>

static struct gate_descriptor handlers[256];

static struct idtr idt_table = {
    .size = (uint32_t) sizeof(handlers) - 1,
    .offset = (uint32_t) handlers
};

void set_entry(uint32_t handler, uint16_t index) {
    handlers[handler].offset_low = handler & 0xff;
    handlers[handler].segment_selector = 0x08;
    handlers[handler].reserved = 0x00;
    handlers[handler].ist = 0b11100111;
    handlers[handler].offset_high = (handler >> 24) & 0xFF;
}

void load_idt(void) {
    asm volatile("lidt (%0)" : : "r" (&idt_table));
}