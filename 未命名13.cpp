#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[299900],a[222222],n,m,x[12],ans;
map<int,int> mp;
main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>s[i],a[i+1]=s[i]-a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x[i];
		for(int j=1;j<=n;j++){
			ans=max(ans,++mp[j%2==0?x[i]-a[j]:a[j]-x[i]]);
		}
	}
	cout<<ans;
}
#define int long long
int s[299900],a[222222],n,m,x[12],ans;
map<int,int> mp;
main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>s[i],a[i+1]=s[i]-a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>x[i];
		for(int j=1;j<=n;j++){
			ans=max(ans,++mp[j%2==0?x[i]-a[j]:a[j]-x[i]]);
		}
	}
	cout<<ans;
}
