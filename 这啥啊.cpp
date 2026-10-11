#include<bits/stdc++.h>
using namespace std;
const int N = 100100;
vector<int> a[N];
int dfn[N], Log2[N * 3], n, q, tot;
pair<int, int> s[N * 3][20];
void dfs(int x, int dep) {
    s[++tot][0]={dep,x};
    dfn[x]=tot;
    for (int i = 0; i < a[x].size(); i++) {
        if (dfn[a[x][i]] == 0) {
            dfs(a[x][i], dep + 1);
            s[++tot][0]={dep,x};
        }
    }
}
int cal(int l, int r) {
    int k = Log2[r - l + 1];
    return min(s[l][k],s[r-(1<<k)+1][k]).second;
}
int main() {
    int x, y;
    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 0); // 假设 1 为根
    for (int i = 2; i <= tot; i++) {
        Log2[i] = Log2[i >> 1] + 1;
    }
    for (int i = 1; i <= Log2[tot]; i++) {
        for (int j = 1; j + (1 << i) - 1 <= tot; j++) {
            s[j][i]=min(s[j][i-1],s[j+(1<<(i-1))][i-1]);
        }
    }
    for (int i = 1; i <= q; i++) {
        cin >> x >> y;
        if(dfn[x]>dfn[y]){swap(x,y);}
        cout<<cal(dfn[x],dfn[y])<<endl;
    }
    return 0;
}
