#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("hack.in","r",stdin);
	freopen("hack.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> x(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> r[i];
    }

    vector<int> L(n + 1), dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        long long limit = x[i] - r[i];

        // 在 x[1..i] 中找到第一个 >= limit 的位置
        int pos = lower_bound(x.begin() + 1, x.begin() + i + 1, limit) - x.begin();

        L[i] = pos;
        dp[i] = (i - pos) + dp[pos - 1];
    }

    int ans = n; // m = 0，备用坦克摧毁全部

    for (int m = 1; m <= n; m++) {
        ans = min(ans, n - m + dp[m]);
    }

    cout << ans << '\n';
    return 0;
}
