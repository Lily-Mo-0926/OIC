#include<bits/stdc++.h>
using namespace std;
string b;
char c[100];
int main(){
	cin>>b;
	for(int i=0;i<b.length();i++){
//		cout<<'H'<<endl;
		
		//cout<<c[i];
		if(b[i]=='L'&&i+1<b.length()&&b[i+1]=='X'&&(i+2>=b.length()||b[i+2]!='X')){
//			cout<<"if1"<<endl;
			c[i]='X';
			c[i+1]='L';
			i+=2;
			continue;
		}
		else if(b[i]=='V'&&i+2>=b.length()&&i+1<b.length()&&b[i+1]=='I'){
//			cout<<"if2"<<endl;
			c[i]='I';
			c[i+1]='V';
			i+=2;
			continue;
		}
		else if(b[i]=='X'&&i+1<b.length()&&b[i+1]=='I'&&i+2>=b.length()){
//			cout<<"if3"<<endl;
			c[i]='I';
			c[i+1]='X';
			i+=2;
			continue;
		}
		else{
			c[i]=b[i];
		}
	}
//	cout<<strlen(c)<<endl;
	for(int i=0;i<strlen(c);i++){
		
		cout<<c[i];
	}
}
