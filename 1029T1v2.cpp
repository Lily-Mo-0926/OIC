#include<bits/stdc++.h>
using namespace std;
#define int long long
__int128 one=1;
signed main(){
	freopen("settle.in","r",stdin);
	freopen("settle.out","w",stdout);
	int n,a,b,h,w;
	scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&h,&w);
	int l=0,r=1e18,ans;
	while (l<=r){
		int mid=l+r>>1,x=a+2*mid,y=b+2*mid;
		if (one*(h/x)*(w/y)>=n || one*(h/y)*(w/x)>=n) l=mid+1,ans=mid;
		else r=mid-1;
	}
	printf("%lld",ans);
	return 0;
}
