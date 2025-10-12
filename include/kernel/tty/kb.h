#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdint.h>


#define KERNEL_KB_BUFF_LEN 512

struct kernel_kb_buff {
    char buff[KERNEL_KB_BUFF_LEN];
    uint16_t index;
};

extern char *get_kb_buff(void);
extern void put_to_buff(char character);

#endif