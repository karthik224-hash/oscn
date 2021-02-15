#include<bits/stdc++.h>
using namespace std;
void gwt(int n,int bt[],int wt[],int at[]){
	wt[0]=0;
	int pf[n];
	pf[0]=0;
	for(int i=1;i<n;i++){
		pf[i]=pf[i-1]+bt[i-1];
		/* if no arrival time given
		then wt[i]=wt[i-1]+bt[i-1]
		*/
		wt[i]=pf[i]-at[i];
		if(wt[i]<0)
			wt[i]=0;
	}
	
}	

void gtat(int n,int bt[],int wt[],int tat[]){
	
	for(int i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
	
}	


pair<float,float> helper(int n,int bt[],int at[]){
	int wt[n],tat[n],res_wt=0,res_tat=0;
	gwt(n,bt,wt,at);
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
	//If the arrival time is given
	cout<<"Arrival Time of Processes: \n";
	int at[n];
	for(int i=0;i<n;i++)
		cin>>at[i];
	pair<float,float>ans=helper(n,bt,at);
	cout<<ans.first<<" "<<ans.second<<"\n";
}	