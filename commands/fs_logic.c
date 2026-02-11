#include "texts"

File fs[MAX_FILES];
int current_dir_idx = 0;

void init_fs() {
    for(int i=0; i<MAX_FILES; i++) fs[i].used = 0;
    strcpy(fs[0].name, "root");
    fs[0].is_dir = 1;
    fs[0].used = 1;
    fs[0].parent_idx = 0;
}

void list_files() {
    print("Listing directory contents:\n");
    for(int i=0; i<MAX_FILES; i++) {
        if(fs[i].used && i != current_dir_idx && fs[i].parent_idx == current_dir_idx) {
            if(fs[i].is_dir) print("[%s]  ", fs[i].name);
            else print("%s  ", fs[i].name);
        }
    }
    print("\n");
}

void make_entry(char* name, int is_dir) {
    if(strlen(name) == 0) return;
    for(int i=0; i<MAX_FILES; i++) {
        if(!fs[i].used) {
            strcpy(fs[i].name, name);
            fs[i].is_dir = is_dir;
            fs[i].used = 1;
            fs[i].parent_idx = current_dir_idx;
            fs[i].content[0] = '\0';
            print("OK.\n");
            return;
        }
    }
}

void change_dir(char* name) {
    if(strcmp(name, "..") == 0) {
        current_dir_idx = fs[current_dir_idx].parent_idx;
        return;
    }
    for(int i=0; i<MAX_FILES; i++) {
        if(fs[i].used && fs[i].is_dir && strcmp(fs[i].name, name) == 0) {
            current_dir_idx = i;
            return;
        }
    }
    print("Directory not found!\n");
}

void remove_entry(char* name) {
    for(int i=0; i<MAX_FILES; i++) {
        if(fs[i].used && strcmp(fs[i].name, name) == 0 && fs[i].parent_idx == current_dir_idx) {
            fs[i].used = 0;
            print("Deleted.\n");
            return;
        }
    }
    print("Not found.\n");
}