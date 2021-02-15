//CRC code
#include<bits/stdc++.h>
using namespace std;

string sender(string s,string crc){
	string encoded=s;
	int m=s.size();
	int n=crc.size();
	for(int i=1;i<=n-1;i++)
		encoded+='0';
	int sz=encoded.size();
	for(int i=0;i<sz-n+1;){
		for(int j=0;j<n;j++){
			encoded[i+j]=(encoded[i+j]==crc[j])?'0':'1';
		}
		while(i<sz && encoded[i]!='1')
			i++;
	}
	string remain=encoded.substr(sz-n+1);
	cout<<remain<<"\n";
	s+=remain;
	return s;
}

void receiver(string encoded,string crc){
	int n=crc.size();
	int sz=encoded.size();
	for(int i=0;i<sz-n+1;){
		for(int j=0;j<n;j++){
			encoded[i+j]=(encoded[i+j]==crc[j])?'0':'1';
		}
		while(i<sz && encoded[i]!='1')
			i++;
	}
	string remain=encoded.substr(sz-n+1);
	for(int i=0;i<remain.size();i++){
		if(remain[i]=='1'){
			cout<<"Error detected\n";
			return;
		}	
	}
	cout<<"NO error detected ";
}


int main(){
	string s="1101000",crc="1101";
	string encoded=sender(s,crc);
	cout<<"Encoded: "<<encoded<<"\n";
	receiver(encoded,crc);
	return 0;
}	