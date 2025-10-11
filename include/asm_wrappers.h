#ifndef ASM_WRAPPERS_H
#define ASL_WRAPPERS_H
#include <stdint.h>

// ====== Port/IO======
extern void outb(uint16_t port, uint16_t value);
extern uint16_t inb(uint16_t port);
// ====================

// ====== Tables ======
extern void load_gdt_table(void *table);
extern void load_idt_table(void *table);
// ====================

// ====== ISR handlers ======
extern void isr_0(void);
extern void isr_1(void);
extern void isr_21h(void);
extern void exceptions_default(void);
// =========================
#endif