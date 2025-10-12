#ifndef ASM_WRAPPERS_H
#define ASM_WRAPPERS_H
#include <stdint.h>

// ====== Assembly helpers ========
#define CLI() asm __volatile__("cli");
#define STI() asm __volatile__("sti");
#define HLT() asm __volatile__("hlt");
// ================================

// ====== Port/IO======
extern void outb(uint16_t port, uint16_t value);
extern uint16_t inb(uint16_t port);
// ====================

// ====== Tables ======
extern void load_gdt_table(void *table);
extern void load_idt_table(void *table);
// ====================
#endif