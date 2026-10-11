#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ans+=1ll*i*(i+1)*3/2;
	}
	cout<<ans;
}
