#include <iostream>
using namespace std;
int n,i,j,a[100][100];
int solve(int x,int y)
{
	int u,v;
	if(x==n) return a[x][y];
	u=solve(x+1,y);
	v=solve(x+1,y+1);
	if(u>v) return a[x][y]+u;
	else return a[x][y]+v;	
}
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++) cin>>a[i][j];
	cout<<solve(1,1)<<endl;
	return 0;	
}
