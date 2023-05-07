#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_odds() {
    printf("Child process for odd numbers with PID: %d\n", getpid());
    for (int i = 1; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_evens() {
    printf("Child process for even numbers with PID: %d\n", getpid());
    for (int i = 2; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_multiples_of_3() {
    printf("Child process for multiples of 3 with PID: %d\n", getpid());
    for (int i = 3; i <= 30; i += 3) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_multiples_of_5() {
    printf("Child process for multiples of 5 with PID: %d\n", getpid());
    for (int i = 5; i <= 50; i += 5) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    
    for (int i = 0; i < 4; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            
            fprintf(stderr, "Fork failed\n");
            exit(1);
        } else if (pid == 0) {
            
            switch (i) {
                case 0:
                    print_odds();
                    break;
                case 1:
                    print_evens();
                    break;
                case 2:
                    print_multiples_of_3();
                    break;
                case 3:
                    print_multiples_of_5();
                    break;
                default:
                    break;
            }
            exit(0);
        }
    }

    
    for (int i = 0; i < 4; i++) {
        wait(NULL);
    }

    return 0;
}
