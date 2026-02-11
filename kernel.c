#include "texts"

extern void init_fs();
extern void list_files();
extern void make_entry(char* name, int is_dir);
extern void remove_entry(char* name);
extern void edit_file(char* name);
extern void change_dir(char* name);
extern int current_dir_idx;
extern File fs[];

void get_input(char* buf) {
    int i = 0;
    while(1) {
        char c = get_char();
        if(c == '\n') { buf[i] = '\0'; print("\n"); break; }
        if(c == '\b' && i > 0) { i--; putchar('\b'); }
        else if(c >= ' ' && i < 50) {
            buf[i++] = c;
            char s[2] = {c, '\0'}; print("%s", s);
        }
    }
}

void show_help() {
    print("Available Commands:\n");
    print("  help               - Show this menu\n");
    print("  ls                 - List files in current dir\n");
    print("  mkdir <name>       - Create a directory\n");
    print("  mkfile <name>      - Create a text file\n");
    print("  cd <name>          - Change directory (use '..' to go back)\n");
    print("  edfile <name>      - Edit a file (ESC to save)\n");
    print("  rm <name>          - Delete a file or directory\n");
    print("  clear              - Clear screen\n");
}

void kernel_main() {
    screen_clear();
    init_fs();
    print("ManirOS 3.0 CLI Booted. Type 'help' for commands.\n");

    char cmd[64];
    while(1) {
        print("manir@os:/%s# ", fs[current_dir_idx].name);
        get_input(cmd);

        if(strcmp(cmd, "help") == 0) show_help();
        else if(strcmp(cmd, "ls") == 0) list_files();
        else if(strcmp(cmd, "clear") == 0) screen_clear();
        else if(cmd[0]=='m' && cmd[1]=='k' && cmd[2]=='d') make_entry(cmd+6, 1);
        else if(cmd[0]=='m' && cmd[1]=='k' && cmd[2]=='f') make_entry(cmd+7, 0);
        else if(cmd[0]=='c' && cmd[1]=='d') change_dir(cmd+3);
        else if(cmd[0]=='r' && cmd[1]=='m') remove_entry(cmd+3);
        else if(cmd[0]=='e' && cmd[1]=='d') edit_file(cmd+7);
        else if(cmd[0] != '\0') print("Bad command. Type 'help'.\n");
    }
}