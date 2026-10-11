#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[1005][1005];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		for(int j=x1;j<=x2;j++){
			s[j][y1]++;
			s[j][y2+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]+=s[i][j-1];
			cout<<s[i][j]<<' ';
		}
		cout<<endl;
	}
}
