/*LRU age Repalcement Algo */
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
	unordered_map<int,int>mp;
	set<int>st;
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
				int lru=INT_MAX,val;
				for(auto it=st.begin();it!=st.end();it++){
					if(mp[*it]<lru){
						lru=mp[*it];
						val=*it;
					}					
				}	
				st.erase(val);
				st.insert(pg[i]);
				res+=1;
			}
				
			
		}	
		mp[pg[i]]=i;
	}	
	cout<<res<<"\n";
	
}	