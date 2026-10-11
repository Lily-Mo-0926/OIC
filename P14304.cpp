#include<bits/stdc++.h>
using namespace std;
#define int long long 
int Q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>Q;
	while(Q--){
		int n;
		cin>>n;
		int ans=0,num=floor(sqrt(n));
		ans+=(num-1)*3;
		for(int i=num*num;i<=n;i+=num){
			ans++;
		}cout<<ans<<'\n';
	}
}
