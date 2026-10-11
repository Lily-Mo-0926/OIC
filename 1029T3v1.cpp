#include<bits/stdc++.h>
//WA+TLE
//离正解的反悔贪心最近的一次
//我错了我再也不认为自己写不出正解了orzzzzz 
using namespace std;
const int N=1e7+7;
char s[N];
int sf[N],sb[N];
stack<int> st;
void File(string c){
    freopen((c+".in").c_str(),"r",stdin);
    freopen((c+".out").c_str(),"w",stdout);
}
signed main(){
    File("league");
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>s+1;
//    cout<<s+1<<endl;
    for(int i=1;i<=strlen(s+1);i++){
    //	cout<<"range "<<i<<endl;
    	if(s[i]=='('){
    		st.push(s[i]);
		}else if(s[i]==')'){
			if(!st.empty())st.pop();
		}
    	else{
    		if(!st.empty()){
    		//	cout<<"fill "<<st.size()<<endl; 
    			s[i]=')';
    			st.pop();
			}else{
    	//		cout<<"fill -1"<<endl;
				s[i]='(';
			}
		}
	}
	while(!st.empty()){
//		cout<<"pop "<<st.size()<<endl;
		st.pop();
	}
    for(int i=1;i<=strlen(s+1);i++){
    //	cout<<"range "<<i<<endl;
    	if(s[i]==')'){
    		st.push(s[i]);
		}else if(s[i]=='('){
			if(!st.empty())st.pop();
		}
    	else{
    		if(!st.empty()){
    			s[i]='(';
    			st.pop();
			}
		}
	}
	cout<<s+1;
}
