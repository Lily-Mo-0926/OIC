#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    const int MAX_V = 100000; // 最大总价值 = 100 * 1000
    vector<long long> dp(MAX_V + 1, 1e18); // 初始化为极大值
    dp[0] = 0; // 价值0的最小重量为0

    // 动态规划：更新达到每个价值所需的最小重量
    for (int i = 0; i < n; i++) {
        for (int j = MAX_V; j >= v[i]; j--) {
            if (dp[j - v[i]] != 1e18) {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }

    // 寻找不超过背包容量的最大价值
    long long ans = 0;
    for (int j = 0; j <= MAX_V; j++) {
        if (dp[j] <= m) {
            ans = max(ans, (long long)j);
        }
    }

    cout << ans << endl;
    return 0;
}
