#include <idt.h>
#include <asm_wrappers.h>
#include <arch/interrupts.h>

/**
 * @file idt.c
 * @brief Implementation of the Interrupt Descriptor Table (IDT) initialization and population.
 */

extern char get_press(void);

/**
 * @brief Array of gate descriptors covering the CPU exceptions and PIC hardware interrupts.
 * 
 * We allocate 48 entries: 32 for CPU exceptions/faults, and 16 for PIC hardware interrupts.
 */
static struct gate_descriptor handlers[48];

/**
 * @brief The IDTR record containing the size and location of the IDT table.
 */
static struct idtr idt_table = {
  .size = (uint16_t)sizeof(handlers) - 1, 
  .offset = (uint32_t)handlers 
};

/**
 * @brief Populates a standard ring-0 interrupt gate entry in the IDT.
 *
 * @param handler Function pointer / memory address to the ISR body.
 * @param index Position within the IDT table (0 to 255).
 */
void set_entry(uint32_t handler, uint8_t index) {
  handlers[index].offset_low = handler & 0xFFFF; // lower 16 bits
  handlers[index].segment_selector = 0x08;       // kernel code segment (GDT index 1)
  handlers[index].reserved = 0;                  // reserved bytes must be zero
  handlers[index].flags = 0x8E;                  // 10001110b: Present (1), DPL (00), System (0), Gate type (1110 - 32-bit Interrupt Gate)
  handlers[index].offset_high = (handler >> 16) & 0xFFFF; // upper 16 bits
}

/**
 * @brief Populates a ring-3 callable interrupt gate (used for Syscalls).
 *
 * @param handler Function pointer to the syscall dispatcher.
 * @param index Position within the IDT table (usually 0x80).
 */
void set_interrupt_syscall(uint32_t handler, uint8_t index) {
  handlers[index].offset_low = handler & 0xFFFF;
  handlers[index].segment_selector = 0x08;
  handlers[index].reserved = 0;
  handlers[index].flags = 0xEF;                  // 11101111b: Present (1), DPL (11 - Ring 3), System (0), Gate type (1111 - 32-bit Trap Gate)
  handlers[index].offset_high = (handler >> 16) & 0xFFFF;
}

/**
 * @brief Uses the auto-generated macros to set entries for standard CPU exceptions (0-31).
 */
void load_exceptions(void) {
  EXCEPTIONS_LIST;
}

/**
 * @brief Uses the auto-generated macros to set entries for programmable interrupt controllers (32-47).
 */
void load_pic_interrupts(void) {
  PIC_HARDWARE_INTERRUPTS;
}

/**
 * @brief Initializes the IDT and loads the IDTR into the CPU using assembly `lidt`.
 */
void load_idt(void) {
  load_exceptions();
  load_pic_interrupts();
  load_idt_table(&idt_table);
  return;
}
