#include <stdio.h>
#include <pthread.h>

void *printEvenNumbers(void *arg) {
    int *limit = (int *)arg;
    printf("Even Numbers: ");
    for (int i = 0; i <= *limit; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

void *printOddNumbers(void *arg) {
    int *limit = (int *)arg;
    printf("Odd Numbers: ");
    for (int i = 1; i <= *limit; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    int limit;
    printf("Enter the limit: ");
    scanf("%d", &limit);

    pthread_t evenThread, oddThread;
    pthread_create(&evenThread, NULL, printEvenNumbers, &limit);
    pthread_create(&oddThread, NULL, printOddNumbers, &limit);

    pthread_join(evenThread, NULL);
    pthread_join(oddThread, NULL);

    return 0;
}
