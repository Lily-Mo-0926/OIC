#include<bits/stdc++.h>
using namespace std;
int dis[4][2]={1,0 ,-1,0 ,0,1 ,0,-1};
bool g[5][5],vis[5][5];
int ans=10;
void md(int x,int y){
	g[x][y]=!g[x][y];
	for(int i=0;i<4;i++){
		g[x+dis[i][0]][y+dis[i][1]]=
			!g[x+dis[i][0]][y+dis[i][1]];
	}
}
bool check(){
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(!g[i][j])
				return 0;
	return 1;
}
void dfs(int stp){
	if(stp>=ans)return;
	if(check()){
		ans=min(ans,stp);
		return;
	}
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			if(!vis[i][j]){
				vis[i][j]=1;
				md(i,j);
				dfs(stp+1);
				md(i,j);
				vis[i][j]=0;
			}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
			cin>>g[i][j];
	dfs(0);
	cout<<ans;
}
