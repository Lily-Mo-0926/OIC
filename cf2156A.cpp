#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int cnt=0;
		while(n>=3){
			cnt+=n/3;
			n=n/3+n%3;
		}
		cout<<cnt<<'\n';
	}
}
