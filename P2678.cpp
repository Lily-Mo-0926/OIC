#include<bits/stdc++.h>
using namespace std;
int a,n,m;
int rk[50005];
bool chk(int x){
	int cnt=0,now=0;
	for(int i=1;i<=n+1;i++){
		cout<<now<<' ';
		if(rk[i]-rk[now]<x){
			cnt++;
		}
		else{
			now=i;
		}
	}cout<<endl;
	return cnt<=m;
}
int main(){
	cin>>a>>n>>m;
	for(int i=1;i<=n;i++){cin>>rk[i];}
	rk[n+1]=a;
	int l=0,r=a+1;
	while(l<r){
		int mid=l+r>>1;
		//cout<<l<<' '<<mid<<' '<<r<<endl;
		if(chk(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	if(!chk(l))cout<<l-1<<endl;
	else cout<<l<<endl;
}
