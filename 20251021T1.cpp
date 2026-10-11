#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n;
int a[N],b[N],c[N];
int pb,pc,bb,bc;
ll sum,mxb=-2e18,mxc=-2e18,res=-2e18;
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int main(){
//	File("film");
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		sum+=a[i];
		if(b[i]-a[i]+mxc>res)res=b[i]-a[i]+mxc,pb=i,pc=bc;
		if(c[i]-a[i]+mxb>res)res=c[i]-a[i]+mxb,pc=i,pb=bb;
		if(b[i]-a[i]>mxb)mxb=b[i]-a[i],bb=i;
		if(c[i]-a[i]>mxc)mxc=c[i]-a[i],bc=i;
	}
	cout<<res+sum<<'\n'<<pb<<' '<<pc;
}
