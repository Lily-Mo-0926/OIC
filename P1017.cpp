#include<bits/stdc++.h>
using namespace std;
char nam[20]={'0','1','2','3','4','5','6','7','8','9',
			  'A','B','C','D','E','F','G','H','I','J'};
int r,n,con;
void solve(int x){
	int yu=x%r;
	x/=r;
	if(yu<0){
		yu-=r;
		x+=1;
	}
	if(x==0){
		cout<<nam[yu];
		return;
	}
	solve(x);
	cout<<nam[yu];
}
signed main(){
	cin>>n>>r;
	cout<<n<<"=";
	solve(n);
	cout<<"(base"<<r<<")";
}
