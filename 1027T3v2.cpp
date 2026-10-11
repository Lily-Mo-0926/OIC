#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int T;
int calc(int pl,int pr,int l,int r){
	if(l<=pl&&pr<=r)return pr-pl+1;
	int mid=(pl+pr)>>1;
	if(l>mid)return calc(mid+1,pr,l,r);
	if(r<=mid)return calc(pl,mid,l,r);
	return min(calc(mid+1,pr,l,r)+mid-l+1,mid-pl+1)+calc(pl,mid,l,r);
}//类st表？分治？ 
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("xor");
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		int n,l,r;
		cin>>n>>l>>r;
		if(n==1){
			cout<<(r-l+1)%mod<<endl;
		}else{
			cout<<calc(0,(1ll<<60)-1,l,r)%mod<<endl;//(1ll<<60)的原因是ceil(log(2)1e18)=60; 
		}
	}
}
