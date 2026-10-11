#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,num;
string s;
int deced(){
	int x=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			x=x*n+s[i]-'0';
		}else if(s[i]>='A'&&s[i]<='F'){
			x=x*n+s[i]-'A'+10;
		}
	} 
	return x;
}
void tur(int x){
	char c[100];
	int cnt=0;
	while(x){
		cnt++;
		int tmp=x%m;
		if(tmp<10){
			c[cnt]=tmp+'0';
		}else{
			c[cnt]=tmp-10+'A';
		}
		x/=m;
	}
	for(;cnt>0;cnt--){
		cout<<c[cnt];
	}
}
int main(){
	cin>>n>>s>>m;
	num=deced(); 
	tur(num); 
} 

