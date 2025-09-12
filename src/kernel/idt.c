#include <idt.h>

static struct gate_descriptor handlers[255];

static struct idtr idt_table = {
    .size = (uint16_t) sizeof(handlers) - 1,
    .offset = (uint32_t) handlers
};

void handler_isr(int id) {
    return;
}

void set_entry(uint32_t handler, uint8_t index) {
    handlers[index].offset_low = handler & 0xFFFF;             // lower 16 bits
    handlers[index].segment_selector = 0x08;                   // kernel code segment
    handlers[index].reserved = 0;                               // reserved, set 0
    handlers[index].flags = 0x8E;                               // present, interrupt gate, ring 0
    handlers[index].offset_high = (handler >> 16) & 0xFFFF;    // upper 16 bits
}

extern void isr_0();
void load_idt(void) {
    for (uint8_t i = 0; i < 255; i++)
        set_entry((uint32_t) isr_0, i);
    
    asm volatile("lidt (%0)" : : "m" (idt_table));
    asm volatile("sti");
    return;
}