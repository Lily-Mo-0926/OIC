//感↘↗受↘学↗科→之→↗美↗ 
#include <bits/stdc++.h>
using namespace std;
int n, g, cnt, ans, a[30];
vector<bool> f;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), g = __gcd(g, a[i]);
    if (g != 1)
    {
        printf("-1");
        return 0;
    }
    sort(a + 1, a + n + 1), f.push_back(1);
    for (int i = 1; cnt < a[1]; i++)
    {
        bool flag = 0;
        for (int j = 1; j <= n && a[j] <= i; j++)
            if (f[i - a[j]])
            {
                flag = 1;
                break;
            }
        f.push_back(flag);
        if (flag)
            cnt++;
        else
            cnt = 0, ans++;
    }
    printf("%d", ans);
    return 0;
}

