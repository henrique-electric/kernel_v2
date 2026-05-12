; ==============================================================================
; @file tables.asm
; @brief Low-level functions to load CPU descriptor tables (GDT, IDT, TSS).
;
; This assembly module provides the actual CPU instructions (`lgdt`, `lidt`, `ltr`)
; and necessary CPU state updates to apply the descriptor tables built by C code.
; ==============================================================================

global load_gdt_table
global load_idt_table
global load_tss_table
global save_gdt

section .text

; ------------------------------------------------------------------------------
; @brief Loads the Interrupt Descriptor Table (IDT).
;
; @param Pointer to the `idtr` struct (passed via stack at [ebp + 8]).
; ------------------------------------------------------------------------------
load_idt_table:
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8] ; Reiceives a 32bit pointer pointing to the IDTR structure
    lidt [eax]
    pop ebp
    sti                ; Enable interrupts after loading IDT
    ret

; ------------------------------------------------------------------------------
; @brief Loads the Global Descriptor Table (GDT) and updates segment registers.
;
; @param Pointer to the `gdt_table` struct (passed via stack at [ebp + 8]).
; ------------------------------------------------------------------------------
load_gdt_table:
    cli
    push ebp
    mov ebp, esp
    mov eax, [ebp + 8] ; Receives a 32bit pointer pointing to the GDTR structure
    lgdt [eax]
    
    ; Perform a far jump to reload the CS register (Code Segment = 0x08)
    jmp 0x08:.load_data_segs

.load_data_segs:
    ; Now reload the other data segment registers with the Kernel Data Segment (0x10)
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    pop ebp
    ret

; ------------------------------------------------------------------------------
; @brief Loads the Task State Segment (TSS) into the task register.
; ------------------------------------------------------------------------------
load_tss_table:
    push ebp
    mov ebp, esp
    mov ax, 0x18 ; The TSS table lives at segment offset 0x18 in the GDT
    ltr ax       ; Load Task Register
    pop ebp
    ret

; ------------------------------------------------------------------------------
; @brief Stores the current GDTR into the provided memory block.
;
; @param Pointer to a 6-byte memory block (passed via stack at [ebp + 8]).
; ------------------------------------------------------------------------------
save_gdt:
  push ebp
  mov ebp, esp
  push ebx

  mov ebx, [ebp + 8]
  sgdt [ebx] ; Save the GDTR at the address passed as parameter.

  pop ebx
  pop ebp
  ret
