#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000006],d[1000006],s[1000006];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	//	s[i]=a[i]+a[i-1];
	}
	for(int j=1,w,l,r;j<=m;j++){
		cin>>w>>l>>r;
		d[l]-=w;
		d[r+1]+=w;
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+d[i];
			//cout<<s[i]<<' ';
			if(s[i]<0){
				cout<<-1<<'\n'<<j;
				return 0;
			}
		}//cout<<endl;
		/*if(d[l]+d[l-1]<0||){
			cout<<-1<<"\n"<<i;
			return 0;
		}
		for(int i=1;i<=n;i++){
			a[i]=d[i]+d[i-1];
			cout<<a[i]<<' ';
		}*/
	}
	cout<<0;
}
