#include<bits/stdc++.h>
using namespace std;
int q,a,x;
list<int>dq[1000006];
int main(){
	cin>>q;
	while(q--){
		string s;
		cin>>s>>a;
		if(s=="push_back"){cin>>x;dq[a].push_back(x);}
		else if(s=="pop_back"){if(!dq[a].empty())dq[a].pop_back();}
		else if(s=="push_front"){cin>>x;dq[a].push_front(x);}
		else if(s=="pop_front"){if(!dq[a].empty())dq[a].pop_front();}
		else if(s=="size"){cout<<dq[a].size()<<"\n";}
		else if(s=="front"){if(!dq[a].empty())cout<<dq[a].front()<<"\n";}
		else{if(!dq[a].empty())cout<<dq[a].back()<<"\n";}
	}
}
