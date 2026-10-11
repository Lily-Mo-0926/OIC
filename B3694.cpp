#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[100001],r[100001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			r[i]=a[i];
		}sort(a+1,a+1+n);
		m=unique(a+1,a+1+n)-(a+1);
		for(int i=1;i<=n;i++){
			cout<<(lower_bound(a+1,a+1+m,r[i])-a)<<' ';
		}cout<<"\n";
	}
}
