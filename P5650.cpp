#include<bits/stdc++.h>
using namespace std;
int a[100005],cnt,ans,f;
string s;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'){
			if(ans>0)ans--;
		}else {
			f=1;
			ans++;
			cnt=max(cnt,ans);
		}
	}
	if(!f){cout<<-1;return 0;}
	cout<<cnt;
} 
