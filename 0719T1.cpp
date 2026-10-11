#include <bits/stdc++.h>
using namespace std;
int n,k,T,cnt,cal,sum[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		string s;
		cin>>n>>k;
		//sum[n+1]=0;
		memset(sum,0,sizeof sum);
		cin>>s;
		for(int i=n;i>0;i--){
			if(s[i-1]=='0')sum[i]=sum[i+1]-1;
			else sum[i]=sum[i+1]+1;
		}
		sort(sum+2,sum+1+n,cmp);
		cal=cnt=0;
		for(int i=2;i<=n;i++){
			cal+=sum[i];
			cnt++;
			if(cal>=k){
				cout<<cnt+1<<"\n";
			//	cout<<cal<<endl;
				break;
			}
		}
		if(cal<k){
			cout<<"-1\n";
		}
	}
}
