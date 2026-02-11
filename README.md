# 💻 ManirOS v3.0

<p align="center">
  <img src="https://img.shields.io/badge/OS-Custom--Kernel-blue?style=for-the-badge&logo=linux" />
  <img src="https://img.shields.io/badge/Dev-Manir-red?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Language-C%20%26%20ASM-yellow?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Architecture-x86-orange?style=for-the-badge" />
</p>

---

## 🚀 Kya Hai ManirOS?
ManirOS ek desi, raw, aur fast x86 text-mode operating system hai. Ise zero se build kiya gaya hai (no Linux kernel, no bloatware). Isme tujhe milta hai ek mast **CLI (Shell)**, ek **Virtual File System**, aur ek **Text Editor**—seedha metal pe!

> "2 saal ki mehnat aur 1 din ka swag... Mummy, main GitHub pe famous ho gaya!" — Manir

---

## ✨ Features (Jo Public ko Chahiye)
- ⌨️ **PS/2 Keyboard Driver:** Har ek key perfectly chalti hai (Polling Mode).
- 📁 **VFS (Virtual File System):** `mkdir`, `mkfile`, aur `cd` karke folder-folder khelo.
- 📝 **Manir-Editor:** Seedha terminal pe files edit karo aur `ESC` maar ke save karo.
- 🖱️ **Hardware Cursor:** Cursor wahi blink karega jahan tu type karega.
- 🛠️ **Custom Bootloader Support:** Multiboot compliant, runs on QEMU/Bochs.

---

## 🛠️ Build & Run (Kali Linux Setup)

Pehle check kar le tere paas ye tools hain: `nasm`, `gcc`, `binutils`, `qemu-system-i386`.

### 1. Repository Clone Karo
```bash
git clone [https://github.com/tera-username/ManirOS.git](https://github.com/tera-username/ManirOS.git)
cd ManirOS