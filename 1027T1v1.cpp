#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
signed main(){
	File("defend");
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, s;
    cin >> n >> s;
    
    vector<pair<ll, ll>> data(n);
    ll total_a = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> data[i].second >> data[i].first; // 注意：这里first是k_i, second是a_i
        total_a += data[i].second;
    }
    
    // 按照k_i从大到小排序
    sort(data.begin(), data.end(), [](const pair<ll, ll> &x, const pair<ll, ll> &y) {
        return x.first > y.first;
    });
    
    vector<ll> a(n + 1), k(n + 1);
    vector<ll> ceil_val(n + 1), d(n + 1);
    
    for (int i = 1; i <= n; i++) {
        a[i] = data[i - 1].second;
        k[i] = data[i - 1].first;
        ceil_val[i] = (a[i] + k[i] - 1) / k[i]; // ceil(a_i / k_i)
        d[i] = a[i] / k[i]; // floor(a_i / k_i)
    }
    
    // 前缀和数组
    vector<ll> C(n + 1, 0), A(n + 1, 0), Qd(n + 1, 0), Qdk(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        C[i] = C[i - 1] + ceil_val[i];
        A[i] = A[i - 1] + a[i];
        Qd[i] = Qd[i - 1] + d[i];
        Qdk[i] = Qdk[i - 1] + d[i] * k[i];
    }
    
    ll best_profit = 0;
    
    for (int i = 0; i <= n; i++) {
        if (C[i] > s) continue;
        ll t = s - C[i];
        ll R = 0;
        if (i == n) {
            // 所有段都被完全保护
            R = 0;
        } else {
            // 二分查找最大的p
            int low = 0, high = n - i;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (Qd[i + mid] - Qd[i] <= t) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            int p = high;
            
            if (p == n - i) {
                // 所有后n-i段都分配了d_j个防御者
                R = Qdk[n] - Qdk[i];
            } else {
                R = Qdk[i + p] - Qdk[i];
                ll remaining = t - (Qd[i + p] - Qd[i]);
                R += remaining * k[i + p + 1];
            }
        }
        
        ll total_profit = A[i] + R;
        if (total_profit > best_profit) {
            best_profit = total_profit;
        }
    }
    
    ll answer = total_a - best_profit;
    cout << answer << endl;
    
    return 0;
}
