#include<bits/stdc++.h>
using namespace std;
int s[4],ans;
int a[30],f[1205];
int main(){
	for(int i=0;i<4;i++)cin>>s[i];
	for(int i=0;i<4;i++){
		memset(f,0,sizeof f);
		int v2=0;
		for(int p=1;p<=s[i];p++){
			cin>>a[p];
			v2+=a[p];
		}
		int v=v2>>1;
		for(int j=1;j<=s[i];j++){
			for(int k=v;k>=a[j];k--){
				f[k]=max(f[k],f[k-a[j]]+a[j]);
			}
		}
		ans+=max(f[v],v2-f[v]);
	}
	cout<<ans;
}
