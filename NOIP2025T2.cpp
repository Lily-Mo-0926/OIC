#include<bits/stdc++.h>
using namespace std;
#define int long long
int cid,t,n,m;
const int nr=5010,mod=998244353;
int c[nr][nr],pw[nr];
int a[nr];
bool cmp(int x,int y){
	return x>y;
}
int C(int x,int y){
	if(x<0||y<0||x<y){
		return 0;
	}
	return c[x][y];
}
signed main(){
//	freopen("sale.in","r",stdin);
//	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>t;
	for(int i=0;i<=5000;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++){
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	pw[0]=1;
	for(int i=1;i<=5000;i++)pw[i]=(pw[i-1]<<1)%mod;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos=i;
			while(pos<=n&&a[pos]==a[i])pos++;
			int k=n+1;
			for(int j=pos;j<=n&&a[j]*2>a[i];j++){
				while(a[j]+a[k-1]<a[i]){
					k--;
				}ans+=C(j-2,m-i-1)*pw[n-k+1];
				ans%=mod;
			} 
		}
		cout<<(pw[n]+mod-ans)%mod<<"\n"; 
	}
}
