#include <kernel/serial.h>
#include <asm_wrappers.h>

void init_serial(void) {
  outb(IER, 0);
}

void write_serial(unsigned char data) {
  outb(THR_RBR, (unsigned short) data);
}
