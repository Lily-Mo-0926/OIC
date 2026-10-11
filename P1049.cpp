#include<bits/stdc++.h>
using namespace std;
int a[31],v,n,f[20001];
int main(){
	cin>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=v;j>=a[i];j--){
			f[j]=max(f[j],f[j-a[i]]+a[i]);
		}
	}
/*	sort(a+1,a+1+n);
	for(int i=v;i>=0;i--){
		for(int j=1;j<n;j++){
			if(i>=a[j]&&dp[i]){
				dp[i-a[j]]=1;
				if(i==a[j]){
					cout<<0;
					exit(0);
				}
			}
		}
	}*/
	cout<<v-f[v];
}
