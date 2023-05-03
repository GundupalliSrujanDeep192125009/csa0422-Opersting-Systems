#include <stdio.h>
#define N_PROCESSES 4
#define N_RESOURCES 3
int claim[N_PROCESSES][N_RESOURCES] = {
    {3, 2, 2},
    {6, 1, 3},
    {3, 1, 4},
    {4, 2, 2}
};
int allocation[N_PROCESSES][N_RESOURCES] = {
    {1, 0, 0},
    {6, 1, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int available[N_RESOURCES] = {9, 3, 6};
int finish[N_PROCESSES] = {0};
int work[N_RESOURCES];
int safety_algorithm() {
    int i, j, k, safe;
    for (i = 0; i < N_RESOURCES; i++) {
        work[i] = available[i];
    }
    for (k = 0; k < N_PROCESSES; k++) {
        safe = 0;
        if (finish[k] == 0) {
            for (j = 0; j < N_RESOURCES; j++) {
                if (claim[k][j] - allocation[k][j] > work[j]) {
                    break;
                }
            }
            if (j == N_RESOURCES) {
                safe = 1;
                break;
            }
        }
    }
    if (safe == 0) {
        return 0;
    }
    for (i = 0; i < N_RESOURCES; i++) {
        work[i] += allocation[k][i];
    }
    finish[k] = 1;
    return safety_algorithm();
}

int main() {
    int safe = safety_algorithm();
    if (safe == 1) {
        printf("The system is in a safe state.\n");
    } else {
        printf("The system is in an unsafe state.\n");
    }
    
    return 0;
}
