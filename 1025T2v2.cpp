#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100005],s[100005];
map<int,int>mp; 
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("super");
	scanf("%lld %lld",&n,&k);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		mp[a[i]]++;
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+(mp[a[i]]>=2);
	}
	for(int i=1;i<=n;i++){
		int p=upper_bound(a+1,a+n+1,a[i]*1ll*k)-a-1;
		if(mp[a[i]]>=3){ans++;}
		if(mp[a[i]]>=2){ans+=(p-i)*3;}
		ans+=(s[p]-s[i])*3+(p-i)*(p-i-1)/2*6;
	}
	printf("%lld",ans);
} 
