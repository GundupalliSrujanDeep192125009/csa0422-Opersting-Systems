#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int allocation[MAX_PROCESSES] = {-1, -1, -1, -1, -1}; 
    int i, j;
    for (i = 0; i < MAX_PROCESSES; i++) {
        int best_partition = -1;
        for (j = 0; j < MAX_PARTITIONS; j++) {
            if (partitions[j] >= processes[i]) {
                if (best_partition == -1 || partitions[j] < partitions[best_partition]) {
                    best_partition = j;
                }
            }
        }
        if (best_partition != -1) {
            allocation[i] = best_partition;
            partitions[best_partition] -= processes[i];
        }
    }

    printf("Process\tSize\tPartition\n");
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%d KB\t", i+1, processes[i]);
        if (allocation[i] == -1) {
            printf("Not allocated\n");
        } else {
            printf("%d\n", allocation[i]+1);
        }
    }

    return 0;
}
