#include <arch/interrupts.h>
#include <stdint.h>
#include <kernel/tty/kb.h>
#include <asm_wrappers.h>
#include <kernel/log.h>

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


void __attribute__((cdecl))handler_isr(int id) {
  if (id == 13) {
    log("GPF", ERROR);
  }
  return;
}
