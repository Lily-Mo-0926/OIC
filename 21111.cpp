#include<bits/stdc++.h>
using namespace std;
struct v{
    int a,b,max;
}t[800040];
int people[200010];
void BuildTree(int x,int y,int num){
    t[num].a=x;
    t[num].b=y;
    if(x==y){t[num].max=people[x];}
    else{
        int Lson=num<<1,Rson=Lson|1;
        BuildTree(x,(x+y)>>1,Lson);
        BuildTree(((x+y)>>1)+1,y,Rson);
        t[num].max=max(t[Lson].max,t[Rson].max);
    }
}
int Query(int L,int R,int num){
    if(L==t[num].a&&R==t[num].b){return t[num].max;}
    if(R<=t[num<<1].b){
        return Query(L,R,num<<1);
    }
    if(L>=t[num<<1|1].a){
        return Query(L,R,num<<1|1);
    }
    int mid=(t[num].a+t[num].b)>>1;
    return max(Query(L,mid,num<<1),Query(mid+1,R,num<<1|1));
}
void Update(int i,int j,int num){
    if(t[num].a==t[num].b){
		t[num].max=j;
		return;
	}
    if(i<=t[num<<1].b){Update(i,j,num<<1);}
    else{Update(i,j,num<<1|1);}
	t[num].max=max(t[num<<1].max,t[num<<1|1].max);
}
int T;
int main(){
//	cin>>T;
//	while(T--){
	memset(t,0,sizeof t);
	memset(people,0,sizeof people);
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&people[i]);
	BuildTree(1,n,1);
	while(m--){
		char c;
		int u,v;
		scanf("%c %d %d",&c,&u,&v);
		if(c=='Q'){
			printf("%d\n",Query(u,v,1));
		}else{
			Update(u,v,1);
		}
	}
//	}
}
