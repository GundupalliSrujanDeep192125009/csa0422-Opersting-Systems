#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_SIZE 100
int main() {
    int fileDescriptor;
    char data[MAX_SIZE];

    
    fileDescriptor = open("file.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fileDescriptor == -1) {
        printf("Error creating the file.\n");
        exit(1);
    }

    printf("Enter data to be written to the file (maximum %d characters):\n", MAX_SIZE);
    fgets(data, MAX_SIZE, stdin);
    if (write(fileDescriptor, data, sizeof(data)) == -1) {
        printf("Error writing to the file.\n");
        exit(1);
    }
    close(fileDescriptor);
    fileDescriptor = open("file.txt", O_RDONLY);
    if (fileDescriptor == -1) {
        printf("Error opening the file for reading.\n");
        exit(1);
    }
    ssize_t bytesRead = read(fileDescriptor, data, sizeof(data));
    if (bytesRead == -1) {
        printf("Error reading from the file.\n");
        exit(1);
    }
    printf("Data read from the file:\n%s\n", data);
    close(fileDescriptor);
    return 0;
}
