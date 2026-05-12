; ==============================================================================
; @file ports.asm
; @brief Low-level port I/O communication functions (inb, outb).
;
; These functions allow the kernel to interact with hardware mapped to the
; standard x86 I/O ports (e.g., PIC, Keyboard Controller, VGA ports).
; They follow the standard C calling convention (cdecl) to be callable from C.
; ==============================================================================

global outb
global inb

section .text

; ------------------------------------------------------------------------------
; @brief Reads data from the specified I/O port.
; 
; @param port (Stack [ebp + 8]): The 16-bit port number to read from.
; @return The data read from the port (returned in the ax register).
; ------------------------------------------------------------------------------
inb:
    push ebp
    mov ebp, esp
    push dx

    mov dx, [ebp + 8]    
    in ax, dx

    pop dx
    pop ebp
    ret

; ------------------------------------------------------------------------------
; @brief Writes data to the specified I/O port.
;
; @param data (Stack [ebp + 8]): The data to write to the port.
; @param port (Stack [ebp + 12]): The 16-bit port number to write to.
; ------------------------------------------------------------------------------
outb:
    push ebp
    mov ebp, esp
    push dx
    push ax

    mov dx, [ebp + 12]
    mov ax, [ebp + 8]
    out dx, ax

    pop ax
    pop dx
    pop ebp
    ret