#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mod,a[100005];
struct node{
	int sum,add,mul;
	int l,r;
}s[400005];
void upd(int p){
	s[p].sum=(s[p<<1].sum+s[p<<1|1].sum)%mod;
}
void pushdown(int p){
	s[p<<1].sum=(s[p<<1].sum*s[p].mul%mod
		+((s[p<<1].r-s[p<<1].l+1)*s[p].add)
		%mod)%mod;
	s[p<<1|1].sum=(s[p<<1|1].sum*s[p].mul%mod
		+((s[p<<1|1].r-s[p<<1|1].l+1)*s[p].add)
		%mod)%mod;
	s[p<<1].mul=(s[p<<1].mul*s[p].mul)%mod;
	s[p<<1|1].mul=(s[p<<1|1].mul*s[p].mul)%mod;
	s[p<<1].add=(s[p<<1].add*s[p].mul%mod+s[p].add)%mod;
	s[p<<1|1].add=(s[p<<1|1].add*s[p].mul%mod+s[p].add)%mod;
	s[p].add=0,s[p].mul=1;
	return;
}
void build(int p,int l,int r){
	s[p].l=l;
	s[p].mul=1;
	s[p].r=r;
	if(l==r){s[p].sum=a[l]%mod;return;}
	int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	upd(p);
	return;
}
void multiment(int p,int x,int y,int k){
	if(x<=s[p].l&&s[p].r<=y){
		s[p].add=(s[p].add*k)%mod;
		s[p].mul=(s[p].mul*k)%mod;
		s[p].sum=(s[p].sum*k)%mod;
		return;
	}
	pushdown(p);
	int mid=s[p].l+s[p].r>>1;
	if(x<=mid)multiment(p<<1,x,y,k);
	if(y>mid)multiment(p<<1|1,x,y,k);
	upd(p);
	return;
}
void addiment(int p,int x,int y,int k){
	if(x<=s[p].l&&s[p].r<=y){
		s[p].add=(s[p].add+k)%mod;
		s[p].sum=(s[p].sum+((s[p].r-s[p].l+1)*k)%mod)%mod;
		return;
	}
	pushdown(p);
	int mid=s[p].l+s[p].r>>1;
	if(x<=mid)addiment(p<<1,x,y,k);
	if(y>mid)addiment(p<<1|1,x,y,k);
	upd(p);
	return;
}
int query(int p,int x,int y){
	if(x<=s[p].l&&y>=s[p].r){
		return s[p].sum;
	}
	pushdown(p);
	int val=0;
	int mid=s[p].l+s[p].r>>1;
	if(x<=mid)val=(val+query(p<<1,x,y))%mod;
	if(y>mid)val=(val+query(p<<1|1,x,y))%mod;
	return val;
}
signed main(){
	cin>>n>>m>>mod;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	for(int i=1,q,x,y,k;i<=m;i++){
		cin>>q>>x>>y;
		if(q==1){
			cin>>k;
			multiment(1,x,y,k);
		}
		else if(q==3){
			cout<<query(1,x,y)<<"\n";
		}else{
			cin>>k;
			addiment(1,x,y,k);
		}
	}
}
