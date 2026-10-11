#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long  ll;
ll sa[100005],sb[100005],ans=4e18; 
ll a[100005],b[100005],c[200005];
int n,m,d;
ll cac(ll x){
	int p=lower_bound(a+1,a+1+n,x)-a-1,
	q=upper_bound(b+1,b+1+m,x)-b-1,f;
	f=m-q;
	ll ca=1ll*p*x-sa[p],
	cb=sb[m]-sb[q]-1ll*f*x;
	return ca+cb;
}
int main(){
	freopen("add.in","r",stdin);
	freopen("add.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],c[i]=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sa[i]=sa[i-1]+1ll*a[i];
	for(int i=1;i<=m;i++)cin>>b[i],c[i+n]=b[i];
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++)sb[i]=sb[i-1]+1ll*b[i];
	sort(c+1,c+n+1+m);
	d=unique(c+1,c+1+n+m)-c-1;
	for(int i=1;i<=d;i++){
		ans=min(ans,cac(c[i]));
	}
	cout<<ans;
}
