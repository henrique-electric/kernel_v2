all:
	

boot: src/bootloader/boot.asm
	nasm -f bin src/bootloader/boot.asm -o build/boot.bin


test_boot: boot
	qemu-system-i386 build/boot.bin
