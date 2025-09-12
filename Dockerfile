FROM archlinux:latest

RUN pacman -Syyuu --noconfirm && pacman -S base-devel nasm libisoburn grub mtools --noconfirm

WORKDIR /kernel

CMD ["make"]