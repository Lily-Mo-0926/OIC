#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int w[10004],v[10004];
int f[10000007];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=v[i];j<=n;j++){
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout<<f[n];
}
