#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,int>mp;
int main(){
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		if(!mp[x])mp[x]=i;
	}
	for(int i=0,x;i<m;i++){
		cin>>x;
		if(mp[x])cout<<mp[x]<<' ';
		else cout<<-1<<' ';
	}
}
