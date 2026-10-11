#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
ld f[22][1<<18],ans=1e18;
int n,m,x[22],y[22];
ld dis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
} 
signed main(){
	freopen("visit.in","r",stdin);
	freopen("visit.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n+m;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n+m;i++)
		for(int s=0;s<(1<<n+m);s++)
			f[i][s]=1e18;
	for(int i=1;i<=n+m;i++)
		f[i][1<<i-1]=dis(0,0,x[i],y[i]);
	for(int s=1;s<(1<<(n+m));s++){
		ld v=(1ll<<(__builtin_popcount(s>>n)));
		for(int i=1;i<=n+m;i++){
			if(!(s&(1<<i-1)))
				continue;
			for(int j=1;j<=n+m;j++)
				if(!(s&(1<<j-1)))
					f[j][s|(1<<j-1)]=
						min(f[j][s|(1<<j-1)],f[i][s]+dis(x[i],y[i],x[j],y[j])/v);
		}
	}
	for(int i=1;i<=n+m;i++)
		for(int s=(1<<n)-1;s<(1<<n+m);s+=(1<<n)){
			ld v=(1ll<<(__builtin_popcount(s>>n)));
			ans=min(ans,f[i][s]+dis(0,0,x[i],y[i])/v);
		}
	printf("%.7Lf",ans);
}
