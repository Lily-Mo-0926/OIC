#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
char s[N];
int st[N],top;
int cnt;
void File(string c){
    freopen((c+".in").c_str(),"r",stdin);
    freopen((c+".out").c_str(),"w",stdout);
}
signed main(){
    File("league");
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s+1;
    int n=strlen(s+1);//strlen作为for循环条件句的组成部分时会随循环被调用多次，可能导致TLE 
    for(int i=1;i<=n;i++){
    	if(s[i]=='('){
    		cnt++;
		}else if(s[i]==')'){
			if(cnt)cnt--;
			else if(top){
				s[st[top--]]='(';
				cnt++;
			}
		}
    	else{
    		if(cnt){
				cnt--; 
    			s[i]=')';
    			st[++top]=i;
			}else{
				cnt++;
				s[i]='(';
			}
		}
	}//我今天T3做的最不对的一点就是误以为自己写不出正解
	cout<<s+1;
}
