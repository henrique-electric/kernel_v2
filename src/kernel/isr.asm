global isr_0

extern handler_isr
isr_0:
    pushad
    call handler_isr
    iret
    
    