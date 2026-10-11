#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt,n,anst=0x7fffffff,f[1005],ans[1005],h[2005];
bool v[1005];
struct edge{int n,t;}e[2005];  //前向星 
void add(int x,int y) {
	e[++cnt].t=y;
	e[cnt].n=h[x];
	h[x]=cnt;
}
void dp(int x) {
	int d[1005]={0},y;
	v[x]=1;  //标记x已访问 
	for(int i=h[x];i;i=e[i].n) {
		y=e[i].t;
		if(!v[y]) {
			dp(y);  //计算子结点 
			d[++d[0]]=f[y];
		}
	}
	sort(d+1,d+d[0]+1);  
	//将x的子结点的传播时间从小到大排序 
	for(int i=1;i<=d[0];i++)f[x]=max(f[x],d[i]+d[0]-i+1);
} 
int main() {
	cin>>n;
	for(int i=2;i<=n;i++) {
		int x;
		cin>>x;
		add(i,x);
		add(x,i);
	}
	for(int i=1;i<=n;i++) {
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));  //每次枚举初始化 
		dp(i);
		if(anst>f[i]) {
			anst=f[i];
			ans[0]=0;
			ans[++ans[0]]=i;  
		}else if(anst==f[i])ans[++ans[0]]=i;  
		//更新最快传播时间并记录根结点 
	}
	cout<<anst+1<<endl;  //答案要加1 
	for(int i=1;i<=ans[0];i++)cout<<ans[i]<<" ";
	return 0;
}
