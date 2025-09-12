#include <libc/puts.h>

uint32_t vga_count = 0;

void puts(char *str) {
    char *vga_buff = (char*) 0xB8000;

    uint16_t str_count = 0;
    while (str[str_count] != 0x00) {
        if (str[str_count] == '\n') {
            str[str_count] = ' ';
            vga_count  = ((((vga_count - 1) + (80-1)*2) / (80*2)) * (80*2)) - 2;
        }

        vga_buff[vga_count] = str[str_count];
        vga_buff[vga_count + 1] = 0x07;
        str_count++;
        vga_count +=2;
    }
}