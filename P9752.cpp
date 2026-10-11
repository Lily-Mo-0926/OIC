#include<bits/stdc++.h>
#define forin(i,a,b) for(int i=(a);i<=(b);i++) 
using namespace std;
map<int,int>mp;
int n,ans;
long long x[10][10][10][10][10];
int main(){
	cin>>n;
	forin(i,1,n){
		int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		forin(j,0,9)x[j][b][c][d][e]++;
		forin(j,0,9)x[a][j][c][d][e]++;
		forin(j,0,9)x[a][b][j][d][e]++;
		forin(j,0,9)x[a][b][c][j][e]++;
		forin(j,0,9)x[a][b][c][d][j]++;
		
		forin(j,0,9)x[(a+j)%10][(b+j)%10][c][d][e]++;
		forin(j,0,9)x[a][(b+j)%10][(c+j)%10][d][e]++;
		forin(j,0,9)x[a][b][(c+j)%10][(d+j)%10][e]++;
		forin(j,0,9)x[a][b][c][(d+j)%10][(e+j)%10]++;
	}
	forin(k1,0,9)
	forin(k2,0,9)
	forin(k3,0,9)
	forin(k4,0,9)
	forin(k5,0,9){
		if(x[k1][k2][k3][k4][k5]==n)ans++;
	}
	cout<<ans;
}
