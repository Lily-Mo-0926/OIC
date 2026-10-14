#include<bits/stdc++.h>
using namespace std;
int x,n,ans;
int a[15];
int main(){
	cin>>x>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(a[1]!=1){
		cout<<-1;
		return 0;
	}
	ans=x;
	for(int i=2,j=2;i<=x;i++){
		if(i==a[j]){
			ans-=1.0*x/i-0.5;
			if(j<n)j++;
			cout<<ans<<' '<<a[j]<<endl;
		}
	}
	cout<<ans<<endl; 
} 
