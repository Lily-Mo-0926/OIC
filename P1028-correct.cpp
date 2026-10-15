#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[1000006],d[1000006],k[1000006];
struct node{
	int w,l,r;
}s[1000006];
bool check(int x){
	for(int i=0;i<=n;i++){k[i]=0;}
	for(int i=1;i<=x;i++){
		k[s[i].l]+=s[i].w;
		k[s[i].r+1]-=s[i].w;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=k[i];
		if(sum>a[i]){
			return 0;
		}
	}
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	//	s[i]=a[i]+a[i-1];
	}
	int c=1,e=m,mid=c+e>>1;
	for(int j=1;j<=m;j++){
		cin>>s[j].w>>s[j].l>>s[j].r;
	}
	while(c<e){
		mid=c+e>>1; 
		if(check(mid)){
			c=mid+1;
		}
		else{
			e=mid;
		}
	}
	if(c!=m){cout<<-1<<"\n"<<c;return 0;}
	/*for(int j=1,w,l,r;j<=m;j++){
		cin>>s[j].w>>s[j].l>>s[j].r;
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
		if(d[l]+d[l-1]<0||){
			cout<<-1<<"\n"<<i;
			return 0;
		}
		for(int i=1;i<=n;i++){
			a[i]=d[i]+d[i-1];
			cout<<a[i]<<' ';
		}
	}*/
	cout<<0;
}
