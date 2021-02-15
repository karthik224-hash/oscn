#include<bits/stdc++.h>
using namespace std;
struct process{
	int pid;
	int at;
	int bt;
	int st;
	int ct;
	int tat;
	int wt;
	
};	
int main(){
	cout<<"Enter the number of Process: \n" ;
	int n;
	cin>>n;
	struct process p[10000];
	int total_tat=0;
	int total_wt=0;
	int is_completed[n];
	int burst_remaining[n];
    memset(is_completed,0,sizeof(is_completed));
	cout << setprecision(2) << fixed;
	for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].at;
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].bt;
		burst_remaining[i] = p[i].bt;
        p[i].pid = i+1;
        cout<<"\n";
    }
	
	int current_time = 0;
    int completed = 0;
    int prev = 0;
	while(completed != n) {
        int idx = -1;
        int mn =INT_MAX;
        for(int i = 0; i < n; i++) {
            if(p[i].at <=current_time && is_completed[i] == 0) {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i]== mn) {
                    if(p[i].at < p[idx].at) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }
		if(idx != -1) {
            burst_remaining[idx] -= 1;
            current_time++;
            prev = current_time;
			if(burst_remaining[idx] == 0) {
				p[idx].ct= current_time;
				p[idx].tat= p[idx].ct- p[idx].at;
				p[idx].wt= p[idx].tat- p[idx].bt;
				
				total_tat += p[idx].tat;
				total_wt += p[idx].wt;
	  
				is_completed[idx] = 1;
				completed++;
			}
		}
		else{
			current_time++;
		}
			
	} 
	float avg_tat= (float)total_tat/(float)n;
    float  avg_wt = (float) total_wt/(float) n;
	for(int i=0; i<n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
    }
	
	cout<<"Average Turnaround Time = "<<avg_tat<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
	return 0;
}	