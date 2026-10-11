#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,p;
int ksc(int a,int b,int p){
	int base=a,ans=0;
	while(b){
		if(b&1){
			ans+=base;
			ans%=p;
		}
		b>>=1;
		base+=base;
		base%=p;
	}
	return ans;
}
signed main(){
	cin>>a>>b>>p;
	cout<<ksc(a,b,p);
}
