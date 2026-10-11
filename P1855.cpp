#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,t,a[105],b[105],f[205][205];
int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
//	memset(f,0,sizeof f);
	f[0][0]=0;
	for(int k=1;k<=n;k++){
		for(int i=m;i>=0;i--){
			if(i<a[k])break;
			for(int j=t;j>=0;j--){
				if(j<b[k])break;
				f[i][j]=max(f[i][j],f[i-a[k]][j-b[k]]+1);
			}
		}
	}
	cout<<f[m][t]<<endl;
} 
