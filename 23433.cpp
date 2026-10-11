#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
map<ll,ll>mp;
ll a[105];
ll tot=1;
ll solve1(ll x){
	ll b=x,cnt=1;
	for(ll i=2;i*i<=x;i++){
		while(b%i==0){
			b/=i;
			mp[i]++;
		}
	}
	if(b!=1){mp[b]++;}
	for(auto u:mp){
		for(ll i=0;i<u.second/n;i++){
			cnt*=u.first;
		}
		mp[u.first]/=n;
	}
	return cnt;
}
int solve2(ll x){
	ll b=x,ans=0;
	for(auto u:mp){
		int cnt=0;
		while(b%u.first==0){
			b/=u.first;
			cnt++;
		}
		ans+=max(0ll,u.second-cnt);
	}
	return ans;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		tot*=a[i];
	}
	cout<<solve1(tot)<<' ';
	ll cnt=0;
	for(ll i=1;i<=n;i++){
		cnt+=solve2(a[i]);
	}
	cout<<cnt;
}
