#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;//10pts 
void File(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
    File("mst");
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		int n,m,s;
		cin>>n>>m>>s;
		if(m==n-1){
			cout<<s<<'\n';
			continue;
		}
		m-=n-1;
		int k=s/(n-1),bb=s%(n-1),sb=n-1-bb;
		int ab=(sb+1)*sb/2-sb,res=0;
		// sb条小边连sb+1个点
		// bb条大边连bb+1个点 
		// (sb+1)*sb/2-sb -> 还可以有的小边数 
		//剩下的都是大边数了吧 
	//	cout<<" "<<k<<' '<<bb<<' '<<sb<<' '<<ab<<endl;
		//n-1: s
		if(ab>=m){
			res+=m*k;
		}else{
			res+=ab*k;
			m-=ab;
			res+=m*(k+1);
		}
		
		cout<<res+s<<'\n';
		
	}
}
/*

*/
