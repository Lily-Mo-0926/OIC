#include<bits/stdc++.h>
using namespace std;
#define int long long
//im going to write something that going to be bufenfen
int n,k;
pair<int,int> a[200006]; 
int dfs(int stp,int u,int v,int l,int x){//暴搜，如果加剪枝目标50pts 
	if(u*v<x){return -1;}
	if(stp>=k){return u*v;}//???
	int cnt=-1;
	for(int i=l;i<=n;i++){
		cnt=max(cnt,dfs(stp+1,min(u,a[i].first),min(v,a[i].second),i+1,x));
	}return cnt;
}//O(nk)
//int dp[200006][200006]; 
bool check(int x){//kaolvgai int
	return dfs(0,1e9,1e9,1,x)>=x;
}
void File(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
    File("lichang");//i think it can be 'field'.
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	int x,y;
    	cin>>x>>y;
    	a[i]={x,y};
	}/*
	if(k==2){
		
	}*/
    int l=0,r=1e18;
    while(l<r){
        int mid=(l+r+1)>>1;
        int x=dfs(0,1e9,1e9,1,mid);
        if(x>=mid){
            l=x;
        }else{r=mid-1;}
    }
    cout<<l;
}

