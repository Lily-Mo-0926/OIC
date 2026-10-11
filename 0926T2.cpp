#include<bits/stdc++.h>
using namespace std;
const int N=5005;
struct Query{
	int a,b,g;
	bool operator<(const Query& other)const{
		return g>other.g;
	}
};
struct Edge{
	int u,v;
}edges[N];
int n,m;
int fa[N],dep[N],w[N],etn[N];
vector<int>g[N];
vector<Query>q;
void dfs(int u,int p,int d){
	fa[u]=p;
	dep[u]=d;
	for(int v:g[u]){
		if(v!=p)dfs(v,u,d+1);
	}
}
int lca(int u,int v){
	while(dep[u]>dep[v])u=fa[u];
	while(dep[v]>dep[u])v=fa[v];
	while(u!=v){
		u=fa[u];
		v=fa[v];
	}return u;
}
bool cover(int u,int anc,int val){
	bool mask=0;
	while(u!=anc){
		if(w[u]==0){
			w[u]=val;
			mask=1;
		}
		u=fa[u];
	}
	return mask;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		g[i].clear();
		w[i]=0;
	}
	for(int i=1;i<n;i++){
		cin>>edges[i].u>>edges[i].v;
		g[edges[i].u].push_back(edges[i].v);
		g[edges[i].v].push_back(edges[i].u);
	}
	dfs(1,0,1);
	for(int i=1;i<n;i++){
		int u=edges[i].u,v=edges[i].v;
		if(fa[u]==v)etn[i]=u;
		else etn[i]=v;
	}
	cin>>m;
	q.clear();
	for(int i=0;i<m;i++){
		int a,b,val;
		cin>>a>>b>>val;
		q.push_back({a,b,val});
	}
	sort(q.begin(),q.end());
	bool ok=1;
	for(auto& x:q){
		int l=lca(x.a,x.b);
		bool ca=cover(x.a,l,x.g),cb=cover(x.b,l,x.g);
		if(!ca&&!cb){
			ok=0;
			break;
		}
	}
	if(!ok){
		cout<<-1<<"\n";
	}else{
		for(int i=1;i<n;i++){
			int u=etn[i];
			if(w[u]==0)w[u]=1e6;
			cout<<w[u]<<(i==n-1?"\n":" ");
		}
	}	
}
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
}
