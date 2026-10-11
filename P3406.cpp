#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,pr;
ll s[100005],ans;
int main(){
	cin>>n>>m;
	cin>>pr;
	for(int i=1,x;i<m;i++){
		cin>>x;
		int u=min(x,pr),v=max(x,pr);
		s[u]++,s[v]--;
		pr=x;
	}
	
	for(int i=1;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		s[i]+=s[i-1];
		ans+=min(s[i]*a,s[i]*b+c);
		//cout<<s[i]<<' ';
	}
	cout<<ans<<endl;
}
