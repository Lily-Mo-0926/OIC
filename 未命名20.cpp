#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin >> k;
    
    vector<vector<int>> sticks(k + 1);
    
    // 读取输入
    for (int i = 1; i <= k; i++) {
        int Ni;
        cin >> Ni;
        sticks[i].resize(Ni);
        for (int j = 0; j < Ni; j++) {
            cin >> sticks[i][j];
        }
        // 对每种颜色的木棍排序
        sort(sticks[i].begin(), sticks[i].end());
    }
    
    // 尝试所有颜色组合
    for (int c1 = 1; c1 <= k; c1++) {
        if (sticks[c1].empty()) continue;
        
        for (int c2 = c1 + 1; c2 <= k; c2++) {
            if (sticks[c2].empty()) continue;
            
            for (int c3 = c2 + 1; c3 <= k; c3++) {
                if (sticks[c3].empty()) continue;
                
                // 对于当前三种颜色，尝试它们各自最大的几根木棍
                // 由于总木棍数有限，我们只需要检查有限组合
                vector<int> colors = {c1, c2, c3};
                vector<int> indices = {
                    (int)sticks[c1].size() - 1,
                    (int)sticks[c2].size() - 1, 
                    (int)sticks[c3].size() - 1
                };
                
                // 检查多个组合
                for (int attempt = 0; attempt < 8; attempt++) {
                    vector<tuple<int, int>> tri(3); // (长度, 颜色)
                    
                    for (int i = 0; i < 3; i++) {
                        int idx = max(0, indices[i] - (attempt >> i & 1));
                        tri[i] = {sticks[colors[i]][idx], colors[i]};
                    }
                    
                    // 排序三边
                    sort(tri.begin(), tri.end());
                    
                    int a = get<0>(tri[0]);
                    int b = get<0>(tri[1]);
                    int c = get<0>(tri[2]);
                    int colorA = get<1>(tri[0]);
                    int colorB = get<1>(tri[1]);
                    int colorC = get<1>(tri[2]);
                    
                    // 检查三角形条件
                    if (a + b > c && colorA != colorB && colorA != colorC && colorB != colorC) {
                        cout << colorA << " " << a << " " 
                             << colorB << " " << b << " "
                             << colorC << " " << c << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    
    // 更简单的方法：遍历所有可能的三元组
    // 由于总木棍数 ≤ 1,000,000，我们可以用更直接的方法
    vector<pair<int, int>> all_sticks;
    for (int i = 1; i <= k; i++) {
        for (int len : sticks[i]) {
            all_sticks.push_back({len, i});
        }
    }
    
    // 按长度排序
    sort(all_sticks.begin(), all_sticks.end());
    
    int n = all_sticks.size();
    
    // 对于每根木棍作为最长边，尝试找到另外两种颜色的较短边
    for (int i = n - 1; i >= 2; i--) {
        int c3 = all_sticks[i].second;
        int len3 = all_sticks[i].first;
        
        // 向前找两种不同颜色的木棍
        int c1 = -1, len1 = -1;
        int c2 = -1, len2 = -1;
        
        for (int j = i - 1; j >= 0; j--) {
            int curr_color = all_sticks[j].second;
            int curr_len = all_sticks[j].first;
            
            if (curr_color == c3) continue;
            
            if (c1 == -1) {
                c1 = curr_color;
                len1 = curr_len;
            } else if (c2 == -1 && curr_color != c1) {
                c2 = curr_color;
                len2 = curr_len;
                break;
            }
        }
        
        if (c1 != -1 && c2 != -1 && len1 + len2 > len3) {
            cout << c1 << " " << len1 << " " 
                 << c2 << " " << len2 << " "
                 << c3 << " " << len3 << "\n";
            return 0;
        }
    }
    
    cout << "NIE\n";
    return 0;
}
