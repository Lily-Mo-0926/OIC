#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],id[1000005];
int main(){
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}a[0]=1e9*9;
	for(int i=1;i<=n;i++){
		int t=i,v=a[i];
		while(v>a[t-1])t=id[t-1];
		id[i]=t;
		if(t>1)t--;
		while(v>a[t-1])t=id[t-1];
		printf("%d\n",t);
	}
	return 0;
}
