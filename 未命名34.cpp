#include<bits/stdc++.h>
using namespace std;
int ans[100005];
int x[100005],y[100005];
bool vis[100005],can[100005];
int n,k,cnt;
void find(int u,int sel){
	vis[u]=1;
	if(!sel){
		ans[++cnt]=u;
	}
	if(!vis[x[u]]){
		find(x[u],1^sel);
	}
	if(!vis[y[u]]){
		find(y[u],1^sel);
	}
}
int main(){
	freopen("iceball.in","r",stdin);
	freopen("iceball.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n/2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		x[u]=v;
		x[v]=u;
	}
	for(int i=1;i<=n/2;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		y[u]=v;
		y[v]=u;
	}
	scanf("%d",&k);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			find(i,0);
		}
	}
	if(cnt<k){
		puts("0");
		return 0;
	}for(int i=1;i<=k;i++){
		cout<<ans[i]<<' ';
	}
}
