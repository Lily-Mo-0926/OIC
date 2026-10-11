#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000000+5;
const int P1 = 998244353, P2 = 1000000007;
const int B1 = 2, B2 = 31;
const int K1 = 0, K2 = 13;

typedef long long ll;

int n;
bool p[maxn];
int p1[maxn], p2[maxn];

struct H {
    int h1, h2, l;
    H(bool b = false){
        h1 = b + K1;
        h2 = b + K2;
        l = 1;
    }
    H operator + (const H & h) const {
        H hh;
        hh.l = l + h.l;
        hh.h1 = (1ll * h1 * p1[h.l] + h.h1) % P1;
        hh.h2 = (1ll * h2 * p2[h.l] + h.h2) % P2;
        return hh;
    }
    bool operator == (const H & h) const{
        return l == h.l && h1 == h.h1 && h2 == h.h2;
    }
    bool operator < (const H & h) const {
        if (l != h.l) return l < h.l;
        else if (h1 != h.h1) return h1 < h.h1;
        else return h2 < h.h2;
    }
} h[maxn];

void init(){
    memset(p,1,sizeof(p));
    p[0] = p[1] = false;
    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; ++i){
        p1[i] = (1ll * B1 * p1[i-1]) % P1;
        p2[i] = (1ll * B2 * p2[i-1]) % P2;
        if (!p[i]) continue;
        for (int j = 2 * i; j <= n; j += i){
            p[j] = false;
        }
    }
}

int solve(){
    for (int i = n; i; --i) {
        h[i] = H(p[i]);
        if (2 * i + 1 <= n){
            h[i] = h[2 * i] + h[i] + h[2 * i + 1];
        } else if (2 * i <= n){
            h[i] = h[2 * i] + h[i];
        }
    }
    cout << h[1].h1 << endl;
    sort(h + 1, h + n + 1);
    int m = unique(h + 1, h + n + 1) - (h + 1);
    return m;
}

int main(){
    cin >> n;
    init();
    cout << solve() <<endl;
}
