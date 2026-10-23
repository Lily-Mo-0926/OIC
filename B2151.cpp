#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
pair<int,int> a[105];
bool check(pair<int,int> x){
	if(x.first>=90&&x.first<=140
	&&x.second<=90&&x.second>=60)
		return 1;
	return 0;
}
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>a[i].first>>a[i].second;
		x=check(a[i]);
		cnt=cnt*x+x;
		ans=max(ans,cnt);
	}
	cout<<ans;
}
