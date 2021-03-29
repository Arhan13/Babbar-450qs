#include <bits/stdc++.h>

using namespace std;

struct Process
{
    int pid;
    int bt;
    int priority;
};

bool compare(Process a, Process b)
{
    return (a.priority > b.priority);
}

void waitingTimeCalc(Process proc[], int n, int wt[])
{
    //Waiting time for the first process is 0
    wt[0] = 0;

    //Calculating the waiting time for the various processes
    for (int i = 1; i < n; i++)
    {
        //Waiting time of previous process + burst time

        wt[i] = proc[i - 1].bt + wt[i - 1];
    }
}

void turnArounTimeCalc(Process proc[], int n, int wt[], int tat[])
{
    //tat[i] = bt[i] + wt[i];
    for (int i = 0; i < n; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

void averageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    waitingTimeCalc(proc, n, wt);
    turnArounTimeCalc(proc, n, wt, tat);
    cout << "\nProcesses  "
         << " Burst time  "
         << " Waiting time  "
         << " Turn around time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "   " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t    " << wt[i]
             << "\t\t  " << tat[i] << endl;
    }
    cout << "\nAverage waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}

void priorityScheduling(Process proc[], int n)
{
    sort(proc, proc + n, compare);
    cout << "Order in which processes gets executed \n";
    for (int i = 0; i < n; i++)
        cout << proc[i].pid << " ";
    averageTime(proc, n);
}

int main()
{
    //pid bt priority
    Process proc[] = {{1, 10, 0}, {2, 5, 5}, {3, 8, 9}};
    int n = sizeof proc / sizeof proc[0];
    priorityScheduling(proc, n);
    return 0;
}
