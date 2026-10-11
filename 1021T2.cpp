#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7,M=1e6+7;
int a[N],b[N],dl[N],dr[N],l[M],r[M];
bool vis[M];
int n,m,ans=0,sum=0;void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("memory");
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		a[i]+=m*2;
	}
	a[0]=a[n],b[0]=b[n];
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])continue;
		if(b[i-1]<b[i]){
			for(int j=b[i-1];j<b[i];j++){
				++dr[(a[i]%m+m-j%m)%m];
				sum+=(a[i]-j%m+m-1)/m;
				r[j]=a[i];
				vis[j]=1;
			}
		}else{
			for(int j=b[i];j<b[i-1];j++){
				++dl[(a[i]%m+m-j%m)%m];
				sum-=(a[i]-j%m)/m;
				l[j]=a[i];
			}
		}
	}
	for(int i=0,pl=m-1,pr=0,s=0;i<m;i++){
		s+=dr[pr]-dl[pl];
		ans=min(ans,s);
		pl=(pl+m-1)%m;
		pr=(pr+m-1)%m;
	}cout<<ans+sum;
}
