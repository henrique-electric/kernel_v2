#include <libc/puts.h>

void puts(char *str) {
    char *vga_buff = (char*) 0xB8000;

    uint16_t str_count = 0;
    uint16_t vga_count = 0;
    while (str[str_count] != 0x00) {
        vga_buff[vga_count] = str[str_count];
        vga_buff[vga_count + 1] = 0x01;
        str_count++;
        vga_count +=2;
    }
}