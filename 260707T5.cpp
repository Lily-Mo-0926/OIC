#include<bits/stdc++.h>
#define kd(); ios::sync_with_stdio(0);\
	cin.tie(0);\
	cout.tie(0);
using namespace std;
int n,q;
int a[300005],d[300005];
int l[300005],r[300005];
int ded[300005];
int main(){
	kd();
	cin>>q;
	set<int>si,js; 
	while(q--){
		js.clear();
		si.clear();
		cin>>n;
		l[n+1]=n;
		r[0]=1;
		for(int i=1;i<=n;i++)cin>>a[i],l[i]=i-1,ded[i]=0;
		for(int i=1;i<=n;i++)cin>>d[i],r[i]=i+1,js.insert(i);
		a[n+1]=0; 
		for(int i=1;i<=n;i++){
			si.clear();
			for(int u:js){
				if(!ded[u]&&d[u]<a[r[u]]+a[l[u]]){
					si.insert(u);
					ded[u]=1;
				}
			}
			js.clear();
			for(int v:si){
				if(l[v]>0){
					js.insert(l[v]);
				}
				if(r[v]<=n){
					js.insert(r[v]);
				}
				l[r[v]]=l[v];
				r[l[v]]=r[v];
			}
			cout<<si.size()<<' ';
		}
		cout<<'\n';
	}
}
