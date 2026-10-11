#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005],c[200005];
multiset<int>st; 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		st.insert(b);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			auto pos=st.find((j-a[i]+n)%n);
			if(pos!=st.end()){
				st.erase(pos);
				cout<<j<<' ';
				break;
			} 
		}
	}
} 
