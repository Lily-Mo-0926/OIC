#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mx,my;
int g[30][30];//n,m
int dx[8]={1,2,2,1,-1,-2,-2,-1},dy[8]={2,1,-1,-2,-2,-1,1,2};
void solbe(int u,int v){
	g[u][v]=-1;
	for(int i=0;i<8;i++){
		int x=u+dx[i],y=v+dy[i];
		if(0<x&&0<y&&n>=x&&m>=y){g[x][y]=-1;}
	}
}
signed main(){
	cin>>n>>m>>mx>>my;
	n++,m++;
	mx++,my++;
	g[0][1]=1;
	solbe(mx,my);
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<g[i][j]<<' ';cout<<endl;}cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]!=0){
				g[i][j]=0;
			}else{
				g[i][j]=g[i-1][j]+g[i][j-1];
			}
		}
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<g[i][j]<<' ';cout<<endl;}cout<<endl;
	cout<<g[n][m];
}
