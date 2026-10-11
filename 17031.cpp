#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,cnt[10010][110],col[110][110],ans,tot,sum; 
int main(){
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		sum=0;
		for(int j=1;j<=m;j++){
			cin>>col[i][j];
			for(int k=1;k<=i;k++){
				for(int l=1;l<=k;l++){
					sum+=j-cnt[col[k][j]][l];
					cnt[col[k][j]][l]=j;
				}
			}
			ans+=sum;
			tot+=i*j;
		}
	}
	printf("%.9lf\n",ans*1.0/(double)tot);
} 
