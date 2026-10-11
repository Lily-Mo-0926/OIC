#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>pre(8008,-4e18),cur(8008,-4e18);
deque<int>dq;
ll a[8008],ans=-4e18;
int n,k,x;
int main(){
	freopen("photo.in","r",stdin);
	freopen("photo.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i<=k)pre[i]=a[i];
	}
	for(int j=2;j<=x;j++){
		fill(cur.begin(),cur.end(),-4e18);
		dq.clear();
		for(int i=1;i<=n;i++){
			int idx=i-1;
			if(idx>0&&pre[idx]!=-1e9){
				while(!dq.empty()&&pre[dq.back()]<=pre[idx])dq.pop_back();
				dq.push_back(idx);
			}
			while(!dq.empty()&&dq.front()<i-k)dq.pop_front();
			if(!dq.empty())cur[i]=pre[dq.front()]+a[i];
		}
		pre=cur;
	}
	for(int i=n-k+1;i<=n;i++)ans=max(ans,pre[i]);
	if(ans==-4e18)cout<<-1<<"\n";
	else cout<<ans<<"\n";
}
