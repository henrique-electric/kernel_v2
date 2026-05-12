FROM --platform=linux/amd64 archlinux:latest

RUN sed -i -e 's/^#DisableSandbox/DisableSandbox/' /etc/pacman.conf && \
    pacman -Syyuu --noconfirm && \
    pacman -S base-devel nasm libisoburn grub mtools clang --noconfirm

WORKDIR /kernel

CMD ["make"]
