#include<bits/stdc++.h>
#define kd(); ios::sync_with_stdio(0);\
	cin.tie(0);\
	cout.tie(0);
#define int long long
using namespace std;
int n,a[300005];
int mx,mn=1e9;
multiset<int>st; 
signed main(){
	kd();
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n+n]=a[i+n]=a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mx<=mn*2){
		for(int i=1;i<=n;i++)cout<<-1<<' ';
		return 0;
	}
	for(int l=1,r=0;l<=n;l++){
		while(r<3*n&&(st.empty()||(a[r+1])*2>=(*st.rbegin()))){
			st.insert(a[++r]);
//			cout<<(*st.begin())<<' '<<(*st.rbegin())<<endl;
		}
//		cout<<l<<" : "<<r<<endl;
		cout<<r-l+1<<' ';
		st.erase(st.find(a[l]));/*
		cout<<endl;
		for(multiset<int>::iterator i=st.begin();i!=st.end();i++)
			cout<<(*i)<<' ';
		cout<<endl;*/
	}
}
