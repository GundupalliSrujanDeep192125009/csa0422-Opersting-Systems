#include <stdio.h>
#include <stdlib.h>

struct Process {
    int processId;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateWaitingTime(struct Process processes[], int n) {
    processes[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void calculateTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void calculateAverageTimes(struct Process processes[], int n, float* avgWaitingTime, float* avgTurnaroundTime) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);

    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    *avgWaitingTime = (float)totalWaitingTime / n;
    *avgTurnaroundTime = (float)totalTurnaroundTime / n;
}

void displayProcessDetails(struct Process processes[], int n) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].processId, processes[i].burstTime,
               processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

void sortProcessesByBurstTime(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n = 3;
    struct Process processes[n];

    // Initialize the processes
    for (int i = 0; i < n; i++) {
        processes[i].processId = i;
    }

    processes[0].burstTime = 2;
    processes[1].burstTime = 4;9
    processes[2].burstTime = 8;

    sortProcessesByBurstTime(processes, n);

    float avgWaitingTime, avgTurnaroundTime;
    calculateAverageTimes(processes, n, &avgWaitingTime, &avgTurnaroundTime);

    displayProcessDetails(processes, n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    return 0;
}
