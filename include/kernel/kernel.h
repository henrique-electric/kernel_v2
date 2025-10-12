#ifndef KERNEL_DATA_H
#define KERNEL_DATA_H
#include <kernel/tty/kb.h>
#include <stdint.h>

struct kernel_struct {
    struct kernel_kb_buff kb_buff;
};

extern void init_kernel_struct(void);

extern struct kernel_struct kernel;
#endif