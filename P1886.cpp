#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[1000006],f[1000006],d[1000006];
pair<int,int> q1[1000006],q2[1000006];
int h1=1,t1,h2=1,t2;
//priority_queue
//queue<pair<int,int>>q1,q2;
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//while(!q1.empty()&&q1.front().second<i-k+1)
		while(h1<=t1&&q1[h1].second<i-k+1){
			//q1.pop();
			h1++;
		}
		while(h2<=t2&&q2[h2].second<i-k+1){
			//q2.pop();
			h2++;
		}
		//while(!q1.empty()&&a[i]<q1.front().first)
		while(h1<=t1&&q1[t1].first>a[i]){
			t1--;
		}//q1.push({a[i],i});
		q1[++t1]={a[i],i};
		if(i-k>=0){f[i-k+1]=q1[h1].first;}
		while(h2<=t2&&q2[t2].first<a[i]){
			t2--;
		}q2[++t2]={a[i],i};
		if(i-k>=0){d[i-k+1]=q2[h2].first;}
	}
	for(int i=1;i<=n-k+1;i++){
		cout<<f[i]<<' ';
	}cout<<endl;
	for(int i=1;i<=n-k+1;i++){
		cout<<d[i]<<' ';
	}cout<<endl;
}
