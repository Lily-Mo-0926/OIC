#include<bits/stdc++.h>
using namespace std;
int n;
int p[205];
//int r[205][205];
int main(){
	cin>>n;
	for(int i=2;i<=n;i++){
		cin>>p[i];
	}
	for(int i=2;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int x;cin>>x;//x=p[i][j]
			p[j]=min(p[j],p[i]+x);
		}
	}
	cout<<p[n];
	/*
	memset(r,0x3f,sizeof r);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			cin>>r[i][j];
			r[j][i]=r[i][j];
		}
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<r[i][j]<<' ';cout<<endl;}
	for(int k=1;k<=n;k++){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				r[i][j]=min(r[i][k]+r[k][j],r[i][j]);
			}
		}
	}
	//cout<<endl;	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<r[i][j]<<' ';cout<<endl;}
	cout<<r[1][n]<<endl;*/
}
