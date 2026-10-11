#include<bits/stdc++.h>
using namespace std;
int w,b;
double f[1010][1010];
int main(){
	cin>>w>>b;
	for(int i=1;i<=w;i++)f[i][0]=1;
	for(int i=0;i<=b;i++)f[0][i]=0;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=b;j++){
			f[i][j]+=(double)i/(i+j);
			if(i>=1&&j>=2)
				f[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*f[i-1][j-2];
			if(j>=3)
				f[i][j]+=(double)j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*f[i][j-3];
		}
	}
	printf("%.9lf",f[w][b]);
}
