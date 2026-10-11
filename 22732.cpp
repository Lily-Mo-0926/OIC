#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define LL long long
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
struct node{
	LL res[3],lv[3],rv[3];
	int sum;
}s[N*4];
node operator+ (node a, node b){
	node c=(node){};
	c.sum=(a.sum+b.sum)%3;
	for(int i=0;i<3;i++)c.lv[i]=a.lv[i]+b.lv[(i+3-a.sum)%3];
	for(int i=0;i<3;i++)c.rv[i]=b.rv[i]+a.rv[(i+3-b.sum)%3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			c.res[(i+j)%3]+=a.rv[j]*b.lv[i];
		}
	}
	for(int i=0;i<3;i++)c.res[i]+=a.res[i]+b.res[i];
	return c;
}
int n,m;
inline void change(int l,int r,int v,int x,int y){
	if(l==r){
		s[v]=(node){};
		++s[v].res[s[v].sum=y%3];
		s[v].lv[y%3]++;
		s[v].rv[y%3]++;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		change(l,mid,ls(v),x,y);
	else
		change(mid+1,r,rs(v),x,y);
	s[v]=s[ls(v)]+s[rs(v)];
}
inline node query(int l,int r,int v,int ll,int rr){
	if(ll<=l&&r<=rr){
		return s[v];
	}
	int mid=(l+r)>>1;
	if(ll>mid)
		return query(mid+1,r,rs(v),ll,rr);
	else if(rr<=mid)
		return query(l,mid,ls(v),ll,rr);
	else
		return query(l,mid,ls(v),ll,rr)+query(mid+1,r,rs(v),ll,rr);
}
int main(){
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		change(1,n,1,i,x);
	}
	for(int i=1;i<=m;i++){
		int op,l,r;
		cin>>op>>l>>r;
		if(op==2)cout<<query(1,n,1,l,r).res[0]<<'\n';
		else change(1,n,1,l,r); 
	}
	return 0;
} 
