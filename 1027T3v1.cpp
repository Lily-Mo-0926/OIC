#include<bits/stdc++.h>
using namespace std;//我要暴力拿部分分 结果也没捞着 
//so you only did the n=1s? yep.
#define int long long
const int mod=1e9+7;
int T;
/*int xoe(int n,int l,int r){
	if(n==1)return l;
	int cnt=0;
	for(int i=1;i<=r-n+1;i++){
		cnt^=xoe(n-1,i,r);
	}
	cout<<cnt<<endl;
	return cnt;
}
int solve(int n,int l,int r){
	if(n==0)return 0;
	return xoe(n,l,r)+solve(n-1,l,r);
}*/void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("xor");
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1){
			cout<<c-b+1<<'\n';
			continue;
		}
		//cout<<solve(a,b,c)<<'\n';
	}
}
