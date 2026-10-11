#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n%3) cout<<n-(n-(n%3))/3;
	else cout<<n-(n-(n%3))/3+1;
}
