#include<bits/stdc++.h>
using namespace std;
long long f[101][101];
int n,m;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i==1||j==1){
				f[i][j]=1;
			}else{
				f[i][j]=f[i-1][j]+f[i][j-1];
			}
		}
	}
	cout<<f[m][n];
} 
