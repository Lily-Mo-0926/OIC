#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
const int N=1e5+1;
int T,n,a[N][4],maxv,ans;
vector<int>members[4];
void solve(){
	for(int i=1;i<=3;i++){
		members[i].clear();
	}
	ans=0;
	cin>>n;
	for(int i=1,x,y;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			x=1;
			y=(a[i][2]>a[i][3]?2:3);
		}
		else if(a[i][1]<=a[i][2]&&a[i][2]>=a[i][3]){
			x=2;
			y=(a[i][1]>a[i][3]?1:3);
		}else{
			x=3;
			y=(a[i][1]>a[i][2]?1:2);
		}
		members[x].push_back(a[i][x]-a[i][y]);
		ans+=a[i][x];
	}
	if((maxv=
	max({members[1].size(),members[2].size(),members[3].size()}))
	<=n/2){
		cout<<ans<<'\n';
		return;
	}
	int x,rem;
	if(members[1].size()==maxv)x=1;
	else if(members[2].size()==maxv)x=2;
	else x=3;
	rem=members[x].size()-(n>>1);
	sort(ALL(members[x]));
	for(int i=0;i<rem;i++){
		ans-=members[x][i];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		solve();
	}
}
