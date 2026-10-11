#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int x[100005];
int q[100005],head=1,tail=0; 
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("super");
	scanf("%d %d",&n,&k);
	if(k==1){
		map<int,int>mp;
		map<pair<int,int>,bool>vis;
		for(int i=1,z;i<=n;i++){
			scanf("%d",&z);
			mp[z]++;
		}
		int cnt=0;
		 
		for(auto u:mp){
			if(u.second>2){cnt+=1;}
			
		}
		printf("%d\n",cnt);
	}
	else {//condition needs to change
		map<int,int>mp;
		map<pair<int,int>,bool>vis;
		for(int i=1,z;i<=n;i++){
			scanf("%d",&z);
			mp[z]++;
		}
		int cnt=0;
		 
		for(auto u:mp){
			if(u.second>2){cnt+=1;}
			q[++tail]=u.first;
			while(q[head]*k<u.first){head++;}
			if(tail-head>1){
				cnt+=(tail-head+1)*(tail-head)*(tail-head-1);//the tri is different
			}
			//this block can be better, with
			for(int i=head;i<tail;i++){
				int v=mp[q[i]];
				if(v>1){
					cnt+=3;
				}
				if(u.second>1){
					cnt+=3;
				}
			}
		}
		printf("%d\n",cnt);
	}
}
