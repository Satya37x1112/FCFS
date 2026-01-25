**FCFS Code**
```
This program demonstrates FCFS process which means (FIRST COME FIRST SERVE) it is one of the important process used in CPU Scheduling.
This Code helps to understand the working of the process in code form which will help to understand and practically see the working of the process.

If you find this code insightful Don't forget to star this repo.........  :-).
```

![FCFS Process Visualization](FCFS8.png)

## Sample Output

**Input:**
```
Enter Number of processes: 4
Enter arrival time and burst time of process 1: 10 20
Enter arrival time and burst time of process 2: 15 30
Enter arrival time and burst time of process 3: 20 40
Enter arrival time and burst time of process 4: 50 55
```

**Output:**

| PID | Arrival | Burst | Completion | Turnaround | Waiting |
|-----|---------|-------|------------|------------|---------|
| 1   | 10      | 20    | 30         | 20         | 0       |
| 2   | 15      | 30    | 60         | 45         | 15      |
| 3   | 20      | 40    | 100        | 80         | 40      |
| 4   | 50      | 55    | 155        | 105       | 50      |

| Metric | Value |
|--------|-------|
| Total turnaround time | 250.00 |
| Average turnaround time | 62.50 |
