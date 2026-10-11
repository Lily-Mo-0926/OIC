#include<bits/stdc++.h>
using namespace std;
#define d(A,B,C,D) ((A-C)*(A-C)+(B-D)*(B-D))
struct h{
	int x,y;
}a[1000005];
bool c(h a,h b){return a.y>b.y;}
int x,y,x1,x2,y1,y2,n,M,ans=1e9;
int main(){
	cin>>x1>>y1>>x2>>y2>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,a[i].x=d(x1,y1,x,y),a[i].y=d(x2,y2,x,y);
	sort(a+1,a+1+n,c);
	for(int i=0;i<=n;i++)M=max(M,a[i].x),ans=min(M+a[i+1].y,ans);
	cout<<ans; 
}
