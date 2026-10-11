#include<bits/stdc++.h>
using namespace std;
int n,m;
char g[200][200];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(g[i][j]=='?'){
				g[i][j]='0'+(g[i-1][j-1]=='*')
						   +(g[i-1][j]=='*')
						   +(g[i-1][j+1]=='*')
						   +(g[i][j-1]=='*')
						   +(g[i][j+1]=='*')
						   +(g[i+1][j-1]=='*')
						   +(g[i+1][j]=='*')
						   +(g[i+1][j+1]=='*');
			}
			cout<<g[i][j];
		}cout<<'\n';
	}
}
