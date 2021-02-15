#include<bits/stdc++.h>
using namespace std;
void gwt(int n,int bt[],int wt[],int quantum){
	int rem_bt[n];
	for(int i=0;i<n;i++)
		rem_bt[i]=bt[i];
	int t=0;
	while(1){
		bool chk=true;
		for(int i=0;i<n;i++){
			if(rem_bt[i]>0){
				chk=false;
				if(rem_bt[i]>quantum){
					t+=quantum;
					rem_bt[i]-=quantum;
				}	
				else{
					t+=rem_bt[i];
					wt[i]=t-bt[i];
					rem_bt[i]=0;
				}	
			}	
		}
		if(chk==true)
			break;
	}	
	return;
}	

void gtat(int n,int bt[],int wt[],int tat[]){
	
	for(int i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
	
}	


pair<float,float> helper(int n,int bt[],int quantum){
	int wt[n],tat[n],res_wt=0,res_tat=0;
	gwt(n,bt,wt,quantum);
	gtat(n,bt,wt,tat);
	for(int i=0;i<n;i++){
		res_wt+=wt[i];
		res_tat+=tat[i];
	}	
	pair<float,float>ans;
	ans=make_pair((float)res_wt/(float)n,(float)res_tat/(float)n);
	return ans;
}	
int main(){
	cout<<"No of processes : \n";
	int n;
	cin>>n;
	cout<<"Burst Time of Processes: \n";
	int bt[n];
	for(int i=0;i<n;i++)
		cin>>bt[i];
	cout<<"Enter the Quantum :\n ";
	int quantum;
	cin>>quantum;
	pair<float,float>ans=helper(n,bt,quantum);
	cout<<ans.first<<" "<<ans.second<<"\n";
}	