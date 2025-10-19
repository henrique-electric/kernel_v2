global load_gdt_table
global load_idt_table

section .text
load_idt_table:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    lidt [eax]
    pop ebp
    sti
    ret

load_gdt_table:
    cli
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    lgdt [eax]
    pop ebp
    mov ax, 0x08
    mov cs, ax
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    ret
