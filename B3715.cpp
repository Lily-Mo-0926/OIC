#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int main(){
	cin>>T;
	while(T--){
		ll x;
		cin>>x;
		for(ll i=2;i*i<=x;i++){
			while(x%i==0){
				cout<<i<<' ';
				x/=i;
			}
		}if(x>1)cout<<x;
		cout<<"\n";
	}
}
