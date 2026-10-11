#include<bits/stdc++.h>
using namespace std;
int n,tar;
int a[1001];
signed main(){
	cin>>n>>tar;
	for(int i=1;i<=n;i++){
		int p,c;
		cin>>p>>c;
		for(int j=1000;j>=0;j--){
			for(int k=1;k<=j&&k<=p;k++){
				a[j]=max(a[j],a[j-k]+k*i*100+(k==p)*c);
			}
		}
	}
	for(int i=1;;i++){
		if(a[i]>=tar){
			return cout<<i,0;
		}
	}
}
