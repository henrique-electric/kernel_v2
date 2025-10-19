#include <arch/interrupts.h>
#include <asm_wrappers.h>
#include <compiler_macros.h>
#include <kernel/log.h>
#include <kernel/tty/kb.h>
#include <arch/cpu.h>
#include <stdint.h>

void print_dec(uint8_t n) {
  volatile char *vga = (char *)0xB8000;
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

void CDECL handler_isr(uint32_t id, const struct cpu_interrupt_state *cpu_state) {
  log("Hello World", INFO);
  print_dec(id);
  return;
}
