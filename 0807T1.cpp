#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long  ll;
int n,m;
const ll INF=(1LL<<60);
ll gta(const vector<vector<int>>&bad,int u,ll cur){
	const vector<int>&v=bad[u];
	if(v.empty())return cur;
	auto it=lower_bound(v.begin(),v.end(),cur);
	if(it==v.end()||*it!=cur)return cur;
	int pos=it-v.begin();
	ll base=(ll)v[pos]-pos;
	int l=pos,r=(int)v.size();
	while(l<r){
		int mid=(l+r)>>1;
		ll diff=(ll)v[mid]-mid;
		if(diff<=base){
			l=mid+1;
		}else{r=mid;}
	}
	int last=l-1;
	return (ll)v[last]+1;
}
int main(){
	freopen("planet.in","r",stdin);
	freopen("planet.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	vector<vector<pair<int,int>>>g(n+1);
	for(int i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	vector<vector<int>>bad(n+1);
	for(int i=1,k;i<=n;i++){
		cin>>k;
		bad[i].resize(k);
		for(int j=0;j<k;j++){
			cin>>bad[i][j];
		}
	}
	vector<ll>dist(n+1,INF);
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
	dist[1]=0;
	pq.push({0,1});
	while(!pq.empty()){
		ll d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d!=dist[u])continue;
		if(u==n)break;
		ll dpt=gta(bad,u,d);
		for(auto x:g[u]){
			int v=x.first,w=x.second;
			ll nd=dpt+w;
			if(nd<dist[v]){
				dist[v]=nd;
				pq.push({nd,v});
			}
		}
	}
	cout<<(dist[n]==INF?-1:dist[n])<<endl;
}
