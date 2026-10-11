#include <bits/stdc++.h>
using namespace std;
#define pb emplace_back
int const N= 501;
int n,Q,f[N][N][2],C[N];
vector<int> g[N];
void dfs(int x){
	f[x][1][0]=f[x][1][1]=0;
	for(auto y:g[x]){
		dfs(y);
		for(int j=n;j>1;j--)
			for(int k=1;k<j;k++)
				f[x][j][0]=min( f[x][j][0],f[x][k][0]+f[y][j-k][0]+C[y]*2),
				f[x][j][1]=min({f[x][j][1],f[x][k][1]+f[y][j-k][0]+C[y]*2,
								f[x][k][0]+f[y][j-k][1]+C[y]});
	}
}
main(){
	int t=1;
	while(scanf("%d",&n) && n){
		printf("Case %d:\n",t++);
		memset(f,0x3f,sizeof(f));
		for(int i=0;i<n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int x,d;
			scanf("%d%d",&x,&d);
			g[x].pb(i);
			C[i]=d;
		}
		dfs(0);
		scanf("%d",&Q);
		while(Q--){
			int x,k=n;
			scanf("%d",&x);
			while(f[0][k][0]>x && f[0][k][1]>x)k--;
			printf("%d\n",k);
		}
	}
}
