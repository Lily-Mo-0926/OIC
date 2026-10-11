#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int n,m;
int ans=0,mn=1e9;
char s[N][N];
int a[N][N],sr[N],sc[N];void File(string s){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}
int main(){
   File("room");
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=(s[i][j]==s[i%n+1][j]&&
					 s[i][j]==s[i][j%m+1]&&
					 s[i][j]==s[i%n+1][j%m+1]);//以(i,j)为顶点的2*2方块是否来自同一栋楼 
//			cout<<a[i][j]<<' ';
			sr[i]+=a[i][j];//在横排方向压缩成和的形式 
			sc[j]+=a[i][j];//在竖排方向压缩 
			ans+=a[i][j];
		}//cout<<endl;
	}
//	for(int i=1;i<=n;i++)cout<<sr[i]<<' ';cout<<endl;
//	for(int i=1;i<=m;i++)cout<<sc[i]<<' ';cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			mn=min(mn,sr[i]+sc[j]-a[i][j]);//把重复统计的部分（a[i][j]）减掉?? 
//			cout<<sr[i]+sc[j]-a[i][j]<<' ';
		}//cout<<endl;
	}//cout<<endl;
	printf("%d",ans-mn);
} 
