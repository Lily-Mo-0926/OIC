#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int,vector<int>,greater<int>>pq;
int n;
int ans;
signed main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		pq.push(x);
	}
	while(pq.size()>1){
		int t1=pq.top();
		pq.pop();
		int t2=pq.top();
		pq.pop();
		ans+=t1+t2;
		pq.push(t1+t2);
	}
	cout<<ans;
} 
