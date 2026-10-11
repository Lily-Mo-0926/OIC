#include<bits/stdc++.h>
using namespace std;
int n;
int pz[35],lu[8];
int main(){
	cin>>n;
	for(int i=1,x;i<8;i++){
		cin>>x;
		pz[x]++;
	}
	while(n--){
		int cnt=0;
		for(int i=1,x;i<8;i++){
			cin>>x;
			cnt+=pz[x];
		}
		lu[cnt]++;
	}
	for(int i=7;i>0;i--){
		cout<<lu[i]<<' ';
	}
}
