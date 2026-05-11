global load_gdt_table
global load_idt_table
global load_tss_table
global save_gdt

section .text
load_idt_table:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8] ; This function receives a 32bit pointer as parameter that points where the IDT structure lives in memory
    lidt [eax]
    pop ebp
    sti
    ret

load_gdt_table:
    cli
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8] ; This function receives a 32bit pointer as parameter that points where the GDT structure lives in memory
    lgdt [eax]
    
    ; Perform a far jump to reload the CS register and load teh correct data segments to point to the correct entry on the GDT
    jmp 0x08:.load_data_segs

.load_data_segs:
    ; Now reload the other data segment registers
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    pop ebp
    ret

load_tss_table:
    push ebp
    mov ebp, esp
    mov ax, 0x18 ; The TSS table lives on the entry 0x18 in the GDT
    ltr ax
    pop ebp
    ret


; This function saves teh GDT table into an adress provided
save_gdt:
  push ebp
  mov ebp, esp
  push ebx

  mov ebx, [ebp + 8]
  sgdt [ebx] ; Save the GDT table at the address passed as parameter.

  pop ebx
  pop ebp
  ret
