#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1000000007;
ll Q,k,l,r,ans;
vector<ll>dp0(100005),dp1(100005),sum(100005);
int main(){
	freopen("run.in","r",stdin);
	freopen("run.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Q>>k;
	dp0[0]=1;
	for(int i=1;i<=100000;i++){
		dp0[i]=(dp0[i-1]+dp1[i-1])%mod;
		if(i>=k)dp1[i]=dp0[i-k];
		ll ways=(dp0[i]+dp1[i])%mod;
		sum[i]=(sum[i-1]+ways)%mod;
	}
	while(Q--){
		cin>>l>>r;
		ans=(sum[r]-sum[l-1]+mod)%mod;
		cout<<ans<<"\n";
	}
}
