#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("bread.in","r",stdin);
	freopen("bread.out","w",stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        if (a[0] < b[0] && b[m-1] > a[n-1]) {
            if (a[n-1] < b[0]) {
                cout << 1 << endl;
            } else {
                if (n >= 2 && m >= 2) {
                    cout << 2 << endl;
                } else {
                    cout << -1 << endl;
                }
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
