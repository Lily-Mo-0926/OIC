#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node{
	int d,c;
}a[100005];
int main(){
//	freopen("fountain.in","r",stdin);
//	freopen("fountain.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].d>>a[i].c;
	}
	while(q--){
		int r,v,i;
		cin>>r>>v;
		v-=a[r].c;
		for(i=r;i<n+2;i++){
			while(a[i].d<=a[r].d&&i<n+2){i++;}
			if(v<=0){break;}
			v-=a[i].c;
			//cout<<i<<' ';
			r=i;
		}
/*		while(v>=0&&r<n+2){
			v-=a[r].c;
			cout<<r<<' ';
			if(v<=0){break;}
			r++;
			while(a[r].d<=a[r-1].d&&r<n+2){r++;}
		}*/
		//cout<<endl;
		cout<<(i<=n?i:0)<<endl;
	}
}
