#include<bits/stdc++.h>
using namespace std;
vector<int> pf(const string &s){
	int n=s.size();
	vector<int>pi(n,0);
	for(int i=1;i<n;i++){
		int j=pi[i-1];
		while(j>0&&s[i]!=s[j])
			j=pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i]=j;
	}
	return pi;
}
int main(){
	freopen("compress.in","r",stdin);
	freopen("compress.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	string ans;
	ans.reserve(1000000);
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int m=s.size();
		string text;
		if(ans.size()>=m)
			text=ans.substr(ans.size()-m);
		else
			text=ans;
		vector<int>pi=pf(s);
		int q=0;
		for(char ch:text){
			while(q>0&&s[q]!=ch)
				q=pi[q-1];
			if(s[q]==ch)
				q++;
		}
		ans.append(s.substr(q));
	}
	cout<<ans<<'\n';
}
