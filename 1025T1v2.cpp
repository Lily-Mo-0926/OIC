#include<bits/stdc++.h>
using namespace std;
const int dx[2][4]={{0,1,0,-1},{0,1,0,-1}},
		  dy[2][4]={{1,0,-1,0},{-1,0,1,0}};
int n,m,K;
int a[60][60];void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int main() {
	File("line");
	scanf("%d%d%d",&n,&m,&K);
	memset(a,0x3f3f,sizeof a);
	while(K--){
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		a[x][y]=1;
		for(int i=1,c=2;i<=max(n,m);i++){
			--x,
			x-=dx[t][0],
			y-=dy[t][0];
			for(int j=0;j<4;j++){
				for(int k=1;k<=i*2;k++,++c){
					x+=dx[t][j],y+=dy[t][j];/*
					for(int g=1;g<=n;g++){
						for(int h=1;h<=m;h++){
							printf("%d ",a[g][h]);
						}puts(" ");
					}
					cout<<x<<' '<<y<<endl;*/
					if(1<=x and x<=n and 1<=y and y<=m)a[x][y]=min(a[x][y],c);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
}
