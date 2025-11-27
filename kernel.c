/* kernel.c
   Very small freestanding kernel function. No stdlib used.
   This file defines the symbol kernel_main which the bootloader CALLs.
*/

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

void print_char(char c) {
    /* BIOS teletype via int 0x10 AH=0x0E.
       We use inline asm to call BIOS from C (real mode, 16-bit style asm).
       Constraint style kept minimal so it's readable.
    */
    asm volatile (
        "movb $0x0E, %%ah\n\t"
        "movb %%al, %%al\n\t"   /* AL already has char via constraint */
        "int $0x10\n\t"
        :
        : "a"(c)    /* put character in AL via eax */
        : "ah"
    );
}

/* kernel_main: symbol called by bootloader */
void kernel_main(void) {
    const char *s = "Hello, World from Kernel!\r\n";
    const char *p = s;
    while (*p) {
        print_char(*p++);
    }

    /* infinite loop to stop */
    for (;;) {
        asm volatile ("hlt");
    }
}
