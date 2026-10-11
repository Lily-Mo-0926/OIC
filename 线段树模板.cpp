#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200002],n,m,T,d[1000005],b[1000005];
void build(int s,int t,int p){
    if(s==t){
        d[p]=a[s];
        return;
    }int m=(s+t)/2;
    build(s,m,p*2);
    build(m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}void update(int l,int r,int c,int s,int t,int p){
    if(l<=s&&t<=r){
        d[p]+=(t-s+1)*c;
        b[p]+=c;
        return;
    }int m=(s+t)/2;
    if(b[p]&&s!=t){
        d[p*2]+=b[p]*(m-s+1);
        d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p];b[p*2+1]+=b[p];
        b[p]=0;
    }if(l<=m)update(l,r,c,s,m,p*2);
    if(r>m)update(l,r,c,m+1,t,p*2+1);
    d[p]=d[p*2]+d[p*2+1];
}int getsum(int l,int r,int s,int t,int p){
    if(l<=s&&t<=r)return d[p];
    int m=(s+t)/2;
    if(b[p]){
        d[p*2]+=b[p]*(m-s+1);
        d[p*2+1]+=b[p]*(t-m);
        b[p*2]+=b[p];
        b[p*2+1]+=b[p];
        b[p]=0;
    }int sum=0;
    if(l<=m)sum=getsum(l,r,s,m,p*2);
    if(r>m)sum+=getsum(l,r,m+1,t,p*2+1);
    return sum;
}signed main(){
	cin>>n>>m;
	int x,y,op,k;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,n,1);
	for(int i=0;i<m;i++){
		cin>>op;
		if(op==1){
			cin>>x>>y>>k;
			update(x,y,k,1,n,1);
		}if(op==2){
			cin>>x>>y;
			cout<<getsum(x,y,1,n,1)<<endl;
		}
	}return 0;
} 
