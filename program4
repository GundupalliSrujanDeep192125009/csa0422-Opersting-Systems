#include <stdio.h>
int main() {
    
    int partitions[] = {300, 600, 350, 200, 750, 125};
    int num_partitions = 6;
    
    
    int processes[] = {115, 500, 358, 200, 375};
    int num_processes = 5;
    
    
    int allocation_status[num_partitions];
    for (int i = 0; i < num_partitions; i++) {
        allocation_status[i] = 0;
    }
    
    
    for (int i = 0; i < num_processes; i++) {
        int process_size = processes[i];
        int allocated = 0;
        
        
        for (int j = 0; j < num_partitions && !allocated; j++) {
            if (allocation_status[j] == 0 && partitions[j] >= process_size) {
                allocation_status[j] = 1;
                allocated = 1;
                printf("Process %d KB allocated to partition %d (%d KB)\n", process_size, j, partitions[j]);
            }
        }
        
        
        if (!allocated) {
            printf("Process %d KB could not be allocated\n", process_size);
        }
    }
    
    return 0;
}
