#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,v,u,a[100005];
ll me;
int main(){
	cin>>n>>m>>v;
	me=1ll*(n-1)*(n-2)/2;
	if(m>me+1||m<n-1){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
	if(v!=1)u=1;
	else u=2;
//	cout<<v<<' '<<u;
//	a[u]=0;
	for(int i=1;i<=n;i++){
		if(i!=v){
			cout<<v<<' '<<i<<"\n";
		}
	}
	a[v]=a[u]=0;
	m=m-n+1;
	for(int i=1;i<=n&&m;i++){
		if(a[i]){
			for(int j=1;j<=n&&m;j++){
				if(i!=j&&a[j]!=0){
					cout<<i<<' '<<j<<'\n';
					m--;
				}
			}a[i]=0; 
		}
	} 
}
