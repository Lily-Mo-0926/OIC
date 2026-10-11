#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
int n,a[N],b[N],ans;
int main(){
	cin>>n;
	ans=n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1,c=1;c<=n;i++,c++){
		cin>>b[c];
		if(a[i]==b[c])ans++,i--;
	}
	cout<<ans;
}
