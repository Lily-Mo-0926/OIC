#include<bits/stdc++.h>
using namespace std;
int a,T;
void solve(int n){
	vector<vector<int> >adj(n+1);
	for(int i=0,x,y;i<n-1;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<int>sz(n+1,0),fa(n+1,0);
	vector<int>odr;
	odr.reserve(n);
	stack<int>st;
	st.push(1);
	fa[1]=0;
	while(!st.empty()){
		int u=st.top();
		st.pop();
		odr.push_back(u);
		for(int v:adj[u]){
			if(v==fa[u])continue;
			fa[v]=u;
			st.push(v);
		}
	}
	for(int i=n-1;i>-1;i--){
		int u=odr[i];
		sz[u]=1;
		for(int v:adj[u]){
			if(v!=fa[u])sz[u]+=sz[v];
		}
	}
	vector<int>ctr;
	int bst=n+1;
	for(int u=1;u<=n;u++){
		int mx=n-sz[u];
		for(int v:adj[u]){
			if(v!=fa[u])mx=max(mx,sz[v]);
		}
		if(mx<=bst){
			if(mx<bst)
				ctr.clear();
			bst=mx;
			ctr.push_back(u);
		}
	}
	if(ctr.size()==1){
		int a=1,b=adj[1][0];
		cout<<a<<" "<<b<<"\n";
		cout<<a<<" "<<b<<"\n";
		return;
	}
	int c1=ctr[0],c2=ctr[1];
	int lf=-1,plf=-1;
	stack<pair<int,int> >st2;
	st2.push({c1,0});
	while(!st2.empty()){
		int u=st2.top().first,p=st2.top().second;
		st2.pop();
		if(u!=c1&&(int)adj[u].size()==1){
			lf=u;
			plf=p;
			break;
		}for(int v:adj[u]){
			if(v!=p&&v!=c2)st2.push({v,u});
		}
	}
	if(lf==-1){
		for(int v:adj[c1]){
			if(v!=c2){
				lf=v;
				plf=c1;
				break;
			}
		}
	}
	cout<<lf<<' '<<plf<<'\n';
	cout<<lf<<' '<<c2<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>a;
		solve(a);
	}
}
