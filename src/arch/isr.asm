global isr_0
global isr_1
global isr_2
global isr_3
global isr_4
global isr_5
global isr_6
global isr_7
global isr_8
global isr_9
global isr_10
global isr_11
global debug
global exceptions_default
extern handler_isr

%macro handle_irq 1
    pushad
    push dword %1
    call handler_isr
    jmp finish_stub
%endmacro


section .text

; divide by 0 error
isr_0:
  handle_irq(0)
    
;Single-step / debug exception
isr_1:
  handle_irq(1)

;Non-maskable interrupt
isr_2:
  handle_irq(2)

; Breakpoint
isr_3:
  handle_irq(3)

; Overflow
isr_4:
  handle_irq(4)

; Bound range
isr_5:
  handle_irq(5)

; Invalid opcode
isr_6:
  handle_irq(6)

; FPU not available
isr_7:
  handle_irq(7)

; Double fault
isr_8:
  handle_irq(8)

; Reserved
isr_9:
  handle_irq(9)

; Invalide TSS
isr_10:
  handle_irq(10)

; Segment not loaded
isr_11:
  handle_irq(11)

; Stack segment error
isr_12:
  handle_irq(12)

; General protection fault
isr_13:
  handle_irq(13)

; Page fault
isr_14:
  handle_irq(14)

; Reserved
isr_15:
  handle_irq(15)

; MF x87 Floating-Point Error
isr_16:
  handle_irq(16)

; AC Alignment Check
isr_17:
  handle_irq(17)
  
; MC Machine Check
isr_18:
  handle_irq(18)

; XM SIMD Floating-Point Exception
isr_19:
  handle_irq(19)

; VE Virtualization Exception
isr_20:
  handle_irq(20)

finish_stub:
  add esp, 0x04
  popad
  iret
