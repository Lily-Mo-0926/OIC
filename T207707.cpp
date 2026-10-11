#include<bits/stdc++.h>
using namespace std;
//char c;
string s;
int a[26],mx,mn=1e9;
int pm[105]={0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0};
int main(){
	cin>>s; 
/*	while(c){
		a[c-'a']++;
		cin>>c;
	}*/
	for(int i=0;i<s.size();i++){
		a[s[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		mx=max(mx,a[i]);
		if(a[i]!=0)mn=min(mn,a[i]);
	}
	cout<<mx<<' '<<mn<<endl; 
/*	for(int i=1;i<105;i++){
		cout<<i<<' '<<pm[i]<<endl;
	}*/
	mx-=mn;
	if(pm[mx]){
		cout<<"Lucky Word\n"<<mx;
	}else{
		cout<<"No Answer\n0";
	}
}
