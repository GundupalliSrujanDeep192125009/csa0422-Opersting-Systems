#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

#define MAX_BUFFER_SIZE 3


int buffer[MAX_BUFFER_SIZE];
int count = 0, in = 0, out = 0;
sem_t mutex, empty, full;
void* producer(void* arg) {
    int produced = 0;
    while (produced < 4) {

        sleep(1);
        int data = rand() % 10 + 1;

        sem_wait(&empty); 
        sem_wait(&mutex); 
        // Insert Item
        buffer[in] = data;
        in = (in + 1) % MAX_BUFFER_SIZE;
        count++;

        printf("Produced %d\n", data);

        sem_post(&mutex); 
        sem_post(&full);  
        produced++;
    }
}

void* consumer(void* arg) {
    int consumed = 0;

    while (consumed < 1) {
        sem_wait(&full);  
        sem_wait(&mutex); 

        
        int data = buffer[out];
        out = (out + 1) % MAX_BUFFER_SIZE;
        count--;

        printf("Consumed %d\n", data);

        sem_post(&mutex); 
        sem_post(&empty); 
        consumed++;
    }
}

int main() {
    
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, MAX_BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_t producer_tid, consumer_tid;
    pthread_create(&producer_tid, NULL, producer, NULL);
    pthread_create(&consumer_tid, NULL, consumer, NULL);
    pthread_join(producer_tid, NULL);
    pthread_join(consumer_tid, NULL);
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
