FROM --platform=x86_64 archlinux:latest

RUN pacman -Syyuu --noconfirm && pacman -S base-devel nasm libisoburn grub mtools clang --noconfirm

WORKDIR /kernel

CMD ["make"]
