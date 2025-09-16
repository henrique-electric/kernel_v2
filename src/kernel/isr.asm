global isr_0
global isr_21h
global exceptions_default


extern handler_isr
isr_0:
    pushad
    push dword 0
    call handler_isr
    add esp, 0x04 
    popad
    iret
    
isr_1:
  pushad
  push dword 0x01 
  call handler_isr
  add esp, 0x04
  popad
  iret

isr_21h:
  pushad
  push dword 0x21
  call handler_isr
  add esp, 0x04
  popad
  iret

exceptions_default:
  pushad
  push dword 0xAF
  call handler_isr
  add esp, 0x04
  popad
  iret
