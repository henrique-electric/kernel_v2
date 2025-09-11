#include <gdt.h>
#include <idt.h>
#include <libc/puts.h>

void kmain(void) {
    load_gdt();
    load_idt();
    while (1) {

    }
    return;
}