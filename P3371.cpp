#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s;
struct node{
	int dis,to;
	bool operator > (const node &a)const{return dis>a.dis;}
};
vector<node>e[500005];
int dis[10004],vis[10004];
priority_queue<node,vector<node>,greater<node> >q;
void dijkstra(int n,int s){
	for(int i=0;i<=n+1;i++){dis[i]=(1<<31)-1;}
	memset(vis,0,sizeof vis);
	dis[s]=0;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().to;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto ed:e[u]){
			int v=ed.to,w=ed.dis;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
}
signed main(){
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({w,v});
	}
	dijkstra(n,s);
	for(int i=1;i<=n;i++){
		cout<<dis[i]<<' ';
	}
}
