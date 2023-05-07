#include <stdio.h>

#define NUM_PROCESSES 3

int main() {
    int burst_times[NUM_PROCESSES] = {10, 15, 25};
    int arrival_time = 0;
    int completion_time[NUM_PROCESSES];
    int waiting_time[NUM_PROCESSES];
    int turnaround_time[NUM_PROCESSES];
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    completion_time[0] = burst_times[0];
    waiting_time[0] = 0;
    turnaround_time[0] = completion_time[0] - arrival_time;

    for (int i = 1; i < NUM_PROCESSES; i++) {
        completion_time[i] = completion_time[i-1] + burst_times[i];
        waiting_time[i] = completion_time[i-1] - arrival_time;
        turnaround_time[i] = completion_time[i] - arrival_time;
    }

    for (int i = 0; i < NUM_PROCESSES; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time /= NUM_PROCESSES;
    avg_turnaround_time /= NUM_PROCESSES;

    printf("Average Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);

    return 0;
}
