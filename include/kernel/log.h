#ifndef KERNEL_LOG_H
#define KERNEL_LOG_H
#include <stdint.h>

enum log_type {
    ERROR,
    INFO,
};


extern void log(char *msg, uint8_t type);

#endif