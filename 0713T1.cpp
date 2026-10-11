#include<bits/stdc++.h>
using namespace std;
int n,a[1005][1005],dp[2100005][20];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	memset(dp,0x3f,sizeof dp);
	dp[2][1]=0;
	for(int j=0;j<(1<<n+1);j+=2)
		for(int i=1;i<=n;i++)
			if(j&(1<<i)) 
				for(int k=1;k<=n;k++)
					if(i!=k)
						dp[j|(1<<k)][k]=min(dp[j|(1<<k)][k],dp[j][i]+a[i][k]);
	cout<<dp[(1<<n+1)-2][n];
}
