/*FIFO  Repalcement Algo */
#include<bits/stdc++.h>
using namespace std;
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
	queue<int>qu;
	set<int>st;
	int res=0;
	for(int i=0;i<n;i++){
		if(st.size()<cap){
			if(st.find(pg[i])==st.end()){
				st.insert(pg[i]);
				qu.push(pg[i]);
				res+=1;
			}
		}
		else{
			if(st.find(pg[i])==st.end()){
				int val=qu.front();
				qu.pop();
				st.erase(val);
				st.insert(pg[i]);
				qu.push(pg[i]);
				res+=1;
			}
		}	
	}	
	cout<<res<<"\n";
	
}	