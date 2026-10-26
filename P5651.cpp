#include<bits/stdc++.h>
using namespace std;
int n,m,t;
vector<pair<int,int>>g[100005];
int dis[100005],vis[100005];
//queue<pair<int,int>>q;
queue<int>q;
int main(){
	cin>>n>>m>>t;
	for(int i=1,x,y,v;i<=m;i++){
		cin>>x>>y>>v;
		g[x].push_back({y,v});
		g[y].push_back({x,v});
	}
	//g[0].push_back({1,0});
	//q.push({1,0});
	q.push(1);
	vis[0]=1;
	while(!q.empty()){
		/*int u=q.front().first,
		w=q.front().second;*/
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto v:g[u]){
			if(!vis[v.first]){
				dis[v.first]=dis[u]^v.second;
				q.push(v.first);
			}
		}
	}
	for(int i=0,x,y;i<t;i++){
		cin>>x>>y;
		cout<<(dis[x]^dis[y])<<"\n";
	}
} 
