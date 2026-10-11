#include<bits/stdc++.h>
using namespace std;
struct node{
	int a=0,b=0,c=0;
}obj[55];
int T,n;
int dp[100005];//100005枚举美味指数???
bool cmp(node x,node y){
	return 1ll*x.c*y.b<1ll*x.b*y.c; 
}
int main(){
	 cin>>T>>n;
	for(int i=1;i<=n;i++){cin>>obj[i].a;}
	for(int i=1;i<=n;i++){cin>>obj[i].b;}
	for(int i=1;i<=n;i++){cin>>obj[i].c;}
	sort(obj+1,obj+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=T;j>=obj[i].c;j--){
			//if(j>=obj[i].c){
				dp[j]=max(dp[j], dp[j-obj[i].c]+obj[i].a-j*obj[i].b);
			//}
		}
	}
	int ans=0;
	for(int i=0;i<=T;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}
/*#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[55],b[55],c[55];
int dp[55][100005];
int main(){
	cin>>T>>n;
	for(int i=1;i<=n;i++){cin>>a[i];}
	for(int i=1;i<=n;i++){cin>>b[i];}
	for(int i=1;i<=n;i++){cin>>c[i];}
	for(int i=1;i<=n;i++){
		for(int j=T;j>=c[i];j--){
			if(j>=c[i]){
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-c[i]]+a[i]-j*b[i]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=T;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}*/
