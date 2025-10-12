#include <kernel/mem/mem.h>

void memset(void *addr, char value, size_t len) {
    char offset = 0;
    for (size_t i = 0; i < len; i++) {
        *((char *) addr + offset) = value;
        offset++;
    }
}