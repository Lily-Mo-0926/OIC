#include<bits/stdc++.h>
using namespace std;
int n,a[300005];
long long sum=0;
double mx;
bool cmp(int x,int y){
	return x>y; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		mx=max(1.0*sum/i*sum,mx);
	}
	printf("%.8lf",mx); 
}
