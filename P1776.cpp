#include<bits/stdc++.h>
using namespace std;
int n,W;
int v[105],w[105],m[105];
int f[40005];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>W;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i]>>m[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=m[i];k++){
			for(int j=W;j>=w[i];j--){
				f[j]=max(f[j],f[j-w[i]]+v[i]);
			}
		}
	}
	cout<<f[W];
}
