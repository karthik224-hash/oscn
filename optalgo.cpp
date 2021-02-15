/*FIFO  Repalcement Algo */
#include<bits/stdc++.h>
using namespace std;
int helper(int pg[],int n,unordered_set<int>&st,int idx){
	int res=-1,maxi=idx;
	for(auto i=st.begin();i!=st.end();i++){
		int j;
		for(j=idx;j<n;j++){
			if(*i==pg[j]){
				if(j>maxi){
					maxi=j;
					res=*i;
				}
				break;
			}	
		}
		if(j==n)
			return *i;
	}	
	return res;
	
}	

int optimal(int pg[],int n,int cap){
	unordered_set<int>st;
	int res=0;
	for(int i=0;i<n;i++){
		if(st.size()<cap){
			if(st.find(pg[i])==st.end()){
				st.insert(pg[i]);
				res+=1;
			}
		}
		else{
			if(st.find(pg[i])==st.end()){
				int val=helper(pg,n,st,i+1);
				st.erase(val);
				st.insert(pg[i]);
				res+=1;
			}
		}	
	}	
	return res;
	
}	


int main(){
	int n;
	cout<<"Enter the value of n: \n";
	cin>>n;
	int pg[n];
	cout<<"Enter the values : ";
	for(int i=0;i<n;i++)
		cin>>pg[i];
	cout<<"Enter the capacity : ";
	int cap;
	cin>>cap;
	int misses=optimal(pg,n,cap);
	cout<<"No of hits: "<<n-misses<<"\n";
	cout<<"No of misses : "<<misses<<"\n";
	return 0;
}	