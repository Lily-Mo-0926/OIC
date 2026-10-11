#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int T;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		int l,r;
		cin>>l>>r;
		l%=9,r%=9;
		r+=9;
		cout<<((l+r)*(r-l+1)/2)%9<<endl;
	}
}
