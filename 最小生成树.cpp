#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> q[10005], v[10005];
long long dis[10005]; 
bool s[10005]; 
long long ans = 0; 
void prim(){
	memset(dis, 0x3f, sizeof(dis)); 	
	memset(s, 0, sizeof(s));	
	s[1] = 1;
	dis[1] = 0; 
	for(int i = 0; i < q[1].size(); i++){
		dis[q[1][i]] = min(dis[q[1][i]], (long long)v[1][i]); 
		}
	for(int i = 1; i <= n-1; i++){ 
    	long long minn = 0x3f3f3f3f3f3f3f3f, x = 0;
		for(int j = 1; j <= n; j++)
      		if(s[j] == 0 && dis[j] < minn)
       			minn = dis[j], x = j; 
       	if(x==0){
       		cout<<"orz";
       		exit(0);
		} 
    	ans += dis[x]; 
		s[x] = 1;
    	dis[x] = 0; 
    	for(int j = 0; j < q[x].size(); j++){
			dis[q[x][j]] = min(dis[q[x][j]], (long long)v[x][j]); 
		
		}
  	}
}


signed main(){
	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin>>x>>y>>z;
		q[x].push_back(y);
		v[x].push_back(z);
		q[y].push_back(x);
		v[y].push_back(z);
	}
	prim();
	cout<<ans;
	return 0;
}
