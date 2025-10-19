global debug
global exceptions_default
extern handler_isr

; Macro to expand the interrupt definition
%macro handle_irq 1
    isr_%+%1:
    cli
    pushad
    push dword %1
    call handler_isr
    add esp, 0x04 
    popad
    sti
    iretd

%endmacro

; Export globally the interrupts
%assign i 0
%rep 48
    global isr_%+i
    %assign i i+1
%endrep


section .text

; ========== Exceptions ===========
handle_irq 0 ; divide by 0 error
handle_irq 1 ;Single-step / debug exception
handle_irq 2 ;Non-maskable interrupt
handle_irq 3 ; Breakpoint
handle_irq 4 ; Overflow
handle_irq 5 ; Bound range
handle_irq 6 ; Invalid opcode
handle_irq 7 ; FPU not available
handle_irq 8 ; Double fault
handle_irq 9 ; Reserved
handle_irq 10 ; Invalide TSS
handle_irq 11 ; Segment not loaded
handle_irq 12 ; Stack segment error
handle_irq 13 ; General protection fault
handle_irq 14 ; Page fault
handle_irq 15 ; Reserved
handle_irq 16 ; MF x87 Floating-Point Error
handle_irq 17 ; AC Alignment Check
handle_irq 18 ; MC Machine Check
handle_irq 19 ; XM SIMD Floating-Point Exception
handle_irq 20 ; VE Virtualization Exception

; Reserved
handle_irq 21
handle_irq 22
handle_irq 23
handle_irq 24
handle_irq 25
handle_irq 26
handle_irq 27
handle_irq 28
handle_irq 29
handle_irq 30
handle_irq 31
; =============================================

; ========= Hardware interrupts ==========
handle_irq 32 ; System timer
handle_irq 33 ; Keyboard
handle_irq 34 ; Chained PIC
handle_irq 35 ; COM2
handle_irq 36 ; COM1
handle_irq 37 ; Sound card / LPT2
handle_irq 38 ; Floppy disk
handle_irq 39 ; Parallel port
handle_irq 40 ; Real-time clock
handle_irq 41 ; Legacy redirect
handle_irq 42 ; Reserved
handle_irq 43 ; Reserved
handle_irq 44 ; Mouse PS/2
handle_irq 45 ; FPU
handle_irq 46 ; Primary ATA disk
handle_irq 47 ; Secondary ATA disk
; =======================================

finish_stub:
