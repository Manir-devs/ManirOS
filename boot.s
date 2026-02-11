; ---------------------------------------------------------
; FILE: boot.s
; ---------------------------------------------------------
[BITS 32]

MBOOT_HEADER_MAGIC  equ 0x1BADB002
MBOOT_HEADER_FLAGS  equ 1 << 0 | 1 << 1 | 1 << 2 ; Flag 2 is for graphics
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)

section .multiboot
    align 4
    dd MBOOT_HEADER_MAGIC
    dd MBOOT_HEADER_FLAGS
    dd MBOOT_CHECKSUM
    ; Graphics fields (Requesting 1024x768x32 or similar)
    dd 0, 0, 0, 0, 0
    dd 0 ; 0 = Linear Graphics Mode
    dd 640 ; Width
    dd 480 ; Height
    dd 32  ; Depth (Bits per pixel)

section .text
global _start
extern kernel_main

_start:
    mov esp, stack_top
    call kernel_main
    hlt

section .bss
align 16
stack_bottom: resb 16384
stack_top: