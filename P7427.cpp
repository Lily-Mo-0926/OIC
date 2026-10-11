#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
int ans[(int)1e5+5];
signed main(){
	cin>>a>>b;
	b=(a+b)*2;
	int f=0;
	for(int i=1;i*i<=b;i++){
		if(b%i==0&&b/i==i+1){f=i;}
	}if(!f){
		return cout<<"No",0;
	}
	cout<<f<<' ';
	for(int i=f;i>1;i--){
		if(a>i)a-=i,cout<<i<<' ';
	}
	cout<<a;
}
