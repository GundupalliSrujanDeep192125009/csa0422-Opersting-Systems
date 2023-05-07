#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILENAME 20

struct Directory {
    char name[MAX_FILENAME];
    char files[MAX_FILES][MAX_FILENAME];
    int num_files;
};

void create_directory(struct Directory* dir, char* name) {
    strcpy(dir->name, name);
    dir->num_files = 0;
}

void add_file(struct Directory* dir, char* filename) {
    if (dir->num_files >= MAX_FILES) {
        printf("Error: directory is full\n");
        return;
    }
    strcpy(dir->files[dir->num_files], filename);
    dir->num_files++;
}

void print_directory(struct Directory* dir) {
    printf("Directory: %s\n", dir->name);
    printf("Files:\n");
    for (int i = 0; i < dir->num_files; i++) {
        printf("- %s\n", dir->files[i]);
    }
}

int main() {
    struct Directory cse;
    char directory_name[MAX_FILENAME] = "CSE";
    char file1[MAX_FILENAME] = "A";
    char file2[MAX_FILENAME] = "B";
    char file3[MAX_FILENAME] = "C";

    create_directory(&cse, directory_name);
    add_file(&cse, file1);
    add_file(&cse, file2);
    add_file(&cse, file3);
    print_directory(&cse);

    return 0;
}
