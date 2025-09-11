%define MULTIBOOT_MAGIC 0x1BADB002
%define MULTIBOOT_FLAGS 0x00000003
%define MULTIBOOT_CHECKSUM -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)



section .text
align 4
multiboot:
    dd MULTIBOOT_MAGIC
    dd MULTIBOOT_FLAGS
    dd MULTIBOOT_CHECKSUM

align 16

bits 32
extern kmain
global __entry
__entry:
    mov esp, stack
    call kmain


align 4
resb 8192
stack: