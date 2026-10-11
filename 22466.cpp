#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[200005],t[200005];
multiset<int>s1,s2;
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		cin>>t[i];
	}
	int cur=0,ans=0;
	for(int i=1,j=1;i<=n;i++){
		s1.insert(t[i]);
		cur+=(t[i]+1)>>1;
		if(s1.size()>m){
			int it=*s1.begin();
			s1.erase(s1.find(it));
			cur+=it-(it+1)/2;
			s2.insert(it);
		}
		while(cur>k){
			if(s1.size()&&t[j]>=*s1.begin()){
				cur-=(t[j]+1)/2;
				s1.erase(s1.find(t[j]));
				if(s2.size()){
					int it=*(--s2.end());
					s2.erase(s2.find(it));
					cur+=(it+1)/2-it;
					s1.insert(it);
				}
			}else{
				cur-=t[j];
				s2.erase(s2.find(t[j]));
			}
			j++;
		}
		ans=max(ans,(a[i]-a[j-1]));
	}
	cout<<ans;
	return 0;
}
