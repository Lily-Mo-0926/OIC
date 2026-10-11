#include<bits/stdc++.h>
using namespace std;
void dijkstra(){
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			if(!k&&!pd[j]){
				k=j;
				continue;
			}if(!pd[j]&&(dis[k]>dis[j])&&dis[j]!=1e9)k=j;
		}
		pd[k]=1;
		for(int j=0;j<a[k].size();j++){
			dis[a[k][j].v]=min(dis[a[k][j].v],dis[k]+a[k][j].w);
		}
	}
}
void dijkstra(){
	q.push({0,s});
	while(!q.empty()){
		if(pd[q.top().y]){
			q.pop();
			continue;
		}
		dis[q.top().y]=q.top().x;
		pd[q.top().y]=1;
		for(int j = 0;j<a[q.top().y].size();j++){
			q.push({q.top().x+a[q.top().y][j].w,a[q.top().y][j].v});
		}
		q.pop();
	}
}

