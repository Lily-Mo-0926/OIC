#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int fa[N];
int n,m;
int fin(int x){return fa[x]==x?x:fa[x]=fin(fa[x]);}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){fa[i]=i;}
	while(m--){
		int x,y,z;
		cin>>z>>x>>y;
		if(z==1){
			x=fin(x);
			y=fin(y);//加上这两句的目的是防止 只修改单点x而非合并xy所在两棵树
			//只有加上这两句x和y才同级 
			if(x!=y)fa[x]=y;
		}else{
			x=fin(x);
			y=fin(y);//防止上次合并完没更新 
			cout<<(x==y?"Y":"N")<<"\n";
		}
	}
} 
//P3545
