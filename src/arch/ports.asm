global outb
global inb

section .text
inb:
    push ebp
    mov ebp, esp
    push dx

    mov dx, [ebp + 8]    
    in ax, dx

    pop dx
    pop ebp
    ret

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