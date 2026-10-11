#include<bits/stdc++.h>
using namespace std;
int T,n,m;
int a[55],b[55];
int f[55][55];
int main(){
	freopen("")
	cin>>T;
	while(T--){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(f,0,sizeof f);
		cin>>n;for(int i=1;i<=n;i++){cin>>a[i];}
		cin>>m;for(int i=1;i<=m;i++){cin>>b[i];}
		if(n<=2&&m<=2){
			int ans=1;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					if(a[i]>b[j]){
						ans++;
					}
				}
			}
			if(ans<3){
				cout<<ans;
			}else {
				cout<<-1;
			}
		}
	}
}
