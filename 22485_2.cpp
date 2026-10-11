#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define dou long double
#define F(i,l,r) for(ll i=l;i<=r;i++)
const ll A=2e5+5;
ll n,L,R,a[A],w[A],z,m;
dou s[A];
bool chk(dou x){
	F(i,1,n+n)s[i]=s[i-1]+a[i]-x;
	deque<ll>q[2];
	F(i,1,n-L+1){
		while(q[i%2].size()&&s[q[i%2].back()]>s[i])q[i%2].pop_back();
		q[i%2].push_back(i);
	}
	F(i,n+1,n+n){
		F(x,0,1)while(q[x].size()&&q[x].front()<i-R-1)q[x].pop_front();
		if(q[i%2].size()&&s[q[i%2].front()]<=s[i]){
			z=w[i]-w[q[i%2].front()],
			m=i-q[i%2].front();
			return 1;
		}
		ll p=i-L+1;
		while(q[p%2].size()&&s[q[p%2].back()]>s[p])q[p%2].pop_back();
		q[p%2].push_back(p);
	}
	return 0;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);
	F(i,1,n)scanf("%Lf",&a[i]),a[i+n]=a[i];
	F(i,1,n+n)w[i]=w[i-1]+a[i];
	dou l=0,r=1e9;
	while(l+1e-9<r){
		dou mid=(l+r)/2;
		if(chk(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	long long g=__gcd(z,m);
	z/=g,m/=g;
	cout<<z;
	if(m>1){
		cout<<"/"<<m;
	}
	return 0;
}
