#include<bits/stdc++.h>
#define mod 1000000007
#define maxn 200005
#define ls ((now<<1))
#define rs ((now<<1)|1)
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
int n,m;
pair<int,int> a[maxn];
int cmp(pair<int,int> x,pair<int,int> y)
{
	if (x.second!=y.second) return x.second<y.second;
	return x.first>y.first;
}
basic_string<int> E[maxn];
int mx[maxn];
int fa[maxn][20];
void dfs(int x,int F)
{
	fa[x][0]=F; for (int i=1;i<=19;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int y:E[x]) dfs(y,x);
	return;
}
int main()
{
	//freopen("movie.in", "r", stdin);
	//freopen("movie.out", "w", stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i].first>>a[i].second;
	sort(a+1,a+n+1,cmp);
	a[n].first=1e7; a[n].second=1e7;
	for (int i=1;i<=n;i++) mx[i]=max(mx[i-1],a[i].first);
	int j = 0;
	for (int i=1;i<=n;i++)
	{
		j=max( j,i+1);
		while (a[ j].first<a[i].second && j<=n) j++;
		E[ j]+=i;
	}
	dfs(n+1,n+1);
	 for (int i=1;i<=n+1;i++) cout<<fa[i][0]<<" ";cout<<endl;
	int L,R;
	while (m--)
	{
		cin>>L>>R;
		int now=0;
		for (int step=1<<20;step>=1;step=step>>1)
			if (now+step<=n+1 && mx[now+step]<L) //看不了
				now+=step;
		now++;
		//这是第一个可以看的电影
		if (a[now].first<L || a[now].second>R) {cout<<0<<endl; continue;}
		int ff=1;
		for (int step=19;step>=0;step--)
			if (fa[now][step]!=n+1)
			{
				int tt=fa[now][step];
				if (a[tt].second<=R) //能看
					cout<<"/ "<<a[tt].second<<endl,
					now=tt,ff+=(1<<step),
					cout<<": "<<(1<<step)<<endl;
			}
		cout<<ff<<endl;
	}
}
