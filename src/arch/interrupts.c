#include <arch/interrupts.h>
#include <stdint.h>
#include <kernel/tty/kb.h>
#include <asm_wrappers.h>
#include <kernel/log.h>
#include <compiler_macros.h>
#include <arch/cpu.h>

void print_dec(uint8_t n) {
    volatile char* vga = (char*)0xB8000;
    int pos = 0;

    if (n >= 100) {
        vga[pos++] = '0' + (n / 100);
        vga[pos++] = 0x07;
    }
    if (n >= 10) {
        vga[pos++] = '0' + ((n / 10) % 10);
        vga[pos++] = 0x07;
    }
    vga[pos++] = '0' + (n % 10);
    vga[pos++] = 0x07;
}


void CDECL handler_isr(struct interrupt_stub_args cpu_state) {
  print_dec(cpu_state.cs);
  return;
}
