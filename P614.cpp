#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans=1e9+7;
int a[3003];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=a[i];
		if(i>m){
			cnt-=a[i-m];
		}
		if(i>=m){
			ans=min(ans,cnt);
			cout<<cnt<<' '<<ans<<endl; 
		}
	}
	cout<<ans;
} 
