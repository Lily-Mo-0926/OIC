#include<bits/stdc++.h>
using namespace std;
int n,t;
double ans;
struct node{
	int m,v;
	double ra;
}a[200];
bool cmp(node x,node y){
	return x.ra>y.ra;
}
int main(){
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].v;
		a[i].ra=1.0*a[i].v/a[i].m;
	}
	sort(a+1,a+1+n,cmp);
//	cout<<endl;
	for(int i=1;i<=n;i++){
	//	cout<<a[i].ra<<' '<<a[i].m<<' '<<a[i].v<<'\n';
		if(t>=a[i].m){
			ans+=a[i].v;
			t-=a[i].m;
		}else if(t>0){
			ans+=a[i].ra*t;
			t=0;
		}
		else{
			break;
		}
	}
	printf("%.2f",ans);
}
