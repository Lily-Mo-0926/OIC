#include<bits/stdc++.h>
using namespace std;
int n,m;
map<int,bool> mp;
/*
struct node{
	int id,nxt;
}a[100006];*/
int nxt[100005],pre[100005];
void add(int x,int k,int p){
	mp[x]=1;
	if(p){//add to right: j k x l
		pre[x]=k;
		nxt[x]=nxt[k];
		pre[nxt[k]]=x;
		nxt[k]=x;
	}
	else{//left		 	: j x k l 
		nxt[x]=k;
		pre[x]=pre[k];
		nxt[pre[k]]=x;
		pre[k]=x;
	}
}
int main(){
	cin>>n;
	nxt[0]=1,nxt[1]=n+1;
	pre[1]=0;
	mp[1]=1;
	for(int i=2,k,p;i<=n;i++){
		cin>>k>>p;
		add(i,k,p); 
	}
	cin>>m;
	for(int i=1,x;i<=m;i++){
		cin>>x;
		if(mp[x]){
			mp[x]=0;
			//nxt[pre[x]]=nxt[x];
		}
	}
	for(int i=nxt[0];i<n+1;i=nxt[i]){
		if(mp[i]) 
			cout<<i<<' ';
	}
}
