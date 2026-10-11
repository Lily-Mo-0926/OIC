#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,q,ti,x,k;
int fa[N],dfn[N],ord[N],sz[N];
vector<int>g[N];
void dfs(int u){
	dfn[u]=++ti;
	ord[ti]=u;
	sz[u]=1;
	for(auto v:g[u]){
		dfs(v);
		sz[u]+=sz[v];
	}
}
signed main(){
	freopen("command.in","r",stdin);
	freopen("command.out","w",stdout);
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		cin>>fa[i];
		g[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
	}
	dfs(1);
	while(q--){
		cin>>x>>k;
		//cout<<sz[x]<<endl;
		if(sz[x]<k)cout<<-1;
		else cout<<ord[dfn[x]+k-1];
		cout<<endl;
	}
}
