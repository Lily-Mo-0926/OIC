#include<bits/stdc++.h>
using namespace std;
int n;
int a[102],sum;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(sum%2)cout<<"Alice";
	else cout<<"Bob";
} 
