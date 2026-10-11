#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main(){
	while(cin>>n>>m){
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<=m;j++){
			char c;
			int u,v;
			cin>>c>>u>>v;
			if(c=='Q'){
				int mx=0;
				for(int i=u;i<=v;i++){
					mx=max(a[i],mx);
				}cout<<mx<<endl;
			}
			else{
				a[u]=v;
			}
		}
	}
	
}
