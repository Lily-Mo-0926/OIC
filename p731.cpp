#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,P=1e9+7;
int n,p[N],ans,f[N],jc[N],iv[N],inv[N];
int C(int n,int m)
{
	return n<m? 0:1LL*jc[n]*iv[m]%P*iv[n-m]%P;
}
int main()
{
	freopen("cirperm.in","r",stdin);
	freopen("cirperm.out","w",stdout);
	iv[0]=jc[0]=1;
	for(int i=1;i<N;i++)
	{
		jc[i]=1LL*jc[i-1]*i%P;
		inv[i]=i==1? 1:1LL*(P-P/i)*inv[P%i]%P;
		iv[i]=1LL*iv[i-1]*inv[i]%P;
	}
	scanf("%d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=(1LL*f[i-1]*i+(i&1? -1:1))%P;
	for(int i=2;i<=n;i++)
		for(int j=1,s=C(n,i)*1LL*jc[i-1]%P;s;s=1LL*s*C(n-i*j,i)%P*inv[j+1]%P*jc[i-1]%P,j++)
			(ans+=(j&1? 1LL:P-1LL)*s%P*f[n-i*j]%P)%=P;
	printf("%d",ans);
}
