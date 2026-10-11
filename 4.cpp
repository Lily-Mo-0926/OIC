#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int read()
{
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		ret=(ret<<1)+(ret<<3)+ch-'0',
		ch=getchar();
	return ret;
}

int n,num,l,r,ans;
const int N=1e6+5;
int s[N],b[N];
struct NA{
	int x,z;
}a[N];

bool cmp(NA i,NA j)
{
	return i.z<j.z||i.z==j.z&&i.x>j.x;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		b[i]=x;
		s[i]=(x==i)?s[i-1]+1:s[i-1];
		a[i].x=min(x,i);
		a[i].z=i+x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	num=l=r=ans=0;
	for(int i=1;i<=n;i++)
		if(i==1||a[i].z==a[i-1].z)
		{
			num++; 
			int t=num+s[a[i].x-1]+s[n]-s[a[i].z-a[i].x];
			if(ans<t)
				ans=t,l=a[i].x,r=a[i].z-a[i].x;
		} else 
		{
			num=1;
			int t=num+s[a[i].x-1]+s[n]-s[a[i].z-a[i].x];
			if(ans<t)
				ans=t,l=a[i].x,r=a[i].z-a[i].x;
		}
	printf("%d %d\n",b[l],b[r]);
	return 0;
}
