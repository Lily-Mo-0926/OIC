#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005,mod=998244353;
int randseed, n, m, Q;
int x[maxn], y[maxn], t[maxn], u[maxn], v[maxn], id[maxn];
basic_string<int> ask[maxn];
int now[maxn],pos[maxn],ans[maxn];
unsigned int rnd() {
    unsigned int r;
    r = randseed = randseed * 1103515245 + 12345;
    return (r << 16) | ((r >> 16) & 0xFFFF);
}

void init() {
	cin>>n>>m>>Q>>randseed;
	for(int i = 1; i <= m; i++) {
        x[i] = rnd() % n + 1; 
        y[i] = rnd() % n + 1;
    }
    for(int i = 1; i <= Q; i++) {
        t[i] = rnd() % m + 1; 
        u[i] = rnd() % n + 1; 
        v[i] = rnd() % n + 1; 
    	id[i] = rnd() % n + 1;
    	ask[t[i]]+=i;
    	
    }
}

long long yuchuli(){
	for(int i=1;i<=n;i++){
		now[i]=i,pos[i]=i;
	}
	int a,b;
	for(int i=1;i<=m;i++){
		for(int j:ask[i]){
			a=u[j],b=v[j];
			swap(now[a],now[b]);
			pos[now[a]]=a,pos[now[b]]=b;
			
			ans[j]=pos[id[j]];
			
			swap(now[a],now[b]);
			pos[now[a]]=a,pos[now[b]]=b;
			
//			cout<<j<<' ';
		}
		swap(now[x[i]],now[y[i]]);
		pos[now[x[i]]]=x[i],pos[now[y[i]]]=y[i];
//		cout<<endl;
	}
	for(int i=1;i<=n;i++){
		now[i]=i,pos[i]=i;
	}
	for(int i=m;i>0;i--){
		for(int j:ask[i]){
			int tt=ans[j];
			ans[j]=now[tt];
		}
		swap(now[x[i]],now[y[i]]);
	}
	long long res=0;
	for(int i=1;i<=Q;i++){
		res=(res+1ll*i*ans[i])%mod;
	}return res;
}
int main(){
	freopen("seats.in","r",stdin);
	freopen("seats.out","w",stdout);
	
	init();
	cout<<yuchuli();
}
