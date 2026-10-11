#include<bits/stdc++.h>
using namespace std;
const int maxn=2000005,mod=998244353;
int randseed, n, m, Q;
int x[maxn], y[maxn], t[maxn], u[maxn], v[maxn], id[maxn],a[maxn],b[maxn];
int ans=0;
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
    }
}

int baoli(){
	for(int i=1;i<=Q;i++){
		for(int j=1;j<=n;j++){
			a[j]=j,b[j]=j;
		}
		int temu=x[t[i]],temv=y[t[i]];
		x[t[i]]=u[i];
		y[t[i]]=v[i];
		for(int j=1;j<=m;j++){
			b[a[x[j]]]=y[j];
			b[a[y[j]]]=x[j];
			swap(a[x[j]],a[y[j]]);
			
		}
		x[t[i]]=temu;
		y[t[i]]=temv;
		//cout<<b[id[i]]<<endl;
		ans=(ans+i*b[id[i]])%mod;
	}
	return ans;
}
int main(){
	freopen("seats.in","r",stdin);
	freopen("seats.out","w",stdout);
	
	init();
	cout<<baoli();
}
