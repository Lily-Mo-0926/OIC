#include<bits/stdc++.h>
using namespace std;
int n,L;
int l[1005],w[1005];
int mx,ans=-1;
//bitset<10005>f[10005]; 
int f[3][9005]; 
int main(){
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	cin>>n>>L;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>w[i];
		//f[(l+1)>>1]=w[i];
	}
	for(int i=1;i<=L;i++){
		for(int k=0;k<3;k++){
			f[k][i]=-1e9;
		}
	}
	for(int i=1;i<=n;i++){
		int half=(l[i]+1)>>1;
//		f[L]=max(f[L],f[L-((l[i]+1)>>1)]+w[i]);
		for(int j=L;j>=l[i];j--){
			f[j]=max(f[j],f[j-l[i]]+w[i]);
		}
/*		for(int j=l[i]-1;j>=((l[i]+1)>>1);j--){
			if(((l[i]+1)>>1)>=j){
				f[j]=max
			}
		}*/
//		f[(l[i]+1)>>1]=max(f[(l[i]+1)>>1],w[i]);
	}
	
	for(int i=1;i<=L;i++){
		ans=max(ans,f[2][i]);
	}
	cout<<ans;
}
