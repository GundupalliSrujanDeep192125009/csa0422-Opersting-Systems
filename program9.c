#include <stdio.h>

#define MAX 10

int main() {
    int n, i;
    int arrival_time[MAX], burst_time[MAX];
    int waiting_time[MAX], turnaround_time[MAX];
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival times and burst times of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
    }

    waiting_time[0] = 0;
    for (i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i-1] + burst_time[i-1];
    }

    turnaround_time[0] = burst_time[0];
    for (i = 1; i < n; i++) {
        turnaround_time[i] = waiting_time[i] + burst_time[i];
    }

    avg_waiting_time = 0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
    }
    avg_waiting_time /= n;

    avg_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        avg_turnaround_time += turnaround_time[i];
    }
    avg_turnaround_time /= n;

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i, burst_time[i], arrival_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
