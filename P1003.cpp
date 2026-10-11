#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y;
struct node{
	int lx,ly,rx,ry;
}a[10004];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].lx>>a[i].ly>>a[i].rx>>a[i].ry;
		a[i].rx+=a[i].lx,a[i].ry+=a[i].ly;
	}cin>>x>>y;
	for(int i=n;i>0;i--){
		if(a[i].lx<=x&&a[i].rx>=x&&a[i].ly<=y&&a[i].ry>=y){return cout<<i,0;}
	}cout<<-1;
}
