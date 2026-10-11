#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> b = a;
    sort(b.begin(), b.end());
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[j]) {
            j++;
        }
    }
    cout << n - j << endl;
    return 0;
}
