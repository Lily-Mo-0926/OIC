#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=20002;
int ans,n,m,k,l[N],r[N],a[55][N],dp[55][N],qzh[55][N];
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			cin>>a[i][j],qzh[i][j]=qzh[i][j-1]+a[i][j];
	for (int i=1;i<=n;i++){
		for (int j=1;j+k-1<=m;j++){
			int t=qzh[i][j+k-1]-qzh[i][j-1]+qzh[i+1][j+k-1]-qzh[i+1][j-1];
			dp[i][j]=max(dp[i][j],l[j-1]+t);
			for (int z=j-k+1;z<=j+k-1;z++){
				int x=t;
				if(i!=1){
					if(j>=z)x-=qzh[i][z+k-1]-qzh[i][j-1];
					else x-=qzh[i][j+k-1]-qzh[i][z-1];
				}
				dp[i][j]=max(dp[i][j],dp[i-1][z]+x);
			}
			dp[i][j]=max(dp[i][j],r[j+k]+t);
		}
		int mx=0;
		for(int j=1;j+k-1<=m;j++) mx=max(mx,dp[i][j]),l[j+k-1]=mx;
		mx=0;
		for (int j=m-k+1;j>=1;j--)mx=max(mx,dp[i][j]),r[j]=mx;
	}
	for (int i=1;i+k-1<=m;i++) ans=max(ans,dp[n][i]);
	cout<<ans;
	return 0;
}
