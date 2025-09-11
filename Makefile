CC = gcc
CC_FLAGS = -m32 -nostdlib -fno-pic -ffreestanding -c -fno-stack-protector
LINKER_FLAGS = -m elf_i386
OBJ = build/kernel.o build/entry.o
ASM = nasm

.PHONY: clean

all: kernel.o
	ld $(LINKER_FLAGS) -T linker.ld $(OBJ) -o iso/boot/kernel.elf
	grub-mkrescue -o kernel.iso iso 
		

kernel.o: src/kernel/main.c
	$(ASM) -f elf32 src/kernel/entry.asm -o build/entry.o
	$(CC) $(CC_FLAGS) src/kernel/main.c -o build/kernel.o

qemu: boot kernel.o
	qemu-system-i386 -drive file=disk.img,format=raw

clean:
	@rm build/*
	@echo "Cleaned the workstation"