#include<bits/stdc++.h>
using namespace std;
int n,m,k,mx,sz,sum;
int a[200005],vis[200005];
map<int,int>mp;
vector<int>g[200005];
void dfs(int u){
	sz++;
	vis[u]=1;
	mp[a[u]]++;
	mx=max(mx,mp[a[u]]);
	for(auto v:g[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
int main(){
	freopen("socks.in","r",stdin);
	freopen("socks.out","w",stdout); 
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,x,y;i<=m;i++)
		cin>>x>>y,
		g[x].push_back(y),
		g[y].push_back(x);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			sz=mx=0;
			mp.clear();
			dfs(i);
			sum+=sz-mx;
		}
	}
	cout<<sum;
}
