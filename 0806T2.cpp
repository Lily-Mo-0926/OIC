#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2002;
const ll INF=4e18;
int n;
ll x[N],y[N],c[N],k[N];
ll dist[N];
int pre[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>k[i];
	for(int i=1;i<=n;i++){
		dist[i]=c[i];
		pre[i]=0;
	}
	dist[0]=0;pre[0]=-1;
	ll tot=0;
	vector<int> st;
	vector<pair<int,int> >edge;
	for(int cnt=0;cnt<=n;cnt++){
		int u=-1;
		ll best=INF;
		for(int i=0;i<=n;i++){
			if(!vis[i]&&dist[i]<best){
				best=dist[i];
				u=i;
			}
		}if(u==-1)break;
		vis[u]=1;
		tot+=best;
		if(u){
			if(!pre[u])st.push_back(u);
			else edge.push_back({pre[u],u});
		}
		if(!u)continue;
		for(int v=1;v<=n;v++){
			if(vis[v])continue;
			ll w=(k[u]+k[v])*(abs(x[u]-x[v])+abs(y[u]-y[v]));
			if(w<dist[v]){
				dist[v]=w;
				pre[v]=u;
			}
		}
	}
	cout<<tot<<'\n';
	cout<<st.size()<<'\n';
	for(int u:st)cout<<u<<' ';
	cout<<'\n';
	cout<<edge.size()<<'\n';
	for(auto &e:edge)cout<<e.first<<' '<<e.second<<'\n';
}
