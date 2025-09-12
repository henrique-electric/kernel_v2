#include <stdint.h>


void clear(void) {
    char *vga = (char*) 0xB8000;
    while ((uintptr_t) vga != (uintptr_t) 0xBFFFF) {
        *vga = 0x00;
        vga++;
    }
}