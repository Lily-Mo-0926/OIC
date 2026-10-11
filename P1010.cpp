#include<bits/stdc++.h>
using namespace std;
int a;
void dvd(int x){
	bool flag=0;
	while(x!=0){
		int t=int(log2(x));
		if(flag)cout<<'+';
		if(t==1)cout<<2;
		else if(t==0)cout<<"2(0)";
		else{
			cout<<"2(";
			dvd(t);
			cout<<")";
		}
		x-=pow(2,t);
		flag=1;
	}
}
int main(){
	cin>>a;
	dvd(a);
	return 0;
}
