all: kernel.o boot
	ld -m elf_i386 -T linker.ld build/kernel.o -o kernel.o

kernel.o: src/kernel/main.c
	gcc -m32 -nostdlib -fno-pic -ffreestanding -c src/kernel/main.c -o build/kernel.o

boot: src/bootloader/boot.asm
	nasm -f bin src/bootloader/boot.asm -o build/boot.bin


test_boot: boot kernel.o
	qemu-system-i386 build/boot.bin
