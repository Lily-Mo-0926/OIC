#include<bits/stdc++.h>
using namespace std;
int n,sum,f=1,cnt=0;
char c; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int k=1;k<=n;k++){
		f=1,cnt=0;
		c=getchar_unlocked();
		while(c<'0'||c>'9'){
			if(c=='-')f=-1;
			c=getchar_unlocked();
		}
		while(c>='0'&&c<='9'){
			cnt=cnt*10+c-'0';
			c=getchar_unlocked(); 
		}
		sum+=f*cnt;
	}
	cout<<sum; 
}
