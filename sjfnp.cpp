#include<bits/stdc++.h>
using namespace std;
struct Process
{
   int pid;     // process ID
   int bt;      // burst Time
   int at;
};
bool comparison(Process a, Process b)
{
    return (a.bt < b.bt);
}
void findWaitingTime(Process proc[], int n, int wt[])
{
    // waiting time for first process is 0
    wt[0] = 0;
	int pf[n];
	pf[0]=0;
    // calculating waiting time
    for (int i = 1; i < n ; i++)
    {
        //wt[i] = proc[i-1].bt + wt[i-1] ;
		pf[i]=pf[i-1]+proc[i-1].bt;
		/* if no arrival time given
		then wt[i]=wt[i-1]+bt[i-1]
		*/
		wt[i]=pf[i]-proc[i].at;
		if(wt[i]<0)
			wt[i]=0;
    }
}
 
// function to calculate turn around time
void findTurnAroundTime(Process proc[], int n, int wt[], int tat[])
{
    // calculating turnaround time by adding bt[i] + wt[i]
    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}
 
// function to calculate average time
void findAverageTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    // function to find waiting time of all processes
    findWaitingTime(proc, n, wt);
 
    // function to find turn around time for all processes
    findTurnAroundTime(proc, n, wt, tat);
 
    // display processes along with all details
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
 
    // calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
}
int main(){
	cout<<"Enter the number of Process: \n" ;
	int n;
	cin>>n;
	struct Process proc[n];
	cout<<"Enter the process id: \n";
	for(int i=0;i<n;i++)
		cin>>proc[i].pid;
	cout<<"Enter the Burst time of Process :\n";
	for(int i=0;i<n;i++)
		cin>>proc[i].bt;
	cout<<"Enter the Arrival time of Process :\n";
	for(int i=0;i<n;i++)
		cin>>proc[i].at;
	sort(proc, proc + n, comparison);
 
    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
    {
        cout << proc[i].pid <<" ";
    }
 
    findAverageTime(proc, n);
	return 0;
}	