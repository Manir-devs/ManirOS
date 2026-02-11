#include "input"
#include "texts" // Taaki hum input lete waqt print kar sakein (Echo)

unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

// Simple ScanCode to ASCII Table
char get_ascii(unsigned char scancode) {
    switch(scancode) {
        case 0x1E: return 'a';
        case 0x30: return 'b';
        case 0x2E: return 'c';
        case 0x20: return 'd';
        case 0x12: return 'e';
        case 0x21: return 'f';
        case 0x22: return 'g';
        case 0x23: return 'h';
        case 0x17: return 'i';
        case 0x24: return 'j';
        case 0x25: return 'k';
        case 0x26: return 'l';
        case 0x32: return 'm';
        case 0x31: return 'n';
        case 0x18: return 'o';
        case 0x19: return 'p';
        case 0x10: return 'q';
        case 0x13: return 'r';
        case 0x1F: return 's';
        case 0x14: return 't';
        case 0x16: return 'u';
        case 0x2F: return 'v';
        case 0x11: return 'w';
        case 0x2D: return 'x';
        case 0x15: return 'y';
        case 0x2C: return 'z';
        case 0x39: return ' '; // Spacebar
        case 0x1C: return '\n'; // Enter Key
        default: return 0;
    }
}

void scan(char* buffer) {
    int i = 0;
    while (1) {
        // Wait for keyboard status bit 0 (Data ready)
        while (!(inb(0x64) & 1));
        
        unsigned char scancode = inb(0x60);

        // Scancode > 0x80 matlab key release hui hai, humein sirf press chahiye
        if (scancode & 0x80) continue;

        char c = get_ascii(scancode);
        
        if (c == '\n') { // Enter dabane pe input khatam
            buffer[i] = '\0';
            break;
        } else if (c != 0) {
            buffer[i] = c;
            // "Echo" - Screen pe dikhao jo type kiya
            print("%s", (char[]){c, '\0'}); 
            i++;
        }
    }
}