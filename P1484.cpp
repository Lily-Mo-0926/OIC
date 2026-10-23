#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[300006],ans;
set<pair<int,int>>st;
int prv[300006],nxt[300005]; 
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		prv[i]=i-1;
		nxt[i]=i+1;
		st.insert({a[i],i});
	}
	nxt[0]=1;prv[n+1]=n;
	while(!st.empty()&&(*prev(st.end())).first>0&&k){
		auto it=prev(st.end());
		int val=(*it).first,id=(*it).second;
		st.erase(it);
		ans+=val;
		k--;
		//cout<<k<<' '<<ans<<endl;
		st.insert({a[id]=a[nxt[id]]+a[prv[id]]-a[id],id});
		if(prv[id]!=0){
			st.erase(st.find({a[prv[id]],prv[id]}));
			nxt[prv[prv[id]]]=id;
			prv[id]=prv[prv[id]];
		}
		if(nxt[id]!=n+1){
			st.erase(st.find({a[nxt[id]],nxt[id]}));
			prv[nxt[nxt[id]]]=id;
			nxt[id]=nxt[nxt[id]];
		}
	}
	cout<<ans;
} 
