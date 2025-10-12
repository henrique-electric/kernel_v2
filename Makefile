CC = gcc
CC_FLAGS = -m32 -nostdlib -fno-pic -ffreestanding -c -fno-stack-protector -Iinclude/
LINKER_FLAGS = -m elf_i386
OBJ = build/kernel.o build/entry.o build/gdt.o build/puts.o build/idt.o build/isr.o build/clear.o build/kb.o build/ports.o build/tables.o build/log.o \
	  build/interrupts.o

ASM = nasm

.PHONY: clean

all:
	$(ASM) -f elf32 src/kernel/entry.asm -o build/entry.o
	$(ASM) -f elf32 src/arch/isr.asm -o build/isr.o
	$(ASM) -f elf32 src/kernel/tty/kb.asm -o build/kb.o
	$(ASM) -f elf32 src/arch/ports.asm -o build/ports.o
	$(ASM) -f elf32 src/arch/tables.asm -o build/tables.o
	$(CC) $(CC_FLAGS) src/kernel/log.c -o build/log.o
	$(CC) $(CC_FLAGS) src/arch/interrupts.c -o build/interrupts.o
	$(CC) $(CC_FLAGS) src/kernel/main.c -o build/kernel.o
	$(CC) $(CC_FLAGS) src/kernel/gdt.c -o build/gdt.o
	$(CC) $(CC_FLAGS) src/kernel/tty/puts.c -o build/puts.o
	$(CC) $(CC_FLAGS) src/kernel/idt.c -o build/idt.o
	$(CC) $(CC_FLAGS) src/kernel/tty/clear.c -o build/clear.o
	ld $(LINKER_FLAGS) -T linker.ld $(OBJ) -o iso/boot/kernel.elf
	grub-mkrescue -o kernel.iso iso
	strip iso/boot/kernel.elf

mac:
	podman run --rm -v $(PWD):/kernel build-kernel

qemu:
	qemu-system-i386 kernel.iso

clean:
	@rm build/*
	@echo "Cleaned the workstation"
