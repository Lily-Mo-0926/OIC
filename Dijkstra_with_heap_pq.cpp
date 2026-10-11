#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,
		vector<pair<int,int>>,
		greater<pair<int,int>>>q;
struct ed 
int dijkstra(){
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	q.push({0,1});
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		int ver=t.second,dis=t.first;
		if(st[ver])continue;
		st[ver]=1;
		for(int i=hesd[ver];i;i=meg[i].ne){
			int j=meg[i].to;
			if(dist[j]>meg[i].w+dis){
				dis=meg[i].w+dis;
				q.push({dis[j],j});
			}
		}
	}
	return dist[n];
}
