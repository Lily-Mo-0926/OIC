#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,l,r;
int a[N],b[N];
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort.out","w",stdout);
	cin>>n>>l>>r;
	for(int i=0;i<n;i++){cin>>a[i];}
	for(int i=0;i<n;i++){cin>>b[i];}
	sort(a,a+n);sort(b,b+n);
	int m=r-l+1; 
	for(int i=l/n;i<=r/n;i++){
		if(i==l/n)
			for(int j=l%n-1;m&&j<n;j++){
				m--;
				cout<<1ll*a[i]+b[j]<<' ';
			}
		for(int j=1;m&&j<n;j++){
			m--;
			cout<<1ll*a[i]+b[j]<<' ';
		}
	}
} 
