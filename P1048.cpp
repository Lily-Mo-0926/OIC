#include<bits/stdc++.h>
using namespace std;
int f[1001];
int T,M;
int c[101],v[101];
int main(){
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++){
		scanf("%d %d",c+i,v+i);
	}
	for(int i=1;i<=M;i++){//test
		cout<<c[i]<<' '<<v[i]<<endl;
	}
	for(int i=1;i<=M;i++){
		for(int j=c[i];j<=T;j++){
			f[j]=max(f[j],f[j-c[i]]+v[i]);
		}
	}
	cout<<f[T];
}
