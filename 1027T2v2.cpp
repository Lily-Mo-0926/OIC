#include<bits/stdc++.h>
using namespace std;
const int N=3e5+3;
int n;
int a[N],dp[N],t1,t2,s1[N],s2[N];
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
//	File("read");
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){
		while(t1&&a[s1[t1]]<=a[i])t1--;
//		for(int i=0;i<=t1;i++)cout<<s1[i]<<' ';cout<<endl;
		s1[++t1]=i;
		while(t2&&a[s2[t2]]>a[i])t2--;
//		for(int i=0;i<=t2;i++)cout<<s2[i]<<' ';cout<<endl;
		s2[++t2]=i;
//		cout<<"dp从哪儿来 "<<*lower_bound(s2+1,s2+t2+1,s1[t1-1])-1<<endl;
//		cout<<"在找什么 "<<s1[t1-1]<<endl;
		dp[i]=dp[*lower_bound(s2+1,s2+t2+1,s1[t1-1])-1]+1;
//		for(int i=0;i<=n;i++)cout<<dp[i]<<' ';cout<<endl;
	}
	cout<<dp[n];
}
