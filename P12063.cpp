#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[2];
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		a[i%2]+=x;
		if(a[i%2]>m){
			return cout<<(i%2==0?"Black":"White"),0;
		}
	}cout<<"Draw";
}
