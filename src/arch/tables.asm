global load_gdt_table
global load_idt_table
extern print_dec

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
    jmp 0x08:.far_jmp_label ; Update code segment register
    
  .far_jmp_label:
    pop ebp
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    ret
