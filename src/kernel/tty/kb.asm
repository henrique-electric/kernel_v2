global get_press
get_press:
    mov dx, 0x60
    in al, dx 
    ret
