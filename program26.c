#include <stdio.h>
void priorityScheduling(int burstTime[], int priority[], int n)
{
    int waitingTime[n], turnaroundTime[n], completionTime[n];
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    completionTime[0] = burstTime[0];
    for (int i = 1; i < n; i++)
    {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
    }
    for (int i = 0; i < n; i++)
    {
        waitingTime[i] = completionTime[i] - burstTime[i];
        turnaroundTime[i] = completionTime[i];

        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    float averageWaitingTime = totalWaitingTime / n;
    float averageTurnaroundTime = totalTurnaroundTime / n;

    
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], priority[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("\nAverage Waiting Time: %.2f", averageWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", averageTurnaroundTime);
}
int main()
{
   
    int burstTime[] = {30, 5, 12};
    int priority[] = {2, 1, 3};
    int n = sizeof(burstTime) / sizeof(burstTime[0]);
    priorityScheduling(burstTime, priority, n);
    return 0;
}
