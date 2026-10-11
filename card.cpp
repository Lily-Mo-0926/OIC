#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    vector<char> have(2 * N + 1, 0);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        have[a[i]] = 1;
    }

    // 小航拥有的牌
    vector<int> B;
    for (int x = 1; x <= 2 * N; x++) {
        if (!have[x]) B.push_back(x);
    }
    sort(B.begin(), B.end());

    // 前 K 轮：较大者获胜，小航需要 出牌 > 阿洛牌
    // 后 N-K 轮：较小者获胜，小航需要 出牌 < 阿洛牌
    vector<int> A1(a.begin(), a.begin() + K);      // 前 K 轮
    vector<int> A2(a.begin() + K, a.end());        // 后 N-K 轮

    sort(A1.begin(), A1.end(), greater<int>());    // 从大到小
    sort(A2.begin(), A2.end());                    // 从小到大

    // Rmatch[p]：用最小的 p 张小航牌，匹配后 N-K 轮（小者赢）的最大胜场数
    vector<int> Rmatch(N + 1, 0);
    int cntR = 0, jR = 0;
    int mR = (int)A2.size();

    for (int p = 1; p <= N; p++) {
        int b = B[p - 1];

        while (jR < mR && A2[jR] <= b) jR++; // 阿洛牌太小，无法被当前及更大牌匹配

        if (jR < mR && A2[jR] > b) {
            cntR++;
            jR++;
        }

        Rmatch[p] = cntR;
    }

    // Lmatch[q]：用最大的 q 张小航牌，匹配前 K 轮（大者赢）的最大胜场数
    vector<int> Lmatch(N + 1, 0);
    int cntL = 0, jL = 0;
    int mL = (int)A1.size();

    for (int q = 1; q <= N; q++) {
        int b = B[N - q]; // 从大到小取

        while (jL < mL && A1[jL] >= b) jL++; // 阿洛牌太大，无法被当前及更小牌匹配

        if (jL < mL && A1[jL] < b) {
            cntL++;
            jL++;
        }

        Lmatch[q] = cntL;
    }

    int ans = 0;

    // 枚举分界点：前 p 张小牌给后 N-K 轮，后 N-p 张大牌给前 K 轮
    for (int p = 0; p <= N; p++) {
        int q = N - p;
        ans = max(ans, Rmatch[p] + Lmatch[q]);
    }

    cout << ans << '\n';

    return 0;
}
