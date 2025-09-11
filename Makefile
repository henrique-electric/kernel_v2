CC = gcc
CC_FLAGS = -m32 -nostdlib -fno-pic -ffreestanding -c 
LINKER_FLAGS = -m elf_i386
OBJ = build/kernel.o

.PHONY: clean

all: kernel.o boot
	ld $(LINKER_FLAGS) -T linker.ld $(OBJ) -o build/kernel.bin
		

kernel.o: src/kernel/main.c
	$(CC) $(CC_FLAGS) src/kernel/main.c -o build/kernel.o
	dd if=build/kernel.bin of=disk.img bs=512 seek=2 conv=notrunc

boot: src/bootloader/boot.asm
	nasm -f bin src/bootloader/boot.asm -o build/boot.bin
	dd if=build/boot.bin of=disk.img bs=512 seek=0 conv=notrunc


test_boot: boot kernel.o
	qemu-system-i386 -drive file=disk.img

clean:
	@rm build/*
	@echo "Cleaned the workstation"