#include<bits/stdc++.h>
using namespace std;
const int N=1e5*3+3;
int n;
int a[N];
int g[N],h[N],vis[N];
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
//	File("read");
	ios::sync_with_stdio(0);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[i]=h[i]=a[i];
		if(i>1&&a[i]==a[i-1]){
			vis[i-1]=1;
			ans--;
		}//this can be thrown away
	}
	for(int k=0;(1<<k)<=n;k++){//我最好再好好算算迭代多少遍 
		for(int i=1;i<n;i++){
			if(!vis[i]&&g[i]<=g[i+1]&&h[i]<=h[i+1]){
				g[i+1]=g[i];
				h[i]=h[i+1];
				vis[i]=1;
				ans--;
			}
		}
	}
	cout<<ans;
}//为什么不对呢 
