#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id,sc; 
}a[5005];
bool cmp(node x,node y){
	if(x.sc==y.sc) return x.id<y.id;
	return x.sc>y.sc;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].sc;
	}
	m=floor(1.0*m*1.5);
	sort(a+1,a+1+n,cmp);
	cout<<a[m].sc<<' ';
	while(a[m].sc==a[m+1].sc)m++;
	cout<<m<<'\n';
	for(int i=1;i<=m;i++){
		cout<<a[i].id<<' '<<a[i].sc<<endl;
	}
}
