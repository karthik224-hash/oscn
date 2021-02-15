#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"Enter the string to be stuffed : ";
	string str;
	string stuff="",destuff="";
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]=='E' || str[i]=='F')
			stuff+='E';
		stuff+=str[i];
	}
	stuff+='F';
	stuff='F'+stuff;
	cout<<"stuffed string is: "<<stuff<<"\n";
	for(int i=1;i<stuff.size()-1;i++){
		if(stuff[i]=='E')
			i++;
		destuff+=stuff[i];
	}
	cout<<"destuffed string is: "<<destuff<<"\n";	
	return 0;
		
}	
