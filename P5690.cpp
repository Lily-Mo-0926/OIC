#include<bits/stdc++.h>
using namespace std;
int mm,dd,ans;
int s[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sol(int d,int m){
	if(d<=s[m]){
		return 0;
	}else return 1;
}
int main(){
	scanf("%d-%d",&mm,&dd);
	if(mm>12){
		ans++;
		mm%=10;
		if(mm==0)mm=10;
		if(mm==2)mm=12;
	}
	ans+=sol(dd,mm);
	cout<<ans;
}
