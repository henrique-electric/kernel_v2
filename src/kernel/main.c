#include <gdt.h>
#include <idt.h>
#include <kernel/log.h>
#include <kernel/kernel.h>

struct kernel_struct kernel;

void kmain(void) {
  load_gdt();
  load_idt();
  init_kernel_struct();
  while (1) {
    
  } 
  return;
}
