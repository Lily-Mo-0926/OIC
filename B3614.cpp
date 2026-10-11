/*#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
//ll st[(int)1e6+6];
stack<ll>st;
int T,n;//,top;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		while(n--){
			string s;
			cin>>s;
			if(s=="query"){
				if(st.empty())cout<<"Anguei!\n";
				else cout<<st.top()<<"\n";
			}else if(s=="pop"){
				if(st.empty())cout<<"Empty\n";
				else st.pop();
			}else if(s=="push"){
				ll x;
				cin>>x;
				st.push(x);
			}else{
				cout<<st.size()<<"\n";
			}
		}
	}
} */
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll T,n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
        stack<ll>st;//多组数据记得清空 
		while(n--){
			string s;
			cin>>s;
			if(s=="query"){
				if(st.empty())cout<<"Anguei!\n";
				else cout<<st.top()<<"\n";
			}else if(s=="pop"){
				if(st.empty())cout<<"Empty\n";
				else st.pop();
			}else if(s=="push"){
				ll x;
				cin>>x;
				st.push(x);
			}else{
				cout<<st.size()<<"\n";
			}
		}
	}
}
/*int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		top=0;
		cin>>n;
		string q;
		while(n--){
			cin>>q;
			if(q=="query"){
				//cout<<(top==0?:st[top]);
				if(top==0){
					cout<<"Anguei!\n";
				}else{
					cout<<st[top]<<"\n";
				}
			}else if(q=="pop"){
				//top!=0?top--:cout<<"Empty\n";
				if(top==0){
					cout<<"Empty\n";
				}else{
					top--;
				}
			}else if(q=="push"){
				int x;
				cin>>x;
				st[++top]=x;
			}else{
				cout<<top<<"\n";
			}
		}
	}
}写炸了*/
