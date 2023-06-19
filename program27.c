#include <stdio.h>
#include <pthread.h>
pthread_mutex_t mutex;
pthread_cond_t condition;
int semaphore = 4;
void waitOperation() {
    pthread_mutex_lock(&mutex);

    while (semaphore <= 0) {
        pthread_cond_wait(&condition, &mutex);
    }

    semaphore--;
    printf("Semaphore acquired by process\n");

    pthread_mutex_unlock(&mutex);
}
void signalOperation() {
    pthread_mutex_lock(&mutex);

    semaphore++;
    printf("Semaphore released by process\n");

    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&mutex);
}
void* process(void* arg) {
    waitOperation();

    // Critical section
    printf("Process executing\n");

    signalOperation();

    pthread_exit(NULL);
}
int main() {
    int numProcesses = 4;
    pthread_t threads[numProcesses];
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&condition, NULL);
    for (int i = 0; i < numProcesses; i++) {
        pthread_create(&threads[i], NULL, process, NULL);
    }
    for (int i = 0; i < numProcesses; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condition);
    return 0;
}
