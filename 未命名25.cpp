#include<bits/stdc++.h>
using namespace std;
int n,t[200005],l[200005],r[200005],sl[200005],sr[200005];
int main(){
//    freopen("waterstar.in","r",stdin);
  //  freopen("waterstar.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&t[i]);
    for(int i=1;i<n;i++)scanf("%d%d",&l[i],&r[i]);
    sl[n]=0,sr[n]=1e9;
    for(int i=n-1;i;i--){
        if(sr[i+1]<l[i])sr[i]=-1;
        else sr[i]=min(sr[i+1],r[i]);
        if(sl[i+1]<=l[i])sl[i]=max(0,l[i]-t[i]);
        else sl[i]=sl[i+1];
    }
    for(int i=1;i<n;i++){
    	cout<<sl[i]<<' '<<sr[i]<<endl;
	}
    int pl=0,pr=1e9;
    for(int i=1;i<=n;i++){
        int g=max(pl,sl[i]);
        cout<<"G: "<<g<<endl;
        if(g>min(pr,sr[i]))puts("-1");
        else printf("%d\n",g);
        if(pr<l[i])pr=-1;
        else pr=min(pr,r[i]);
        if(pl<=l[i])pl=max(0,l[i]-t[i+1]);
    }
}
/*#include<bits/stdc++.h>
using namespace std;
int n,maxt;
int t[200005];
struct edge{
	int l,r;
}a[200005];
int f[20005][5001];
int solve(int x,int k){//k=timespot
	if(x+1<=n){
		if(k<=a[x].r&&k>=a[x].l){
			return f[x][k]=solve(x+1,k);
		}else if(k<a[x].l&&t[x]>=a[x].l-k){
			return f[x][k]=solve(x+1,a[x].l);
		}else{
			return f[x][k]=-1;
		}
	}if(x-1>0){
		if(k<=a[x-1].r&&k>=a[x-1].l){
			return f[x][k]=solve(x-1,k);
		}else if(k<a[x-1].l&&t[x-1]>=a[x-1].l-k){
			return f[x][k]=solve(x-1,a[x-1].l);
		}else{
			return f[x][k]=-1;
		}
	}
}
int findtim(int x){
	for(int i=0;i<=maxt;i++){
		if(solve(x,i)!=-1){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("waterstar.in","r",stdin);
	freopen("waterstar.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",t+i);
	}
	for(int i=1;i<n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
		maxt=max(maxt,a[i].r);
	}
	for(int i=1;i<=n;i++){
	//	for(int j=0;j<=1000;j++)
		printf("%d\n",findtim(i));
	}
}*/
