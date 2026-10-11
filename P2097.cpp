#include<bits/stdc++.h>
using namespace std;
int fa[100005],vis[100005];
int n,m,ans;
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){fa[i]=i;}
	for(int i=1;i<=m;i++){
		int p,q,u,v;
		cin>>p>>q;
		u=find(p),v=find(q);
		if(u!=v){
			fa[u]=v;
		}
	}
	for(int i=1;i<=n;i++){
		int j=find(i);
		if(!vis[j]){
			vis[j]=1;
			ans++;
		}
	}
	cout<<ans;
}
