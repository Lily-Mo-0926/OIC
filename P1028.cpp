#include<bits/stdc++.h>
using namespace std;
int n,f[1006];
int dfs(int x){
	if(f[x]){
		return f[x];
	}
	if(x==1||x==0){
		return f[x]=1;
	}
	for(int i=x/2;i>=0;i--){
		f[x]+=dfs(i);
	}
	//cout<<ans<<endl; 
	return f[x];
	 
}
int main(){
	cin>>n;
	/*f[1]=1;
	for(int i=1;i<=n;i++){
		
	} */
	cout<<dfs(n);
} 
