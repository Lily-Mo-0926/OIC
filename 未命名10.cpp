#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    
    int q;
    cin >> q;
    
    vector<char> ans(s.begin(), s.end());
    vector<int> last_op_index(n, -1);
    int last_full_index = -1;
    int last_full_type = 0;
    
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int p; char c;
            cin >> p >> c;
            p--; // 转换为0索引
            ans[p] = c;
            last_op_index[p] = i;
        } else {
            int dummy_p; char dummy_c;
            cin >> dummy_p >> dummy_c;
            last_full_index = i;
            last_full_type = t;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (last_full_index == -1) {
            // 无全量转换，直接使用当前字符
            continue;
        }
        if (last_op_index[i] > last_full_index) {
            // 最后一次修改在全量转换之后，保留修改
            continue;
        }
        // 需要根据全量转换类型处理字符
        if (last_full_type == 2) {
            ans[i] = tolower(ans[i]);
        } else if (last_full_type == 3) {
            ans[i] = toupper(ans[i]);
        }
    }
    
    for (char c : ans) {
        cout << c;
    }
    cout << endl;
    
    return 0;
}
