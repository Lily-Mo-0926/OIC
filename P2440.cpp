#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
ll n,k;
ll L[10000005],tot;
bool chk(ll x){
	if(x==0){
		return 1;
	}
	ll cnt=0;
	for(int i=n;i>0;i--){
		if(!L[i]/x)return cnt>=k;
		cnt+=L[i]/x;
	}
	return cnt>=k;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>L[i];
		tot=max(tot,L[i]);
	}
	sort(L+1,L+1+n);
	ll l=0,r=tot;
	while(l<r){
		ll mid=(l+r)>>1;
		//cout<<l<<' '<<mid<<' '<<r<<endl;
		if(chk(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	if(!chk(l))cout<<l-1<<endl;
	else cout<<l<<endl;
}
