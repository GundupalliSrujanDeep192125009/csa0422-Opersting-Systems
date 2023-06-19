#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define MAX_THREADS 2
int sharedData = 10;  // Shared integer variable
sem_t semaphore;      // Semaphore to synchronize access to sharedData
void* doubleThread(void* arg)
{
    int value;
    sem_wait(&semaphore);  // Wait for semaphore to be available
    value = sharedData;
    value *= 2;  // Double the value
    printf("Double: %d\n", value);
    sem_post(&semaphore);  // Release the semaphore
    pthread_exit(NULL);
}

void* fiveTimesThread(void* arg)
{
    int value;
    sem_wait(&semaphore);  // Wait for semaphore to be available
    value = sharedData;
    value *= 5;  // Multiply the value by 5
    printf("Five times: %d\n", value);
    sem_post(&semaphore);  // Release the semaphore
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];

    // Initialize the semaphore
    if (sem_init(&semaphore, 0, 1) != 0) {
        printf("Semaphore initialization failed.\n");
        return 1;
    }

    // Create the threads
    if (pthread_create(&threads[0], NULL, doubleThread, NULL) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }
    if (pthread_create(&threads[1], NULL, fiveTimesThread, NULL) != 0) {
        printf("Thread creation failed.\n");
        return 1;
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}
