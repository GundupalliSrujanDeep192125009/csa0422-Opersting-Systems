#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

int compare(const void* a, const void* b) {
    const process* p1 = (const process*) a;
    const process* p2 = (const process*) b;
    return p1->burst_time - p2->burst_time;
}

int main() {
    const int num_processes = 4;
    process processes[num_processes] = {
        { .pid = 1, .burst_time = 6, .waiting_time = 0, .turnaround_time = 0 },
        { .pid = 2, .burst_time = 8, .waiting_time = 0, .turnaround_time = 0 },
        { .pid = 3, .burst_time = 7, .waiting_time = 0, .turnaround_time = 0 },
        { .pid = 4, .burst_time = 3, .waiting_time = 0, .turnaround_time = 0 }
    };

    
    qsort(processes, num_processes, sizeof(process), compare);

    
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        process* p = &processes[i];
        p->waiting_time = current_time;
        p->turnaround_time = current_time + p->burst_time;
        total_waiting_time += p->waiting_time;
        total_turnaround_time += p->turnaround_time;
        current_time += p->burst_time;
    }

    
    double avg_waiting_time = (double) total_waiting_time / num_processes;
    double avg_turnaround_time = (double) total_turnaround_time / num_processes;
    printf("Average Waiting Time: %lf\n", avg_waiting_time);
    printf("Average Turnaround Time: %lf\n", avg_turnaround_time);

    return 0;
}
