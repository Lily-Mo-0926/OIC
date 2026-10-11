#include<bits/stdc++.h>
using namespace std;
int a[200005],cnt[1000005],asr[200005];
int n,m,blk,ans;
struct Query{
	int l,r,id;
}q[200005];
bool cmp(const Query &x,const Query &y){
	int bx=x.l/blk,by=y.l/blk;
	if(bx!=by)return bx<by;
	if(bx&1)return x.r<y.r;
	return x.r>y.r;
}
inline void add(int pos){
	int v=a[pos];
	if(cnt[v]==0)++ans;
	++cnt[v];
}
inline void del(int pos){
	int v=a[pos];
	--cnt[v];
	if(cnt[v]==0)--ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	blk=sqrt(n);
	sort(q+1,q+1+m,cmp);
	int curl=1,curr=0;
	for(int i=1;i<=m;i++){
		int l=q[i].l,r=q[i].r;
		while(curl>l)add(--curl);
		while(curr<r)add(++curr);
		while(curl<l)del(curl++);
		while(curr>r)del(curr--);
		asr[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++){
		cout<<asr[i]<<"\n";
	}
}
