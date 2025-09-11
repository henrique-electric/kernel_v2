CC = gcc
CC_FLAGS = -m32 -nostdlib -fno-pic -ffreestanding -c 
LINKER_FLAGS = -m elf_i386
OBJ = build/kernel.o

.PHONY: clean

all: kernel.o boot
	ld $(LINKER_FLAGS) -T linker.ld $(OBJ) -o build/kernel.bin
	dd if=build/kernel.bin of=disk.img bs=512 seek=2 conv=notrunc
		

kernel.o: src/kernel/main.c
	$(CC) $(CC_FLAGS) src/kernel/main.c -o build/kernel.o

boot: src/bootloader/boot.asm
	nasm -f bin src/bootloader/boot.asm -o build/boot.bin
	dd if=build/boot.bin of=disk.img bs=512 seek=0 conv=notrunc


qemu: boot kernel.o
	qemu-system-i386 -drive file=disk.img,format=raw,if=ide,geometry=64,16,63

clean:
	@rm build/*
	@echo "Cleaned the workstation"