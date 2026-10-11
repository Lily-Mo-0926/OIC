#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
ll n,m,deg[100005],d[100005],ans;
vector<int>edg[100005];
int main(){
    freopen("vote.in","r",stdin);
    freopen("vote.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0,x,y;i<n;i++){
		cin>>x>>y;
		if(x>y)swap(x,y);
		deg[x]++,deg[y]++;
		edg[x].push_back(y);
	}
	for(int i=1;i<=n;i++)sort(edg[i].begin(),edg[i].end()),d[i]=deg[i];
	sort(d+1,d+1+n);
	for(int i=1;i<=n;i++){
		int f=m-d[i];
		int pos=lower_bound(d+i+1,d+1+n,f)-d-1;
		if(pos<n){
			ans+=(ll)n-pos;
		} 
	}
	for(int u=1;u<=n;u++){
		int len=edg[u].size();
		for(int i=0;i<len;){
			int v=edg[u][i];
			int cnt=0;
			while(i<len&&edg[u][i]==v){
				cnt++,i++;
			}
			ll real=(ll)deg[u]+deg[v]-cnt;
			if(1LL*deg[u]+deg[v]>=m&&real<m){
				ans--;
			}
		} 
	}
	cout<<ans;
} 
