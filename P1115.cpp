#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
int n,a[200005],f[200005],ans=-2e9-7;
int main(){
	cin>>n;
	f[0]=-2e9-7;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=-2e9-7;
	}
//	f[1]=a[1]; 
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1]+a[i],a[i]);
		ans=max(ans,f[i]);
	}
	cout<<ans<<endl;
} 
