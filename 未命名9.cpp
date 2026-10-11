#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=65536;
ll seed,mul,add,n,k;
signed main(){
	cin>>seed>>mul>>add>>n>>k;
	vector<ll>v,t(n+1);
	t[0]=seed;
	ll ans=0;
	for(int i=0;i<n;i++){
		if(i>0){
			t[i]=(t[i-1]*mul+add)%mod;
		}
		v.insert(lower_bound(v.begin(),v.end(),t[i]),t[i]);
//		cout<<"v ";for(int i=0;i<=n;i++){cout<<v[i]<<' ';}cout<<endl;
//		cout<<"t ";for(int i=0;i<=n;i++){cout<<t[i]<<' ';}cout<<endl;
		if(i>=k-1){
			ans+=v[(k-1)/2];
			v.erase(lower_bound(v.begin(),v.end(),t[i-k+1]));
//			cout<<"Ev ";for(int i=0;i<=n;i++){cout<<v[i]<<' ';}cout<<endl;
//			cout<<"Et ";for(int i=0;i<=n;i++){cout<<t[i]<<' ';}cout<<endl;
		}
	}
	cout<<ans<<"\n";
	return 0;
} 
