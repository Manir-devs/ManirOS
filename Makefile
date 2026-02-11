CC = gcc -m32 -ffreestanding -O0 -I./libraries/include
LD = ld -m elf_i386 -T linker.ld
AS = nasm -f elf32

BUILD_DIR = build
OBJS = $(BUILD_DIR)/boot.o \
       $(BUILD_DIR)/texts.o \
       $(BUILD_DIR)/fs_logic.o \
       $(BUILD_DIR)/editor.o \
       $(BUILD_DIR)/kernel.o

all: $(BUILD_DIR) $(BUILD_DIR)/kernel.bin
	qemu-system-i386 -kernel $(BUILD_DIR)/kernel.bin

$(BUILD_DIR):
	mkdir -p build

$(BUILD_DIR)/kernel.bin: $(OBJS)
	$(LD) -o $@ $(OBJS)

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/texts.o: libraries/src/texts.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/fs_logic.o: commands/fs_logic.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/editor.o: commands/editor.c
	$(CC) -c $< -o $@

$(BUILD_DIR)/boot.o: boot.s
	$(AS) boot.s -o $@

clean:
	rm -rf $(BUILD_DIR)