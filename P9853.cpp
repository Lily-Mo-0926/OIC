#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n,q;
const int INF=5e9+18;
int sol[200005];
void du(int j){
	string s;
	cin>>s;
	ll a=0,b=0,c=0;
	int cnt=0,f=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='-'){
			f=-1;
			continue;
		}
		if(s[i]=='x'||s[i]=='='){
			if(cnt==0)a*=f;
			else if(cnt==1)b*=f;
			cnt++;
			f=1;
			continue;
		}
		if(cnt==0){
			if(s[i]>='0'&&s[i]<='9'){
				a=a*10+s[i]-'0';
			}
		}
		else if(cnt==1){
			if(s[i]>='0'&&s[i]<='9'){
				b=b*10+s[i]-'0';
			}
		}
		else{
			if(s[i]>='0'&&s[i]<='9'){
				c=c*10+s[i]-'0';
			}
		}
	}
	c*=f; 
	sol[j]=(c-b)/a;
};
signed main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		/*int a,b,c;
		scanf("%dx%d=%d",a,b,c);
		sol[i]=(c-b)/a;*/
		du(i);
	}
	sort(sol+1,sol+1+n);
	for(int i=1;i<n;i++){
		if(sol[i]==sol[i+1]){
			sol[i]=INF;
		}
	}
	sort(sol+1,sol+1+n);
	while(q--){
		int l,r;
		cin>>l>>r;
		int a=lower_bound(sol+1,sol+1+soln,l)-sol-1,
		b=upper_bound(sol+1,sol+1+soln,r)-sol-1;
		cout<<b-a<<endl;
	} 
}
