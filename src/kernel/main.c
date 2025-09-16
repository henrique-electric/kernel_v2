#include <gdt.h>
#include <idt.h>
extern void puts(char *str);

void kmain(void) {
  load_gdt();
  puts("loaded GDT");
  load_idt();
  clear();
  puts("Loaded IDT");
  while (1) {
  }
  return;
}
