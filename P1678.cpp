#include<bits/stdc++.h>
using namespace std;
int m,n;
long long ans;
int a[100005];
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	sort(a+1,a+1+m);
	for(int i=1,b;i<=n;i++){
		cin>>b;
		int k=lower_bound(a+1,a+1+m,b)-a;
		if(k==m+1)ans+=1ll*b-a[m];
		else if(k==1)ans+=1ll*a[1]-b;
		else ans+=1ll*min(abs(b-a[k]),abs(b-a[k-1]));
	}
	cout<<ans;
}
