OUTPUT_FORMAT(binary)
ENTRY(kmain)


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
}