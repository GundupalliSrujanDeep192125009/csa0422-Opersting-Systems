#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

pthread_mutex_t forks[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];

int left_fork(int philosopher) {
    return philosopher;
}

int right_fork(int philosopher) {
    return (philosopher + 1) % NUM_PHILOSOPHERS;
}

void test(int philosopher) {
    if (state[philosopher] == HUNGRY &&
        state[left_fork(philosopher)] != EATING &&
        state[right_fork(philosopher)] != EATING) {
        state[philosopher] = EATING;
        printf("Philosopher %d is now eating.\n", philosopher);
        pthread_mutex_unlock(&forks[philosopher]);
    }
}

void take_forks(int philosopher) {
    pthread_mutex_lock(&forks[philosopher]);
    state[philosopher] = HUNGRY;
    printf("Philosopher %d is now hungry.\n", philosopher);
    test(philosopher);
    pthread_mutex_unlock(&forks[philosopher]);
    pthread_mutex_lock(&forks[philosopher]);
}

void put_forks(int philosopher) {
    pthread_mutex_lock(&forks[philosopher]);
    state[philosopher] = THINKING;
    printf("Philosopher %d is now thinking.\n", philosopher);
    test(left_fork(philosopher));
    test(right_fork(philosopher));
    pthread_mutex_unlock(&forks[philosopher]);
}

void* philosopher_thread(void* philosopher_ptr) {
    int philosopher = *(int*)philosopher_ptr;
    free(philosopher_ptr);

    for (int i = 0; i < 3; i++) {  // Number of times a philosopher will eat
        sleep(1);  // Simulate thinking
        take_forks(philosopher);
        sleep(1);  // Simulate eating
        put_forks(philosopher);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];

    // Initialize mutexes and philosopher states
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&forks[i], NULL);
        state[i] = THINKING;
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        int* philosopher_ptr = malloc(sizeof(int));
        *philosopher_ptr = i;
        pthread_create(&philosophers[i], NULL, philosopher_thread, philosopher_ptr);
    }

    // Wait for philosopher threads to finish
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
