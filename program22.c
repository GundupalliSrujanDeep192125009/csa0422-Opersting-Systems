#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3

struct User {
    char name[20];
    struct File {
        char name[20];
    } files[MAX_FILES];
};

struct User users[MAX_USERS];

void create_user_directory(char* username) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (users[i].name[0] == '\0') {
            strcpy(users[i].name, username);
            printf("User directory '%s' created.\n", username);
            break;
        }
    }
    if (i == MAX_USERS) {
        printf("Maximum number of users reached. Unable to create user directory.\n");
    }
}

void create_file(char* username, char* filename) {
    int i;
    for (i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].name, username) == 0) {
            int j;
            for (j = 0; j < MAX_FILES; j++) {
                if (users[i].files[j].name[0] == '\0') {
                    strcpy(users[i].files[j].name, filename);
                    printf("File '%s' created in user directory '%s'.\n", filename, username);
                    break;
                }
            }
            if (j == MAX_FILES) {
                printf("Maximum number of files reached for user directory '%s'. Unable to create file.\n", username);
            }
            break;
        }
    }
    if (i == MAX_USERS) {
        printf("User directory '%s' does not exist. Unable to create file.\n", username);
    }
}

int main() {
    int i;

    // Initialize users
    for (i = 0; i < MAX_USERS; i++) {
        users[i].name[0] = '\0';
        for (int j = 0; j < MAX_FILES; j++) {
            users[i].files[j].name[0] = '\0';
        }
    }

    // Create user directories
    create_user_directory("user1");
    create_user_directory("user2");
    create_user_directory("user3");

    // Create files in user directories
    create_file("user1", "file1");
    create_file("user1", "file2");
    create_file("user1", "file3");
    create_file("user2", "file4");
    create_file("user2", "file5");
    create_file("user3", "file6");

    return 0;
}
