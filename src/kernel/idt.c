#include <idt.h>
#include <asm_wrappers.h>
#include <arch/interrupts.h>

extern char get_press(void);

static struct gate_descriptor handlers[256];

static struct idtr idt_table = {.size = (uint16_t)sizeof(handlers) - 1,
                                .offset = (uint32_t)handlers};



void set_entry(uint32_t handler, uint8_t index) {
  handlers[index].offset_low = handler & 0xFFFF; // lower 16 bits
  handlers[index].segment_selector = 0x08;       // kernel code segment
  handlers[index].reserved = 0;                  // reserved, set 0
  handlers[index].flags = 0x8E;                   // present, interrupt gate, ring 0
  handlers[index].offset_high = (handler >> 16) & 0xFFFF; // upper 16 bits
}

void set_interrupt_syscall(uint32_t handler, uint8_t index) {
  handlers[index].offset_low = handler & 0xFFFF;
  handlers[index].segment_selector = 0x08;
  handlers[index].reserved = 0;
  handlers[index].flags = 0x8F;
  handlers[index].offset_high = (handler >> 16) & 0xFFFF;
}

void load_exceptions(void) {
  EXCEPTIONS_LIST;
}

void load_pic_interrupts(void) {
  PIC_HARDWARE_INTERRUPTS;
}

void load_idt(void) {
  load_exceptions();
  load_pic_interrupts();
  load_idt_table(&idt_table);
  return;
}
