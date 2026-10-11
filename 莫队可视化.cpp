#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXV = 1000005;

int a[MAXN], cnt[MAXV], ansArr[MAXN];
int block, ans = 0, moveCount = 0; // moveCount 用来控制调试输出数量
const int DEBUG_LIMIT = 20;        // 只打印前20次移动

struct Query {
    int l, r, id;
} q[MAXN];

// 关键：cmp 排序规则
bool cmp(const Query &x, const Query &y) {
    int bx = x.l / block, by = y.l / block;
    if (bx != by) return bx < by;
    if (bx & 1) return x.r < y.r;   // 奇数块：右端点升序 →
    return x.r > y.r;               // 偶数块：右端点降序 ←
}

inline void add(int pos) {
    if (moveCount++ < DEBUG_LIMIT) 
        cout << "  [移动] 加入位置 " << pos << " (值=" << a[pos] << ")" << endl;
    int v = a[pos];
    if (cnt[v] == 0) ++ans;
    ++cnt[v];
}

inline void del(int pos) {
    if (moveCount++ < DEBUG_LIMIT) 
        cout << "  [移动] 移除位置 " << pos << " (值=" << a[pos] << ")" << endl;
    int v = a[pos];
    --cnt[v];
    if (cnt[v] == 0) --ans;
}

int main() {
    // 为了方便展示，我们手动造一个 N=10 的小数据
    int N = 10;
    int testArr[11] = {0, 1, 2, 1, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i <= N; ++i) a[i] = testArr[i];

    int M = 5;
    // 故意构造 5 个询问，覆盖不同块
    q[1] = {1, 10, 1};
    q[2] = {2, 8, 2};
    q[3] = {9, 10, 3};
    q[4] = {4, 6, 4};
    q[5] = {5, 7, 5};

    block = sqrt(N); // block ≈ 3

    // --- 调试位置①：排序前打印原始顺序 ---
    cout << "【排序前的询问顺序】(L, R)：" << endl;
    for (int i = 1; i <= M; ++i) 
        cout << "  Q" << q[i].id << ": (" << q[i].l << ", " << q[i].r << ")" << endl;
    cout << endl;

    sort(q + 1, q + 1 + M, cmp);

    // --- 调试位置②：排序后打印重排顺序 ---
    cout << "【排序后的询问顺序】(按 cmp 规则)：" << endl;
    cout << "  块大小 block = " << block << endl;
    for (int i = 1; i <= M; ++i) {
        int bx = q[i].l / block;
        cout << "  第 " << i << " 个回答 Q" << q[i].id 
             << ": (" << q[i].l << ", " << q[i].r << ")  [属于块 " << bx << "]" << endl;
    }
    cout << endl;

    cout << "【开始模拟指针移动】（只显示前 " << DEBUG_LIMIT << " 次）" << endl;
    int curL = 1, curR = 0; // 初始空区间

    for (int i = 1; i <= M; ++i) {
        int L = q[i].l, R = q[i].r;
        cout << "\n--- 正在回答 Q" << q[i].id << "，目标区间 [" << L << ", " << R << "] ---" << endl;
        cout << "  当前指针位置: curL=" << curL << ", curR=" << curR << endl;

        // 注意这里移动的顺序：先扩后缩
        while (curL > L) add(--curL);
        getchar(); 
        while (curR < R) add(++curR);
        getchar();
        while (curL < L) del(curL++);
        getchar();
        while (curR > R) del(curR--);
        getchar();

        cout << "  移动完成，当前指针: curL=" << curL << ", curR=" << curR 
             << "，答案 ans=" << ans << endl;
        ansArr[q[i].id] = ans;
    }

    cout << "\n【最终答案】" << endl;
    for (int i = 1; i <= M; ++i) 
        cout << "Q" << i << ": " << ansArr[i] << endl;

    return 0;
}
