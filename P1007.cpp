#include<bits/stdc++.h>
using namespace std;
int len,n,a[5005],b[5005],ans1,ans2;
int main(){
	cin>>len>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;/*
		a[i]=min(x,len+1-x);
		b[i]=max(x,len+1-x);*/
		ans1=max(min(x,len+1-x),ans1);
		ans2=max(max(x,len+1-x),ans2);
	}
	cout<<ans1<<' '<<ans2<<endl;
} 
