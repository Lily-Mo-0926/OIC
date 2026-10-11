#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int c,x,y,t1,t2;
int f[503],g[503];
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c>>x>>y;
		for(int j=0;j<=k;j++){
			g[j]=f[j];
		}
		while(c--){
			cin>>t1>>t2;
			for(int j=k;j>=t1;j--){
				g[j]=max(g[j],g[j-t1]+t2);
			}
		}
		for(int j=k;j>=x;j--)g[j]=g[j-x]+y;
		for(int j=k;j>=x;j--)f[j]=max(f[j],g[j]);
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
} 
