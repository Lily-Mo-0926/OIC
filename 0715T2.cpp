#include<bits/stdc++.h>
using namespace std;
int r,s,p;
double dp[105][105][105];
int main(){
	cin>>r>>s>>p;
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			dp[i][j][0]=1;
			for(int k=1;k<=100;k++){
				int tot=i*j+j*k+k*i;
				dp[i][j][k]=(double)(i*j*dp[i][j-1][k]+j*k*dp[i][j][k-1]+k*i*dp[i-1][j][k])/(double)tot;
			}
		}
	}
	printf("%.12lf %.12lf %.12lf ",dp[r][s][p],dp[s][p][r],dp[p][r][s]);
} 
