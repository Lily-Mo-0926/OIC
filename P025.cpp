#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[205][7];
int main(){
	f[1][1]=1;
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		f[i][1]=1;
		for(int j=2;j<=k;j++){
			if(i-j>=0) 
				f[i][j]=f[i-1][j-1]+f[i-j][j]; 
		}
	}
	cout<<f[n][k];
}
