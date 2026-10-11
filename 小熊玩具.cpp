#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000;
const int MAXN = 39;

int n[4];
int total;
int dp[2][4][4][MAXN][MAXN][MAXN]; 

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> n[i];
        total += n[i];
    }

    if (total == 0) {
        cout << 0 << endl;
        return 0;
    }

    memset(dp, 0, sizeof(dp));
    int cur = 0;

    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (x == y && n[x] < 2) continue;
            if (n[x] < 1 || n[y] < 1) continue;
            int i0 = n[0], i1 = n[1], i2 = n[2], i3 = n[3];
            i0 -= (x == 0) + (y == 0);
            i1 -= (x == 1) + (y == 1);
            i2 -= (x == 2) + (y == 2);
            i3 -= (x == 3) + (y == 3);
            if (i0 < 0 || i1 < 0 || i2 < 0 || i3 < 0) continue;
            dp[cur][x][y][i0][i1][i2] = (dp[cur][x][y][i0][i1][i2] + 1) % MOD;
        }
    }

    for (int s = total - 2; s > 0; s--) {
        int nxt = 1 - cur;
        memset(dp[nxt], 0, sizeof(dp[nxt]));

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                for (int i0 = 0; i0 <= n[0]; i0++) {
                    for (int i1 = 0; i1 <= n[1]; i1++) {
                        for (int i2 = 0; i2 <= n[2]; i2++) {
                            int i3 = s - (i0 + i1 + i2);
                            if (i3 < 0 || i3 > n[3]) continue;
                            if (dp[cur][x][y][i0][i1][i2] == 0) continue;

                            for (int z = 0; z < 4; z++) {
                                int cnt0 = i0, cnt1 = i1, cnt2 = i2, cnt3 = i3;
                                if (z == 0) {
                                    if (cnt0 <= 0) continue;
                                    cnt0--;
                                } else if (z == 1) {
                                    if (cnt1 <= 0) continue;
                                    cnt1--;
                                } else if (z == 2) {
                                    if (cnt2 <= 0) continue;
                                    cnt2--;
                                } else if (z == 3) {
                                    if (cnt3 <= 0) continue;
                                    cnt3--;
                                }

                                bool valid = true;
                                if (x / 2 == y / 2 && y / 2 == z / 2) valid = false;
                                if (x % 2 == y % 2 && y % 2 == z % 2) valid = false;
                                if (!valid) continue;

                                int &next_state = dp[nxt][y][z][cnt0][cnt1][cnt2];
                                next_state = (next_state + dp[cur][x][y][i0][i1][i2]) % MOD;
                            }
                        }
                    }
                }
            }
        }
        cur = nxt;
    }

    int ans = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            for (int i0 = 0; i0 <= n[0]; i0++) {
                for (int i1 = 0; i1 <= n[1]; i1++) {
                    for (int i2 = 0; i2 <= n[2]; i2++) {
                        if (i0 == 0 && i1 == 0 && i2 == 0) {
                            ans = (ans + dp[cur][x][y][i0][i1][i2]) % MOD;
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
