#include<bits/stdc++.h>
using namespace std;
int n,S,q,s[240000],tag[240000];
void build(int o,int l,int r){
	s[o]=S;
	if(l==r){return;}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void pushdown(int o,int l,int r){
	int mid=l+r>>1;
	s[o<<1]+=tag[o];
	s[o<<1|1]+=tag[o];
	tag[o<<1]+=tag[o];
	tag[o<<1|1]+=tag[o];
	tag[o]=0; 
}
void add(int o,int l,int r,int L,int R,int x){
	if(l>=L&&r<=R){
		s[o]+=x;
		tag[o]+=x;
		return;
	}
	pushdown(o,l,r);
	int mid=l+r>>1;
	if(L<=mid){add(o<<1,l,mid,L,R,x);}
	if(R>mid){add(o<<1|1,mid+1,r,L,R,x);}
	s[o]=min(s[o<<1],s[o<<1|1]);
}
int ask(int o,int l,int r,int L,int R){
	if(l>=L&&r<=R){return s[o];}
	pushdown(o,l,r);
	int mid=l+r>>1,res=0x3f3f3f3f;
	if(L<=mid){res=ask(o<<1,l,mid,L,R);}
	if(R>mid){res=min(res,ask(o<<1|1,mid+1,r,L,R));}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>S>>q;
	--n;
	build(1,1,n);
	while(q--){
		int l,r,x;
		cin>>l>>r>>x;
		--r;
		if(ask(1,1,n,l,r)>=x){
			puts("T");
			add(1,1,n,l,r,-x);
		}else{
			puts("N");
		}
	}
	return 0;
}
