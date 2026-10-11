#include<bits/stdc++.h>
#define ls cur<<1
#define rs cur<<1|1 
using namespace std;
using ll=long long;
const int mod=1e9+7,N=2e5+5;
int n=1,q,tot;
int a[N],f[N],l[N],r[N],dfn[N],cnt[N];
ll tr[N*4],tg[N*4];
struct Q{
	int op,x;
}qs[N];
vector<int>con[N]; 
ll qpow(ll x,ll y){
	if(!y){
		return 1;
	}
	ll g=qpow(x,y>>1);
	if(y&1ll){
		return g*g%mod*x%mod;
	}
	return g*g%mod;
}
void dfs(int u,int fa){
	dfn[l[u]=++tot]=u;
	f[u]=fa;
	for(int v:con[u]){
		if(v!=fa){
			dfs(v,u);
		}
	}r[u]=tot;
}
void build(int cur,int l,int r){
	tg[cur]=1;
	if(l==r){
		tr[cur]=(l==1)*a[dfn[l]];
		return;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	tr[cur]=(tr[ls]+tr[rs])%mod;
}
void pultz(int cur,ll val){
	(tr[cur]*=val)%=mod;
	(tg[cur]*=val)%=mod;
}
void pd(int cur){
	pultz(ls,tg[cur]);
	pultz(rs,tg[cur]);
	tg[cur]=1;
}
void cg(int cur,int l,int r,int loc){
	if(l==r){
		tr[cur]=a[dfn[r]]*tg[cur]%mod;
		return;
	}
	int mid=l+r>>1;
	pd(cur);
	if(loc<=mid){
		cg(ls,l,mid,loc);
	}else{
		cg(rs,mid+1,r,loc);
	}
	tr[cur]=(tr[ls]+tr[rs])%mod;
}
void mul(int cur,int l,int r,int ql,int qr,ll val){
	if(ql<=l&&r<=qr){
		return pultz(cur,val);
	}
	int mid=l+r>>1;
	pd(cur);
	if(ql<=mid){
		mul(ls,l,mid,ql,qr,val);
	}
	if(qr>mid){
		mul(rs,mid+1,r,ql,qr,val);
	}tr[cur]=(tr[ls]+tr[rs])%mod;
}
ll query(int cur,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr){
		return tr[cur];
	}
	int mid=l+r>>1;
	pd(cur);
	ll res=0;
	if(ql<=mid){
		res=query(ls,l,mid,ql,qr);
	}
	if(qr>mid){
		(res+=query(rs,mid+1,r,ql,qr))%=mod;
	}return res;
}
int main(){
	scanf("%d%d",&a[1],&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qs[i].op,&qs[i].x);
		if(qs[i].op==1){
			scanf("%d",&a[++n]);
			con[qs[i].x].push_back(n);
			qs[i].x=n;
		}
	}
	dfs(1,0);
	cnt[1]=1;
	build(1,1,n);
	for(int i=1;i<=q;i++){
		int u=qs[i].x;
		if(qs[i].op==1){
			cnt[u]=1;
			cg(1,1,n,l[u]);
			cnt[f[u]]++;
			mul(1,1,n,l[f[u]],r[f[u]],cnt[f[u]]*qpow(cnt[f[u]]-1,mod-2)%mod);
		}
		else{
			printf("%lld\n",query(1,1,n,l[u],r[u])*qpow(query(1,1,n,l[u],l[u]),mod-2)%mod*cnt[u]%mod*a[u]%mod);
		}
	}
}
