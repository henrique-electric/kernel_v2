#include <kernel/tty/kb.h>
#include <kernel/kernel.h>
#include <asm_wrappers.h>
#include <kernel/log.h>

#define CURRENT_BUFF_INDEX kernel.kb_buff.index

void handle_key_press(void) {
    log("Key pressed", INFO);
    //outb(0x20, 0x20);
    return;
}
