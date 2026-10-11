#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105],b[105];
int mx,ans=-1;
bitset<10005>f[10005]; 
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx+=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=mx;j>=a[i];j--){
			f[j]|=(f[j-a[i]]<<b[i]);
		}
	}
	for(int i=1;i<=mx;i++){
		if(!(i%k)&&f[i][i/k]){
			ans=max(ans,i);
		}
	}
	cout<<ans;
}
