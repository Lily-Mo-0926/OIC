#include<bits/stdc++.h>
using namespace std;
int a;
unsigned long long b;
void dfs(int n,unsigned long long k,int x){
	if(n==0)return;
	if(k<(1ull<<n-1)){
		if(x)cout<<1;
		else cout<<0;
		dfs(n-1,k,0);
	}else{
		if(x)cout<<0;
		else cout<<1;
		dfs(n-1,k-(1ull<<n-1),1);
	}
}
int main(){
	cin>>a>>b;
	dfs(a,b,0);
}
