#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans,t[50005][505];
vector<int> v[50005];
void dfs(int x,int f){
	t[x][0]++;
	for(auto i:v[x])
		if(i!=f){
			dfs(i,x);
			for(int j=0;j<k;j++)
				ans+=t[x][j]*t[i][k-j-1];
			for(int j=0;j<k;j++)
				t[x][j+1]+=t[i][j];
		}
} 
signed main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,w;
		cin>>u>>w;
		v[u].push_back(w);
		v[w].push_back(u);
	}
	dfs(1,-1);
	cout<<ans;
}
