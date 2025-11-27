/* link.ld - places linked sections starting at 0x7C00 (boot sector address) */
ENTRY(start)

SECTIONS
{
    . = 0x7C00;

    .text : {
        *(.text*)
    }

    .rodata : {
        *(.rodata*)
    }

    .data : {
        *(.data*)
    }

    .bss : {
        *(.bss*)
        *(COMMON)
    }
}
