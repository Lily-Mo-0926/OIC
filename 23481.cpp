#include<bits/stdc++.h>
using namespace std;
int n,k;
struct rect{
	int w,h;
}a[1000006];
bool cmp(rect x,rect y){
	return x.h==y.h?x.w<y.w:x.h<y.h;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i].w>>a[i].h;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){cout<<a[i].h<<' '<<a[i].w<<endl;}
	for(int i=k;i<=n;i++);
}
