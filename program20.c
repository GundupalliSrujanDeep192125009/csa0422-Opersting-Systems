#include <stdio.h>

#define MAX_PARTITIONS 6
#define MAX_PROCESSES 5

void worstFit(int partitions[], int processes[], int allocation[], int m, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        int index = -1;
        for (j = 0; j < m; j++) {
            if (partitions[j] >= processes[i]) {
                if (index == -1)
                    index = j;
                else if (partitions[j] > partitions[index])
                    index = j;
            }
        }

        if (index != -1) {
            allocation[i] = index;
            partitions[index] -= processes[i];
        }
    }
}

void displayAllocation(int partitions[], int processes[], int allocation[], int m, int n) {
    printf("Process\tProcess Size\tPartition\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d KB\t\t", i+1, processes[i]);
        if (allocation[i] != -1)
            printf("%d (Remaining Space: %d KB)\n", allocation[i]+1, partitions[allocation[i]]);
        else
            printf("Not Allocated\n");
    }
} 

int main() {
    int partitions[MAX_PARTITIONS] = {300, 600, 350, 200, 750, 125};
    int processes[MAX_PROCESSES] = {115, 500, 358, 200, 375};
    int allocation[MAX_PROCESSES] = {-1};

    worstFit(partitions, processes, allocation, MAX_PARTITIONS, MAX_PROCESSES);
    displayAllocation(partitions, processes, allocation, MAX_PARTITIONS, MAX_PROCESSES);

    return 0;
}
