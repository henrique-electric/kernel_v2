ENTRY(__entry)

SECTIONS {
    .text :
    {
        *(.text)
    }

    .data : 
    {
        *(.data)
    }

    .bss : 
    {
        *(.bss)
    }

    .multiboot :
    {
        *(.multiboot)
    }
}