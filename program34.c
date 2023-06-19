#include <stdio.h>

// Function to allocate memory blocks using the worst-fit algorithm
void worstFit(int memory[], int n, int processSize) {
    int maxFragment = -1;
    int index = -1;
    
    // Find the memory block with the largest fragment
    for (int i = 0; i < n; i++) {
        if (memory[i] >= processSize) {
            int fragment = memory[i] - processSize;
            if (fragment > maxFragment) {
                maxFragment = fragment;
                index = i;
            }
        }
    }
    
    // Allocate the process to the memory block
    if (index != -1) {
        memory[index] = processSize;
        printf("Process of size %d KB is allocated to Memory Block %d.\n", processSize, index + 1);
    } else {
        printf("Process of size %d KB cannot be allocated.\n", processSize);
    }
}

int main() {
    int memory[] = {40, 10, 30, 60}; // Memory partitions in KB (in order)
    int n = sizeof(memory) / sizeof(memory[0]);
    
    int processes[] = {100, 50, 30, 120, 35}; // Process sizes in KB (in order)
    int numProcesses = sizeof(processes) / sizeof(processes[0]);
    
    printf("Initial Memory Blocks:\n");
    for (int i = 0; i < n; i++) {
        printf("Memory Block %d: %d KB\n", i + 1, memory[i]);
    }
    
    printf("\n");
    
    // Allocate memory blocks for each process
    for (int i = 0; i < numProcesses; i++) {
        printf("Allocating Process of size %d KB:\n", processes[i]);
        worstFit(memory, n, processes[i]);
        printf("Memory Blocks after allocation:\n");
        for (int j = 0; j < n; j++) {
            printf("Memory Block %d: %d KB\n", j + 1, memory[j]);
        }
        printf("\n");
    }
    
    return 0;
}
