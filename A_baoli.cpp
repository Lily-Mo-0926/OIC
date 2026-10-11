#include<bits/stdc++.h>
using namespace std;
int n,m; 
long long sum,base;
int a[100005],t[100005];
long long w(int x){
	return 1ll*x*(n-x); 
} 
int main(){
	freopen("awesomeness.in","r",stdin);
	freopen("awesomeness.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	base=1ll*n*(n+1)/2;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			sum+=w(i-1);
		}
	}
	for(int j=1,i,x;j<=m;j++){
		cin>>i>>x;
		
		if(i>1&&a[i]!=a[i-1]){
			sum-=w(i-1);
		}
		if(i<n&&a[i]!=a[i+1]){
			sum-=w(i);
		}
		a[i]=x;
		if(i>1&&a[i]!=a[i-1]){
			sum+=w(i-1);
		}
		if(i<n&&a[i]!=a[i+1]){
			sum+=w(i);
		}
		cout<<base+sum<<endl; 
	} 
}
