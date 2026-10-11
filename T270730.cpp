#include<bits/stdc++.h>
using namespace std;
int T,n,l,r;
unsigned long long x,st[1000006];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		l=1;r=0;
		while(n--){
			string s;
			cin>>s;
		//	cout<<s<<endl;
			if(s=="query"){
				if(l>r){
					cout<<"Anguei!\n";
				}else{
					cout<<st[r]<<"\n";
				}
			}else if(s=="size"){
				cout<<r-l+1<<"\n";
			}else if(s=="pop"){
					if(l>r){
						cout<<"Empty\n";
					}else{
						r--;
					}
			}else{
				cin>>x;
				st[++r]=x;
			}
		} 
	}
}
