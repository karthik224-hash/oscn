/*Dijistra's Algorithm*/
#include<bits/stdc++.h>
using namespace std;
int helper(vector<int>&dis,vector<bool>&vis){
	int mind=INT_MAX,mini=-1;
	for(int i=0;i<dis.size();i++){
		if(vis[i]==false && mind>dis[i]){
			mini=i;
			mind=dis[i];
		}	
	}	
	return mini;
	
}	
int main(){
	int n;
	cout<<"Enter the number of Vertices :" ;
	cin>>n;
	int G[n][n];
	cout<<"Enter the adjacency Matrix : ";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>G[i][j];
		}
	}
	vector<int>dis(n,INT_MAX);
	vector<bool>vis(n,false);
	cout<<"Enter the soource Vertex: ";
	int s;
	cin>>s;
	dis[s]=0;
	for(int i=0;i<n;i++){
		int idx=helper(dis,vis);
		if(idx==-1)
			break;
		vis[idx]=true;
		for(int j=0;j<n;j++){
			if(dis[j]>dis[idx]+G[idx][j]){
				dis[j]=dis[idx]+G[idx][j];		
			}
		}	
	}	
	for(int i=0;i<dis.size();i++)
		cout<<dis[i]<<" ";
	cout<<"\n";
}	
