#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
pair<int,int> a[200006]; 

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
	}
	sort(a+1,a+1+n);
	int ans=0;
	multiset<int>ms;
	for(int i=n;i>=1;i--){
		ms.insert(a[i].second);
		if(ms.size()==k){
			ans=max(ans,a[i].first* *ms.begin());//利用默认小根堆的性质 
			ms.erase(ms.begin());
		}
	}cout<<ans;
}

