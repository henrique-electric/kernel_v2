#include <gdt.h>
#include <idt.h>
#include <kernel/log.h>

void kmain(void) {
  load_gdt();
  log("Loaded GDT", INFO);
  load_idt();
  clear();
  log("Loaded IDT", INFO);
  while (1)
  {
    /* code */
  }
  
  return;
}
