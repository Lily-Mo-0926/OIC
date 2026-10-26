#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[500006];
bool vis[500006];
bool check(int x){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++){
		if(a[i]<=x){
			vis[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		if(vis[i]&&abs(a[i]-a[i+1])<=x){
			vis[i+1]=1;
		}
	}
	for(int i=n;i>1;i--){
		if(vis[i]&&abs(a[i]-a[i-1])<=x){
			vis[i-1]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){return 0;}
	}
	return 1;
}
int main(){
	
	cin>>T;
	while(T--){
		cin>>n;
		int l=0,r=1,mid;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			r=max(r,a[i]);
		}
		while(l<r){
			mid=(l+r)>>1;
			if(check(mid)){
				r=mid;
			}
			else l=mid+1;
		}
		cout<<l<<endl; 
	}
}
