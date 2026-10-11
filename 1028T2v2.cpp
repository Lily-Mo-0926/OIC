#include<stdio.h>
#include<algorithm>
#include<iostream>
#define ll long long

ll T,n,m,s,d,k,v,r,ans;

signed main(){
	freopen("mst2.in","r",stdin);
	freopen("mst.out","w",stdout);

	scanf("%lld",&T);

	while(T--){
		scanf("%lld%lld%lld",&n,&m,&s);
		d=(n-1)*(n-2)/2,k=m-d;
//		std::cout<<d<<' '<<k<<std::endl;
		if(k<=0) ans=s-n+m+1;
		else if(d>=k*(n-2)) ans=(s-n+1)*k+m;
		else{
			v=s/(n-1),r=s%(n-1);
			ans=d*v+k*(v+r);
//			std::cout<<v<<' '<<r<<std::endl;
			std::cout<<d*(v+1)-(n-r)*(n-r-1)/2+k*(v+1)<<std::endl;
			if(r) ans=std::min(ans,d*(v+1)-(n-r)*(n-r-1)/2+k*(v+1));
		}

		printf("%lld\n",ans);
	}

	return 0;
}
