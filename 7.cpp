#include<bits/stdc++.h>
using namespace std;
int main(){
	int x=2023,ans=0;
	while(x!=0){
		x-=x&-x;
		cout<<x<<endl;
		ans++;
	}cout<<ans;
}
