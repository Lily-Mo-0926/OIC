#include<bits/stdc++.h>
using namespace std;
long long n,c,s;
int main(){
	cin>>n;
	c=(n+1)*n+2*n;
	for(long long i=1;i<=n;i++){
		s+=i*i;
	}
	cout<<c<<endl<<s;
}
