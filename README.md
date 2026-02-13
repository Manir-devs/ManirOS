# 💻 ManirOS v3.0

<p align="center">
  <img src="https://img.shields.io/badge/OS-Custom--Kernel-blue?style=for-the-badge&logo=linux" />
  <img src="https://img.shields.io/badge/Dev-Manir-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C%20%26%20ASM-yellow?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Architecture-x86-orange?style=for-the-badge" />
</p>

---

## 🚀 What is ManirOS?
ManirOS is a native, raw, and high-performance **x86 text-mode operating system** built from scratch. No Linux kernel, no bloatware—just pure code running directly on the metal. It features a custom **CLI Shell**, a **Virtual File System (VFS)**, and an integrated **Text Editor**.

> "2 years of grind, 1 day of swag... Mom, I'm finally on GitHub!" — Manir

---

## ✨ Features
- ⌨️ **PS/2 Keyboard Driver:** Fully functional keyboard support using Polling Mode.
- 📁 **Virtual File System (VFS):** Manage your files and directories with `mkdir`, `mkfile`, and `cd`.
- 📝 **Manir-Editor:** A built-in terminal-based editor with `ESC` to save/exit functionality.
- 🖱️ **Hardware Cursor Support:** Real-time hardware cursor blinking at the point of interaction.
- 🛠️ **Multiboot Compliant:** Seamlessly runs on industry-standard emulators like **QEMU** and **Bochs**.

---

## 🛠️ Build & Run Setup

### Prerequisites
Ensure you have the following tools installed:
- **Assembler:** `nasm`
- **Compiler:** `gcc` (i686-elf-gcc recommended for cross-compiling)
- **Build Tool:** `make`
- **Emulator:** `qemu-system-i386`

---

### 🐧 On Linux (Kali/Ubuntu/Debian)

1. **Install Dependencies:**
   ```bash
   sudo apt update
   sudo apt install nasm gcc make qemu-system-x86 binutils