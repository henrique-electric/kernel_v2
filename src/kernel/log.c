#include <kernel/log.h>

extern void log(char *msg, uint8_t type) {
    uint8_t msg_color;
    switch (type)
    {
    case ERROR:
        msg_color = 0x0C;
        break;
    case INFO:
        msg_color = 0x0F;
    default:
        break;
    }

    uint16_t str_count = 0, vga_count = 0;
    char *vga_buff = (char*) 0xB8000;

    while (msg[str_count] != 0x00) {
        vga_buff[vga_count] = msg[str_count];
        vga_buff[vga_count + 1] = msg_color;

        vga_count += 2;
        str_count++;
    }
}