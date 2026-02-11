#include "texts"

volatile char* vga = (volatile char*)0xB8000;
int cursor_pos = 0;

unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outb(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

void update_cursor(int x, int y) {
    unsigned short pos = y * 80 + x;
    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos & 0xFF));
    outb(0x3D4, 0x0E);
    outb(0x3D5, (unsigned char)((pos >> 8) & 0xFF));
}

void screen_clear() {
    for (int i = 0; i < 80 * 25 * 2; i += 2) {
        vga[i] = ' ';
        vga[i+1] = 0x07;
    }
    cursor_pos = 0;
    update_cursor(0, 0);
}

void putchar(char c) {
    if (c == '\n') {
        cursor_pos += 80 - (cursor_pos % 80);
    } else if (c == '\b') {
        if (cursor_pos > 0) {
            cursor_pos--;
            vga[cursor_pos * 2] = ' ';
            vga[cursor_pos * 2 + 1] = 0x07;
        }
    } else {
        vga[cursor_pos * 2] = c;
        vga[cursor_pos * 2 + 1] = 0x07;
        cursor_pos++;
    }
    update_cursor(cursor_pos % 80, cursor_pos / 80);
}

void print(char* format, ...) {
    va_list args;
    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            if (format[i] == 's') {
                char* s = va_arg(args, char*);
                while (*s) putchar(*s++);
            }
        } else {
            putchar(format[i]);
        }
    }
    va_end(args);
}

// ... strcmp, strcpy, strlen, get_char wahi rahenge jo pehle the ...
int strcmp(char* s1, char* s2) {
    while (*s1 && (*s1 == *s2)) { s1++; s2++; }
    return *(unsigned char*)s1 - *(unsigned char*)s2;
}

void strcpy(char* dest, char* src) {
    while ((*dest++ = *src++));
}

int strlen(char* s) {
    int len = 0;
    while(s[len]) len++;
    return len;
}

unsigned char keyboard_map[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0,
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0, '\\', 
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
};

char get_char() {
    while(!(inb(0x64) & 1));
    unsigned char code = inb(0x60);
    if(code & 0x80) return 0;
    return keyboard_map[code];
}