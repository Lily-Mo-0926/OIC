#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
unsigned long long a[1000005],x,as,msk,sum=1; 
void find(){
	for(int i=0;i<k;i++){
		if(msk&(1ull<<i)){
			sum*=2ull;
		}
	}
	sum-=n;
}
int main(){
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		as|=x;
	}
	msk=(1ull<<k)-1;
	if(k==64){
		msk=~0ull;
	} 
	for(int i=1,p,q;i<=m;i++){
		cin>>p>>q;
		if(!(as&(1ull<<p))){
			msk&=(~(1ull<<p));
		}
	}
	find();
	if(n==0&&sum==0){
		cout<<"18446744073709551616";
		return 0; 
	}
	cout<<sum;
}
