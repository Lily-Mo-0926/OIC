#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],n=0; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>a[++n]);
    n--;
    vector<int>f1;
	for(int i=1;i<=n;i++){
		int pos=upper_bound(f1.begin(),f1.end(),a[i],greater<int>())-f1.begin();
		if(pos==f1.size())f1.push_back(a[i]);
		else f1[pos]=a[i];
	}
	vector<int>f2;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(f2.begin(),f2.end(),a[i])-f2.begin();
		if(pos==f2.size())f2.push_back(a[i]);
		else f2[pos]=a[i];
	}
	cout<<f1.size();
	cout<<"\n"<<f2.size();
}
