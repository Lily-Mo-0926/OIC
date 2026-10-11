#include<bits/stdc++.h>
using namespace std;
int back[10000006];
int q;
int main(){
	cin>>q;
	while(q--){
		int z,y,x;
		cin>>z>>x;
		if(z==1){
			cin>>y;
			back[y]=back[x];
			back[x]=y;
		}else if(z==2){
			cout<<back[x]<<endl;
		}else{
			back[x]=back[back[x]];
		}
	}
} 
