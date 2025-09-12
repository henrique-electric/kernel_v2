#include <idt.h>

static struct gate_descriptor handlers[256];

static struct idtr idt_table = {
    .size = (uint32_t) sizeof(handlers) - 1,
    .offset = (uint32_t) handlers
};

void key_handler() {
    puts("Key\0");
}

void set_entry(uint32_t handler, uint8_t index) {
    handlers[index].offset_low = handler & 0xFFFF;             // lower 16 bits
    handlers[index].segment_selector = 0x08;                   // kernel code segment
    handlers[index].reserved = 0;                               // reserved, set 0
    handlers[index].flags = 0x8E;                               // present, interrupt gate, ring 0
    handlers[index].offset_high = (handler >> 16) & 0xFFFF;    // upper 16 bits
}

void load_idt(void) {
    set_entry((uint32_t) key_handler, 0x21);
    asm("cli");
    asm volatile("lidt (%0)" : : "r" (&idt_table));
    asm("sti");
}