/*#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
map<pair<int,int>,int>mp;
queue<pair<int,int> >q; 
int dis[2][4]={0,1 ,0,-1 ,1,0 ,-1,0};
int bfs(pair<int,int> z){
	int cnt=0;
	q.push(z);
	mp[z]=2;
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(mp[{u.first+dis[0][i],u.second+dis[1][i]}]==1){
				cnt++;
				q.push({u.first+dis[0][i],u.second+dis[1][i]});
				mp[{u.first+dis[0][i],u.second+dis[1][i]}]=2;
			}
		}
	}
	cout<<z.first<<' '<<z.second<<":\n	cnt:"<<cnt<<endl;
	return cnt;
}
signed main(){
	cin>>n>>k;
	for(int i=1,x,y;i<=k;i++){
		cin>>x>>y;
		mp[{x,y}]=1;
	}
	for(auto u:mp){
		if(u.second==1){
			ans+=bfs(u.first);
		}
	}
	cout<<ans;
}*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
map<pair<int,int>,int>mp;
int dis[2][4]={0,1 ,0,-1 ,1,0 ,-1,0};

signed main(){
	cin>>n>>k;
	for(int i=1,x,y;i<=k;i++){
		cin>>x>>y;
		mp[{x,y}]=1;
		for(int i=0;i<4;i++){
			ans+=mp[{x+dis[0][i],y+dis[1][i]}];
		}
	}
	cout<<ans;
} 
