#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,m,op,x,y;
int l[500005],r[500005],s[500005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		l[i]=i-1;
		r[i]=i+1;
	}
	r[n]=0;
	r[0]=1;
	l[n+1]=n;
	while(m--){
		cin>>op>>x;
		if(op==1){
			cin>>y;
			if(x!=y){
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				r[x]=y;
				l[x]=l[y];
				r[l[y]]=x;
				l[y]=x;
			}
		}else if(op==2){
			cin>>y;
			if(x!=y){
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				l[x]=y;
				r[x]=r[y];
				l[r[y]]=x;
				r[y]=x;
			}
		}else{
			if(!s[x]){
				l[r[x]]=l[x];
				r[l[x]]=r[x];
				s[x]=1;
			}
		}
	}
	if(!r[0])cout<<"Empty!";
	else{
		op=r[0];
		while(op){
			cout<<op<<' ';
			op=r[op];
		}
	}
}
