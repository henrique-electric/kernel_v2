#include <kernel/kernel.h>
#include <kernel/mem/mem.h>

void init_kernel_struct(void) {
    memset(&kernel, 0x00, sizeof(struct kernel_struct));

}