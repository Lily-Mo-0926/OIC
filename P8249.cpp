#include<bits/stdc++.h>
using namespace std;
int a,b,q,l,r;
int main(){
	cin>>a>>b>>q;
	while(q--){
		int ans=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			int x=(i%a)+(i%b);
			cout<<(i%a)<<" + "<<(i%b)
			<<" = "<<x<<"\n";
			ans=max(ans,x);
		}
		cout<<ans<<"\n";
		cout<<"\n";
	}
} 
