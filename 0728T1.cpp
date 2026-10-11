#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll a[100005],b[100005],c[100005];
ll w[100005],ans,cnt,fa,fb,fc;
bool cmp(ll x,ll y){
	return x>y;
}
signed main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
	if(m==0){cout<<0;return 0;}
	for(int k=0;k<8;k++){
		fa=(k&4)?1:-1;
		fb=(k&2)?1:-1;
		fc=(k&1)?1:-1;
		for(int i=1;i<=n;i++){
			w[i]=fa*a[i]+fb*b[i]+fc*c[i];
		}
		sort(w+1,w+1+n,cmp);
		cnt=0;
		for(int i=1;i<=m;i++){
			cnt+=w[i];
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
} 
