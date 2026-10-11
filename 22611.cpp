#include<bits/stdc++.h>
using namespace std;
int n,f[51];
priority_queue<int>s[51];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=n;i>0;i--){
		int mx=0,j=1;
		while(!s[i].empty()){
			mx=max(mx,j+s[i].top());
			j++;
			s[i].pop();
		}
		if(~f[i])
			s[f[i]+1].push(mx);
		else
			printf("%d",mx);
	}
}
