#include <stdio.h>

struct pcb
{
    int pid;
    int arr;
    int burst;
    int completion;
    int tat;
    int wt;
};

int main(void)
{
    int i, j, n;
    double sumTAT = 0.0, avgTAT = 0.0;
    struct pcb p[10], temp;

    printf("Enter Number of processes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of processes\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &p[i].arr, &p[i].burst);
        p[i].pid = i + 1;
        p[i].completion = 0;
        p[i].tat = 0;
        p[i].wt = 0;
    }

    /* Sort processes by arrival time (stable bubble sort) */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].arr > p[j + 1].arr) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    /* FCFS scheduling: compute completion, turnaround and waiting times */
    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (p[i].arr > current_time)
            current_time = p[i].arr; /* CPU idle until process arrives */

        p[i].completion = current_time + p[i].burst;
        p[i].tat = p[i].completion - p[i].arr;
        p[i].wt = p[i].tat - p[i].burst;

        sumTAT += p[i].tat;
        current_time = p[i].completion;
    }

    avgTAT = sumTAT / n;

    printf("\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].arr, p[i].burst, p[i].completion, p[i].tat, p[i].wt);
    }

    printf("\nTotal turnaround time = %.2f\n", sumTAT);
    printf("Average turnaround time = %.2f\n", avgTAT);

    return 0;
}
