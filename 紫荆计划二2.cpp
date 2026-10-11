#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=105*105*105;
int x,y,z,mx;
int qx[maxn],qy[maxn],qz[maxn],cost[maxn],cost2[maxn],ans[maxn];
int head,tail;
int dis[102][102][102];
int dp[maxn];
void ins(int x,int y,int z,int d){
	if(dis[x][y][z]!=-1)return;
	dis[x][y][z]=d;
	tail++;
	qx[tail]=x;qy[tail]=y;qz[tail]=z;
}
void check(int x,int d){
	if(cost2[x]==-1)cost2[x]=d;
	cost2[x]=min(cost2[x],d);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>x>>y>>z>>mx;
	head=1;
	tail=0;
	memset(dis,-1,sizeof dis);
	memset(cost,-1,sizeof cost);
	memset(cost2,-1,sizeof cost2);
	ins(0,0,0,0);
	while(head<=tail){
		int X=qx[head],Y=qy[head],Z=qz[head],d=dis[X][Y][Z];
		if(cost[X+Y+Z]==-1)cost[X+Y+Z]=d+(X!=0)+(Y!=0)+(Z!=0);
		cost[X+Y+Z]=min(cost[X+Y+Z],d+(X!=0)+(Y!=0)+(Z!=0));
		
		check(X,d+1);
		check(Y,d+1);
		check(Z,d+1);
		
		check(X+Y,d+2);
		check(Y+Z,d+2);
		check(Z+X,d+2);
		
		ins(x,Y,Z,d+1);
		ins(X,y,Z,d+1);
		ins(X,Y,z,d+1);
		
		ins(0,Y,Z,d+1);
		ins(X,0,Z,d+1);
		ins(X,Y,0,d+1);
		int tt;
		tt=min(X,y-Y);
		ins(X-tt,Y+tt,Z,d+1);
		tt=min(X,z-Z);
		ins(X-tt,Y,Z+tt,d+1);
		tt=min(Y,x-X);
		ins(X+tt,Y-tt,Z,d+1);
		tt=min(Y,z-Z);
		ins(X,Y-tt,Z+tt,d+1);
		tt=min(Z,x-X);
		ins(X+tt,Y,Z-tt,d+1);
		tt=min(Z,y-Y);
		ins(X,Y+tt,Z-tt,d+1);
	}
	memset(dp,-1,sizeof dp);
	memset(ans,-1,sizeof ans);
	dp[0]=0;
	for(int i=0;i<mx;i++){
		if(dp[i]!=-1){
			for(int j=1;j<=x+y+z;j++){
				if(cost[j]!=-1&&i+j<=mx){
					if(dp[i+j]==-1)dp[i+j]=dp[i]+cost[j];
					dp[i+j]=min(dp[i+j],dp[i]+cost[j]);
					if(ans[i+j]==-1)ans[i+j]=dp[i]+cost[j];
					ans[i+j]=min(ans[i+j],dp[i]+cost[j]);
				}
			}
			for(int j=1;j<=x+y+z;j++){
				if(cost2[j]!=-1&&i+j<=mx){
					if(ans[i+j]==-1)ans[i+j]=dp[i]+cost2[j];
					ans[i+j]=min(ans[i+j],dp[i]+cost2[j]);
				}
			}
		}
	}
	for(int i=1;i<=mx;i++)cout<<ans[i]<<' '; cout<<endl;
}
