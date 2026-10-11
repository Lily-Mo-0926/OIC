#include<bits/stdc++.h>
using namespace std;
int n,T,ans,odr[200005];
vector<int>g[200005];
bool cmp(int a,int b){
	return g[a].size()>g[b].size();
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1,x,y;i<n;i++){
		 cin>>x>>y;
		 g[x].push_back(y);
		 g[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end());
		odr[i]=i;
	}
	sort(odr+1,odr+1+n,cmp);
	ans=0;
	for(int u=1;u<=n;u++){
		int bnn=-1e9,mxn=0,bso;
		for(int v=1;v<=n;v++){
			if(v==u)continue;
			bool flg=binary_search(g[u].begin(),g[u].end(),v);
			if(!flg){
				bnn=g[v].size();
				break;
			}
		}
		for(int v:g[u]){
			mxn=max(mxn,(int)g[v].size());
		}
		bso=max(mxn-1,bnn);
		ans=max(ans,(int)g[u].size()-1+bso);
	}
	cout<<ans<<endl;
}
int main(){
	freopen("remove.in","r",stdin);
	freopen("remove.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
}
