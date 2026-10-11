#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,l,x,y;
long long rs;
struct P{
	int w,s;//w守卫者权重，s攻击者人数 
	bool operator < (const P&t)const{return w>t.w;}//通过权重由大到小贪心 
}a[N<<1];
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("defend");
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		rs+=x;
		a[++l]=(P){y,x/y};//权重y，需要x/y个守卫者
		a[++l]=(P){x%y,1};//权重x%y，需要1个守卫者 
		//这里分成两条是因为如果有攻击者余数事实上的守卫者权重会减小，于是把一个墙拆成两个。 
	}
	sort(a+1,a+l+1);//排完序开贪 
//	cout<<rs<<endl;
//	for(int i=1;i<=l;i++)cout<<a[i].w<<' '<<a[i].s<<endl;cout<<endl;
	for(int i=1;i<=l;i++){
		if(a[i].s>=m){//咋搞都不可能完全挡住了
		//这个if在全程序中只跑一次 
			rs-=1ll*m*a[i].w;
//			cout<<rs<<endl;
			break;//放弃。
		}else{//正常计算 
			rs-=1ll*a[i].s*a[i].w;
			m-=a[i].s;
		}
	}
	cout<<rs;
}
