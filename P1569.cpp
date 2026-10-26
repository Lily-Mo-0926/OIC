#include<bits/stdc++.h>
using namespace std;
int n,s[1003],f[1003],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		s[i]+=s[i-1];
	}if(s[n]<0){
		cout<<"Impossible";
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i]=-1e9;//为什么加上这个就多得10pts从而ak 
		for(int j=i-1;j>=0;j--){
			if(s[i]-s[j]>=0){
				f[i]=max(f[i],f[j]+1);
			}
		}
	}
	cout<<f[n];
} 
