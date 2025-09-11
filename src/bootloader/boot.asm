bits 16
org 0x7c00

;; Core
__init:
    jmp __load_kernel


__load_kernel:
    ;; +++++++++++++++++++++++++++++++++
    ;;   Convert LBA layout to CHS
    ;; +++++++++++++++++++++++++++++++++
    ;; Sector = (LBA % Sector) + 1
    ;; Head = (LBA / Sector) % Heads
    ;; Cylinder = LBA / (Sector * Heads)


    mov ax, 0x1000      ; Where to load the kernel
    mov es, ax          ; set ES segment register to 0x1000 (where kernel will get loaded)
    mov bx, 0x0000      ; 0x0000 offset on the 0x1000 segment 


    mov ah, 0x02    ; Read disk code
    mov al, 0x01    ; Read one sector
    mov ch, 0x00    ; Cylinder 0
    mov cl, 0x02    ; Sector two
    mov dh, 0x00    ; Head 0
    mov dl, 0x80    ; Default disk
    int 0x13

    cmp ah, 0
    jne .err_read

    mov si, load_success_msg
    call __puts
    jmp __trap
    ;; TODO
    .err_read:
        mov si, error_load_kernel_msg
        call __puts
        jmp __trap

__load_gdt:
    cli
    lgdt [gdt_descriptor]
    mov eax, cr0
    or eax, 1
    mov cr0, eax
    jmp 0x08:__main

gdt_table_start:
    null_entry:
        dq 0

    code_segment:
        dw 0xffff       ; Limit
        dw 0x0000        ; base
        db 0x00         ; base
        db 0x9A  ; access byte
        db 0xCF     ; limit + flags
        db 0x00         ; base

    data_segment:
        dw 0xffff       ; limit
        dw 0x0000        ; base
        db 0x00         ; base
        db 0b10010010  ; access byte
        db 0b1111100   ; limit + flags
        db 0x00         ; base
gdt_table_end:

gdt_descriptor:
    dw gdt_table_end - gdt_table_start - 1
    dd gdt_table_start
;;

;; Protected mode

bits 32
__main:
    mov ax, 0x10
    mov ds, ax
    mov ss, ax
    jmp __trap
    ;; TODO

;; utils functions
__puts:
    lodsb
    cmp al, 0x0
    je .end
    mov ah, 0x0e
    int 0x10
    jmp __puts
.end:
    ret
;;

;; Trap the program flow
__trap:
    jmp __trap
;;
error_load_kernel_msg: db "Error loading the kernel", 0
boot_entry_msg: db "Hello user!, starting the boot now : )", 0xa, 0, 
loading_kernel_msg: db "Loading kernel on memory", 0xa, 0,
load_success_msg: db "Loaded Kernel", 0
loading_gdt_msg: db "Setting Global Descriptor Table", 0xA, 0 

times 510 - ($ - $$) db 0
dw 0xAA55