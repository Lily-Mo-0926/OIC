#include<bits/stdc++.h>
using namespace std;
int n,num,l,r,ans;
long long cnt;
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		b[i]=x;
		s[i]=(x==i)?s[i-1]+1:s[i-1];
		a[i].x=min(x,i);
		a[i].z=i+x;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++) num=l=r=ans=0;
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
	for(int i=1;i<=n;i++){
		if(i<l||i>r){
			cnt+=1ll*(b[i]==i)*i*i;
		}else{
			cnt+=1ll*(b[r+l-i]==i)*i*i;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
