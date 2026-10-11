#include<bits/stdc++.h>
using namespace std;
char c;
int a[105],mx,mn=1e9;
int main(){
	for(int i=1;i<105;i++){
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				a[i]=0;
				break;
			}
			a[i]=1;
		}
	}
	for(int i=1;i<105;i++){
		cout<<a[i]<<',';
	}
	mx-=mn;
}
