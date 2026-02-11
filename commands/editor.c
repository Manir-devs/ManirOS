/* commands/editor.c */
#include "texts"

extern File fs[MAX_FILES];

void edit_file(char* name) {
    int idx = -1;
    for(int i=0; i<MAX_FILES; i++) {
        if(fs[i].used && strcmp(fs[i].name, name) == 0 && !fs[i].is_dir) {
            idx = i; break;
        }
    }
    if(idx == -1) { print("File not found!\n"); return; }

    screen_clear();
    print("EDITOR: %s | ESC to Save\n---\n", name);
    int ptr = 0;
    while(1) {
        char c = get_char();
        if(c == 27) break;
        if(c == '\b' && ptr > 0) { ptr--; putchar('\b'); }
        else if(c >= ' ' && ptr < FILE_DATA_SIZE-1) {
            fs[idx].content[ptr++] = c;
            print("%s", (char[]){c, '\0'});
        }
    }
    fs[idx].content[ptr] = '\0';
    screen_clear();
}