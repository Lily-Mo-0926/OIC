#include<bits/stdc++.h>
using namespace std;
int n,sol[15],ans,ct;
int ck1[15],ck2[30],ck3[30];
void dfs(int u){
	if(u>n){
		if(ct<3){for(int i=1;i<=n;i++){cout<<sol[i]<<' ';}cout<<endl;}
		ct++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!ck1[i]&&!ck2[u+i]&&!ck3[u+n-i]){
			ck1[i]=1,ck2[u+i]=1,ck3[u+n-i]=1;
			sol[u]=i,dfs(u+1);
			ck1[i]=0,ck2[u+i]=0,ck3[u+n-i]=0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ct<<endl;
}
