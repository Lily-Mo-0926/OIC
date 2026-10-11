#include<bits/stdc++.h>
using namespace std;
int n;
int t[200005],l[200005],r[200005];
int sl[200005],sr[200005];
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int main(){
//	File("waterstar");
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",t+i);}
	for(int i=1;i<n;i++){scanf("%d%d",l+i,r+i);}
	sl[0]=0;sr[n]=1e9;
	for(int i=n-1;i>0;i--){
		if(sr[i+1]<l[i]){sr[i]=-1;}//its impossible to go right
		else{sr[i]=min(sr[i+1],r[i]);}//the upperbound is the minimum of nextbound and nowbound
		if(sl[i+1]<=l[i])sl[i]=max(0,l[i]-t[i]);
		else sl[i]=sl[i+1];
	}
	int pl=0,pr=1e9;
	for(int i=1;i<=n;i++){
		int g=max(pl,sl[i]);
		if(g>min(pr,sr[i]))puts("-1");
		else printf("%d\n",g);
		if(pr<l[i])pr=-1;
		else pr=min(r[i],pr);
		if(pl<=l[i])pl=max(0,l[i]-t[i+1]);
	}
}
