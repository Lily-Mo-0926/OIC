#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll f[305][305][305],a,b,c,d,e,gf;
int n,m,ans;
set<pair<ll,ll>>mp;
int main(){
	cin>>n>>m>>a>>b>>c>>d>>e>>gf;
	for(int i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		mp.insert({u,v});
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j+i<=n;j++){
			for(int k=0;k+j+i<=n;k++){
				int x=a*i+c*j+e*k, y=b*i+d*j+gf*k;
				f[0][0][0]=1;
				if(!mp.count({x,y})){
					if(i)f[i][j][k]=f[i-1][j][k];
					if(j)f[i][j][k]=(f[i][j][k]+f[i][j-1][k])%mod;
					if(k)f[i][j][k]=(f[i][j][k]+f[i][j][k-1])%mod;
				}
				if(i+j+k==n)ans=(ans+f[i][j][k])%mod;
			}
		}
	}
	cout<<ans;
}
