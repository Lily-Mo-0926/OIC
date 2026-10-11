#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,u[100005],v[100005];
int cnt1,cnt2,cnt3,d1[100005],d2[100005];
int l=1,r=1,zw[100005],w[100005],ret;
signed main(){
	cin>>n>>m;
	for(int i=1,a,b,c;i<=m;i++)cin>>a>>b>>c,zw[a]+=c,zw[b]-=c;
	for(int i=1;i<=n;i++){
		if(zw[i]>0)d1[++cnt1]=i;
		if(zw[i]<0)d2[++cnt2]=i;
	}
	while(l<=cnt1){
		ret=min(zw[d1[l]],-zw[d2[r]]);
		zw[d1[l]]-=ret;
		zw[d2[r]]+=ret;
		u[++cnt3]=d1[l];
		v[cnt3]=d2[r];
		w[cnt3]=ret;
		if(!zw[d1[l]])++l;
		if(!zw[d2[r]])++r;
	}
	cout<<cnt3<<endl;
	for(int i=1;i<=cnt3;i++){
		cout<<u[i]<<' '<<v[i]<<" "<<w[i]<<"\n";
	}
}
