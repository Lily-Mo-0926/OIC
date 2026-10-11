#include<bits/stdc++.h>
using namespace std;
int T,n,q;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>q;
		string s;
		cin>>s;
		char c=s[0];
		for(int i=1;i<n;i++){
			if(s[i]!=c){c='c';break;}
		}
		int a;
		if(c=='A'){
			while(q--){
				cin>>a;
				cout<<a<<'\n';
			}
			continue;
		}else if(c=='B'){
			while(q--){
				cin>>a;
				for(int i=1;;i++){
					if((a>>i)<=0){
						cout<<i<<'\n';
						break;
					}
				}
			}
			continue;
		}
		while(q--){
			int time=0;
			cin>>a;
			while(a){
				if(s[(time)%n]=='A'){a-=1;}
				if(s[(time)%n]=='B'){a=a>>1;}
				time++;
			}cout<<time<<'\n';
		}
	}
}
