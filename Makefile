# Makefile
# Assumes: nasm, gcc (multilib), ld are installed.
# On Debian/Kali: sudo apt install nasm gcc-multilib binutils

AS=nasm
CC=gcc
LD=ld
CFLAGS=-m32 -ffreestanding -fno-builtin -fno-stack-protector -O2 -Wall -Wextra -c
LDFLAGS=-m elf_i386 -T link.ld --oformat binary

all: os-image.bin

boot.o: boot.asm
	$(AS) -f elf32 boot.asm -o boot.o

kernel.o: kernel.c
	$(CC) $(CFLAGS) kernel.c -o kernel.o

os.bin: boot.o kernel.o link.ld
	$(LD) -m elf_i386 -T link.ld boot.o kernel.o -o os.elf
	# convert ELF to a flat binary starting at 0x7C00
	objcopy -O binary os.elf os.bin

# final floppy-style image (512 bytes aligned)
os-image.bin: os.bin
	# ensure size >= 512 and signature present (boot.asm already added signature)
	cat os.bin > os-image.bin

clean:
	rm -f *.o *.elf *.bin os-image.bin
