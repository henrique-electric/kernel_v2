global load_gdt_table
global load_idt_table
global load_tss_table
global save_gdt

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

load_tss_table:
    push ebp
    mov ebp, esp
    mov ax, 0x18
    ltr ax
    pop ebp
    ret

save_gdt:
  push ebp
  push ebx
  mov ebp, esp
  mov ebx, [ebp + 8]
  sgdt [ebx]
  pop ebp
  pop ebx
  ret
