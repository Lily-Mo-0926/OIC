#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
priority_queue<pair<int,int>,
		vector<pair<int,int>>,
		greater<pair<int,int>>>q;
struct edge{
	int to,w,ne;
}meg[(int)2e5+7];
int dist[2005],head[2005],st[2005];
int dijkstra(int s){
	memset(dist,0x3f,sizeof dist);
	//st[1]=1;
	dist[s]=0;
	q.push({0,s});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int ver=t.second,dis=t.first;
		if(st[ver])continue;
		st[ver]=1;
		for(int i=head[ver];i;i=meg[i].ne){
			int j=meg[i].to;
			if(dist[j]>meg[i].w+dis){
				dist[j]=meg[i].w+dis;
				q.push({dist[j],j});
			}
		}
	}
	return dist[n];
}
int main(){
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w; 
		meg[i]={v,w,head[u]};
		head[u]=i; 
		meg[i+m]={u+n,w,head[v+n]};
		head[v+n]=i+m;
	}
	dijkstra(1);
	for(int i=1;i<=n;i++){
	//	cout<<dist[i]<<' ';
		ans+=dist[i];
	}
	//cout<<endl;
	dijkstra(n+1);
	for(int i=n+1;i<=n*2;i++){
	//	cout<<dist[i]<<' ';
		ans+=dist[i];
	}
	//cout<<endl;
	cout<<ans;
}
