#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter the string to be stuffed : ";
	string str;
	string stuff="",destuff="";
	cin>>str;
	int cnt=0;
	for(int i=0;i<str.size();i++){
		stuff+=str[i];
		if(str[i]=='1'){
			cnt+=1;
		}
		else{
			cnt=0;
		}
		if(cnt==5){
			stuff+='0';
			cnt=0;
		}	
	}	
	cnt=0;
	cout<<"stuffed string is: "<<stuff<<"\n";
	for(int i=0;i<stuff.size();i++){
		destuff+=stuff[i];
		if(stuff[i]=='1'){
			cnt+=1;
		}
		else
			cnt=0;
		if(cnt==5){
			i++;
			cnt=0;
		}
	}
	cout<<"destuffed string is: "<<destuff<<"\n";	
}	
