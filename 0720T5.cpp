#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,k,n,d[200005],tim,cnt;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		priority_queue<int>ds;
		cnt=0;
		for(int i=1;i<=n;i++){
			cin>>d[i];
		}
		for(int i=1;i<=n;i++){
			ds.push(d[i]);
			if((n-i+1)%(k+1)==0){
				cnt+=ds.top();
				ds.pop();
			}
		} 
		cout<<cnt<<"\n";
	}
}
