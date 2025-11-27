; boot.asm
; simple boot sector that sets up stack and CALLs kernel_main (provided by C)
; org at 0x7C00 so we can directly boot from this binary
[org 0x7C00]
bits 16

start:
    cli                 ; make sure interrupts off while we set things up
    xor ax, ax
    mov ss, ax
    mov sp, 0x7C00      ; simple stack (you can change)
    sti

    ; set data segments to 0 for simplicity (real-mode)
    mov ax, 0x0000
    mov ds, ax
    mov es, ax

    ; call the C kernel entry (symbol provided by kernel.c)
    ; the symbol must be available at link time
    call kernel_main

hang:
    cli
    hlt
    jmp hang

; boot signature (must be at offset 510..511)
times 510-($-$$) db 0
dw 0xAA55
