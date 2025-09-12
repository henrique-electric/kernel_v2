global isr_0

extern handler_isr
isr_0:
    pushad
    push dword 0
    call handler_isr
    add esp, 0x04
    popad
    iret
    
    