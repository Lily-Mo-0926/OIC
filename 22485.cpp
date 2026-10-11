#include<bits/stdc++.h>
using namespace std;
using ld=long double;
int n,L,R,q[200005][2],al,ar;
ld s[200005],a[200005];
bool check(ld mid){
	for(int i=1;i<=n;i++){
		a[i]-=mid;
		s[i]=s[i-1]+a[i];
	}
	int l[2]={1,1},r[2]={0,0};
	bool flag=0;
	for(int i=L+(L&1);i<=n;i++){
		while(l[i&1]<=r[i&1] && s[q[r[i&1]][i&1]]>=s[i-L-(L&1)]){
			r[i&1]--;
		}
		q[++r[i&1]][i&1]=i-L-(L&1);
		if(l[i&1]<=r[i&1] && q[l[i-1]][i&1]==i-R-2+(R&1)){
			l[i&1]++;
		}
		if(s[i]>=s[q[l[i&1]][i&1]]){
			al=q[l[i&1]][i&1]+1;
			ar=i;
			flag=1;
			break;
		}
	}
	for(int i=1;i<=n;i++)a[i]+=mid;
	return flag;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);
	for(int i=1;i<=n;i++)scanf("%Lf",&a[i]),a[i+n]=a[i];
	n*=2;
	ld l=0,r=1e9;
	for(int t=0;t<60;t++){
		ld mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	check(l);
	long long sum=0,g;
	for(int i=al;i<=ar;i++){
		sum+=a[i];
	}
	g=__gcd(sum,ar-al+1ll);
	printf("%lld/%lld",sum/g,(ar-al+1)/g);
}
