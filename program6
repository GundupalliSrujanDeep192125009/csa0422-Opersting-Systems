#include<stdio.h>

#define N 3
#define M 3

void detect_deadlock(int max[N][M], int alloc[N][M], int available[M]) {
    int marked[N] = {0};
    int work[M];

    for (int i = 0; i < M; i++) {
        work[i] = available[i];
    }

    int count = 0;
    while (count < N) {
        int found = 0;
        for (int i = 0; i < N; i++) {
            if (!marked[i]) {
                int j;
                for (j = 0; j < M; j++) {
                    if (max[i][j] - alloc[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == M) {
                    for (int k = 0; k < M; k++) {
                        work[k] += alloc[i][k];
                    }
                    marked[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    if (count < N) {
        printf("Deadlock detected!\n");
        printf("Deadlocked processes: ");
        for (int i = 0; i < N; i++) {
            if (!marked[i]) {
                printf("P%d ", i+1);
            }
        }
        printf("\n");
    } else {
        printf("No deadlock detected.\n");
    }
}

int main() {
    int max[N][M] = {{3, 6, 8},
                     {4, 3, 3},
                     {3, 4, 4}};

    int alloc[N][M] = {{3, 3, 3},
                       {2, 0, 3},
                       {1, 2, 4}};

    int available[M] = {1, 2, 0};

    detect_deadlock(max, alloc, available);

    return 0;
}
