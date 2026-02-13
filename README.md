# 💻 ManirOS v1.0

<p align="center">
  <img src="https://img.shields.io/badge/OS-Custom--Kernel-blue?style=for-the-badge&logo=linux" />
  <img src="https://img.shields.io/badge/Dev-Manir-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C%20%26%20ASM-yellow?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Architecture-x86-orange?style=for-the-badge" />
</p>

---

## 🚀 What is ManirOS?
ManirOS is a hobbyist **x86 text-mode operating system** built from scratch. It's not "high-performance" yet, and it's definitely not famous—it's just me exploring how computers work at the lowest level. Currently, I've managed to build a basic **Functional Terminal (Shell)** that runs directly on the hardware.

> "Writing an OS is 10% coding and 90% staring at a black screen wondering why the cursor isn't blinking.lol"

---

## ✨ Current Progress
- 🖥️ **Basic Shell:** A simple command-line interface to interact with the kernel.
- ⌨️ **Keyboard Support:** Basic PS/2 keyboard driver implementation.
- 📺 **VGA Text Mode:** Printing strings and managing the screen buffer (0xB8000).
- 🏗️ **Bootloader:** Custom ASM code to jump into 32-bit Protected Mode.

---

## 🛠️ Build & Run Setup

Based on the project structure, you need specific cross-compilation tools to avoid conflicts with your host OS headers.

### Prerequisites
* **NASM:** To assemble the bootloader.
* **GCC (i686-elf):** For compiling C code without standard libraries.
* **Binutils:** For linking the objects.
* **QEMU:** To emulate the x86 environment.

---
### 🛠️ How to Build and Run

#### 🐧 On Linux (Kali / Ubuntu)
```bash
# 1. Install Dependencies
sudo apt update && sudo apt install nasm mtools qemu-system-x86 build-essential gcc-multilib

# 2. Build & Run
make clean && make
qemu-system-i386 -kernel ManirOS.bin

####On Windows
```bash
# 1. Manual Build (using MSYS2/MinGW)
nasm -f elf32 boot.asm -o boot.o
gcc -m32 -c kernel.c -o kernel.o -ffreestanding -O0 -Wall
ld -m elf_i386 -T linker.ld -o ManirOS.bin boot.o kernel.o

# 2. Run
qemu-system-i386 -kernel ManirOS.bin