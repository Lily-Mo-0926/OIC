#include<bits/stdc++.h>
using namespace std;
vector<int>gph[100005];
int a[100005];
int n,m,ans;
void dfs(int i,int fa,int ct){
	ct=ct*a[i]+a[i];
	if(ct>m){
		return;
	}
	if(gph[i].size()==1&&i!=1){
		ans++;
		return;
	}
	for(auto u:gph[i]){
		if(u!=fa){
			dfs(u,i,ct);
		}
	}
}
int main(){
	freopen("park.in","r",stdin);
	freopen("park.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
//	fa[1]=0;
	for(int i=1,x,y;i<=n-1;i++){
		cin>>x>>y;
		gph[x].push_back(y);
		gph[y].push_back(x);
	}
	dfs(1,0,0); 
	cout<<ans<<endl; 
} 
