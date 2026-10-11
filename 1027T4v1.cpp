#include<bits/stdc++.h>
using namespace std;//im going to do the 'no' cases
//结果没骗到分，下次老实写暴力吧 
int n,m,a[1001];
int vis[1001];
int len;
pair<int,int>ans[514191];
void dfs(int stp){
	if(vis[1]==0&&vis[2]==1||vis[n]==0&&vis[n-1]==1){return;}
	bool f=(a[1]==1);
	for(int i=2;i<n;i++){
		if(!vis[i]&&vis[i-1]&&vis[i+1]){return;}
		f=(a[i]==i);
	}
	if(f){
		cout<<len<<'\n';
		for(int i=1;i<=len;i++){//also can consider about vector
			cout<<ans[i].first<<' '<<ans[i].second<<'\n';
		}exit(0);
	}
	if(stp>=m)return;
	for(int i=1;i<n;i++){
		if(!vis[i]&&!vis[i+1]){
			ans[++len]={i,i+1};
			swap(a[i],a[i+1]);
			vis[i]=(a[i]==i);
			vis[i+1]=(a[i+1]==i+1);
			dfs(stp+1);
			len--;
			swap(a[i],a[i+1]);
			vis[i]=0;
			vis[i+1]=0;
		}
	}
	
}
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("dmgz");
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){vis[a[i]]=1;}
	}
	if(vis[1]==0&&vis[2]==1||vis[n]==0&&vis[n-1]==1){cout<<"NO";return 0;}
	for(int i=2;i<n;i++){
		if(!vis[i]&&vis[i-1]&&vis[i+1]){cout<<"NO";return 0;}
	}
	cout<<"YES"<<endl;
	dfs(0);
}
