#include<bits/stdc++.h>
using namespace std;
int n,m,a[13][13],ans=-1e9;
bool v1[4100],v2[4100];
void dfs(const vector<int>&v,bool *vis){
	for(int g:v){vis[g]=1;}
	for(int i=1;i<v.size();i++){
		vector<int>g;
		for(int j=0;j<i||i+j<v.size();j++){
			g.push_back((j<i)*v[i-j-1]|(i+j<v.size())*v[i+j]);
		}
		dfs(g,vis);
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	vector<int>o;
	for(int i=0;i<n;i++){o.push_back(1<<i);}
	dfs(o,v1);
	o.clear();
	for(int i=0;i<m;i++){o.push_back(1<<i);}
	dfs(o,v2);
	for(int i=0;i<(1<<n);i++){
		if(v1[i]){
			for(int j=0;j<(1<<m);j++){
				if(v2[j]){
					int res=0;
					for(int k=0;k<n;k++){
						if(i>>k&1){
							for(int l=0;l<m;l++){
								res+=(j>>l&1)*a[k][l];
							}
						}
					}
					ans=max(ans,res);
				}
			}
		}
	}
	cout<<ans;
}
