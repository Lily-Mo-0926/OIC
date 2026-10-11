#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,w,sj;
int a[200005];
signed main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		int s,t,p;
		cin>>s>>t>>p;
		a[s+1]+=p;
		a[t+1]-=p;
		sj=max(sj,t);
	}for(int i=1;i<=sj+1;i++){
		a[i]+=a[i-1];
		//cout<<a[i]<<endl;
		if(a[i]>w){
			cout<<"No";
			return 0;
		}
	}cout<<"Yes";
}
