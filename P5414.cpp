#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int T,n,f[105],a[105],sum,mx;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		mx=sum=0;
		memset(a,0,sizeof a);
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			cin>>a[i];sum+=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(a[i]>=a[j]){
					f[i]=max(f[i],f[j]);
				}
			}
			f[i]+=a[i];
		}
		for(int i=1;i<=n;i++)mx=max(mx,f[i]);
		cout<<sum-mx<<endl;
	}
} 
