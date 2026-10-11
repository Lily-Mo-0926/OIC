#include<bits/stdc++.h>
using namespace std;
int cnt;
string s;
int main(){
//	freopen("vowel.in","r",stdin);
//	freopen("vowel.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'
		 ||c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
		 cnt++;
	}cout<<cnt;
} 
