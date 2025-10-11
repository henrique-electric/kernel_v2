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
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8]
    lgdt [eax]
    pop ebp
    ret