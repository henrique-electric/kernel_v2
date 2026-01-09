global debug
global exceptions_default
global acknowledge_isr
extern handler_isr

%define DUMMY_CODE 0xFAFAFAFA

; Macro to expand the interrupt definition
%macro handle_irq 1
    isr_%+%1:
    cli
    push dword %1
    call handler_isr
    add esp, 0x08
    call acknowledge_isr
    iretd
%endmacro

%macro handle_irq_noerr 1
  isr_%1:
    cli
    push dword DUMMY_CODE
    push dword %1
    call handler_isr

    add esp, 0x08 ; pop the vector code and dummy code

    call acknowledge_isr
    iretd
%endmacro


; Export globally the interrupts
%assign i 0
%rep 48 
    global isr_%+i
    %assign i i+1
%endrep


section .text

acknowledge_isr:
  push dx
  push ax
  mov ax, 0x20
  mov dx, 0x20
  out dx, ax
  pop dx
  pop ax
  ret


; ========== Exceptions ===========
handle_irq_noerr 0 ; divide by 0 error
handle_irq_noerr 1 ;Single-step / debug exception
handle_irq_noerr 2 ;Non-maskable interrupt
handle_irq_noerr 3 ; Breakpoint

handle_irq_noerr 4 ; Overflow
handle_irq_noerr 5 ; Bound range
handle_irq_noerr 6 ; Invalid opcode
handle_irq_noerr 7 ; FPU not available
handle_irq_noerr 9 ; Reserved
handle_irq_noerr 15 ; Reserved
handle_irq_noerr 16 ; MF x87 Floating-Point Error
handle_irq_noerr 18 ; MC Machine Check
handle_irq_noerr 20 ; VE Virtualization Exception

handle_irq 8 ; Double fault
handle_irq 10 ; Invalide TSS
handle_irq 11 ; Segment not loaded
handle_irq 12 ; Stack segment error
handle_irq 13 ; General protection fault
handle_irq 14 ; Page fault
handle_irq 17 ; AC Alignment Check
handle_irq 19 ; XM SIMD Floating-Point Exception

; Reserved
handle_irq_noerr 21
handle_irq_noerr 22
handle_irq_noerr 23
handle_irq_noerr 24
handle_irq_noerr 25
handle_irq_noerr 26
handle_irq_noerr 27
handle_irq_noerr 28
handle_irq_noerr 29
handle_irq_noerr 30
handle_irq_noerr 31
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
