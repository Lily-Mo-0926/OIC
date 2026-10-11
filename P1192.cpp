#include<bits/stdc++.h>
using namespace std;
int n,k;
const int mod=100003;
int f[1000003];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	f[1]=f[0]=1;
	for(int i=n;i>1;i--){
		for(int j=k;j>0;j--){
			if(i>=j){
				f[i]=(f[i-j]+f[i])%mod;
			}
		}
	}
	cout<<f[n]<<endl;
}
