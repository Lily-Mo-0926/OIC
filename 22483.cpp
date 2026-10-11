#include<bits/stdc++.h>
using namespace std;
int T,n,m,e,f;
int a[1005][1005],d[1001][1001];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>e>>f;
		int ans=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				d[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
				if(a[i][j]>d[i][j]){
					int x=a[i][j]-d[i][j];
					if(i+e > n+1 || j+f > m+1)ans=0;
					d[i][j]+=x;
					d[i+e][j]-=x;
					d[i][j+f]-=x;
					d[i+e][j+f]+=x;
				}
			}
		}
		if(ans)
			puts("^_^");
		else
			puts("QAQ");
	}
}
