CC = gcc
CC_FLAGS = -m32 -nostdlib -fno-pic -ffreestanding -c 
LINKER_FLAGS = -m elf32
OBJ = build/kernel.o

.PHONY: clean

all: kernel.o boot
	ld $(LINKER_FLAGS) -T linker.ld $(OBJ) -o kernel.o
		

kernel.o: src/kernel/main.c
	$(CC) $(CC_FLAGS) src/kernel/main.c -o build/kernel.o

boot: src/bootloader/boot.asm
	nasm -f bin src/bootloader/boot.asm -o build/boot.bin


test_boot: boot kernel.o
	qemu-system-i386 build/boot.bin

clean:
	@rm build/*
	@echo "Cleaned the workstation"