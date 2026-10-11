#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,op,x;
int main(){
	cin>>n;
	multiset<int>s;
	while(n--){
		cin>>op;
		if(op==1){
			cin>>x;
			s.insert(x);
		}else if(op==2){
			cout<<*s.begin()<<endl;
		}else{
			s.erase(s.begin()); 
		}
	} 
} 
