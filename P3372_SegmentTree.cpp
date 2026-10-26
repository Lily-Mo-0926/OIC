#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100005];
int shu[400005],mk[400005];
void build(int l,int r,int p){
	if(l==r)shu[p]=a[l];
	else{
		int mid=l+r>>1;
		build(l,mid,p<<1);
		build(mid+1,r,p<<1|1);
		shu[p]=shu[p<<1]+shu[p<<1|1];
	}
}
void pshdwm(int p,int len){
	mk[p<<1]+=mk[p];
	mk[p<<1|1]+=mk[p];
	shu[p<<1]+=mk[p]*(len-(len>>1));
	shu[p<<1|1]+=mk[p]*(len>>1);
	mk[p]=0;
}
void upd(int l,int r,int d,int p,int cl,int cr){
	if(cl>r||cr<l){
		return;
	}else if(cl>=l&&cr<=r){
		shu[p]+=(cr-cl+1)*d;
		if(cr>cl)mk[p]+=d;
	}else{
		int mid=cl+cr>>1;
		pshdwm(p,cr-cl+1);
		upd(l,r,d,p<<1,cl,mid);
		upd(l,r,d,p<<1|1,mid+1,cr);
		shu[p]=shu[p<<1]+shu[p<<1|1]; 
	}
}
int query(int l,int r,int p,int cl,int cr){
	if(cl>r||cr<l){
		return 0;
	}else if(cl>=l&&cr<=r){
		return shu[p];
	}else{
		int mid=cl+cr>>1;
		pshdwm(p,cr-cl+1);
		return query(l,r,p<<1,cl,mid)+query(l,r,p<<1|1,mid+1,cr); 
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=1,q,x,y,k;i<=m;i++){
		cin>>q>>x>>y;
		if(q==1){
			cin>>k;
			upd(x,y,k,1,1,n);
		}
		if(q==2){
			cout<<query(x,y,1,1,n)<<"\n";
		}
	}
}
