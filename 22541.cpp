#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
	int len;
	int c[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};
}l,r;
ll low,high;
node makeUp(ll x){
	node num;
	num.len=0;
	num.c[num.len++]=x%10;
	x/=10;
	while(x){
		num.c[num.len++]=x%10;
		x/=10;
	}
	return num;
}//0--len-1
int main(){
	cin>>low>>high;
	l=makeUp(low);
	r=makeUp(high);
	if(l.len==r.len){
		int cnt=0;
		for(int i=r.len-1;i>=0;i--){
			if(r.c[i]==l.c[i]){
				cnt+=(l.c[i]==8);
				continue;
			}else if(r.c[i]>l.c[i]){
				break;
			}
		}
		cout<<cnt;return 0;
	}else{cout<<0;return 0;}
}
