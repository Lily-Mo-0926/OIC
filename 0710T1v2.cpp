#include<bits/stdc++.h>
using namespace std;
int n,L;
int l[1005],w[1005];
int mx,ans=-1;
//bitset<10005>f[10005]; 
int dp[9005][3]; 
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>L;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>w[i];
		ans=max(ans,w[i]);
		for(int j=L;j>=((l[i]+1)>>1);j--){
			for(int k=2;k>=0;k--){
				if(j>=l[i]){
					dp[j][k]=max(dp[j][k],dp[j-l[i]][k]+w[i]);
				}if(k>=1){
					dp[j][k]=max(dp[j][k],dp[j-((l[i]+1)>>1)][k-1]+w[i]);
				}
				ans=max(ans,dp[j][k]);
			}
		}   
	}
	cout<<ans;
}
