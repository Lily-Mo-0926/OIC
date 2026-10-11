#include <iostream>
using namespace std;
unsigned short f(unsigned short x) {
    x ^= x << 6;
    cout<<x<<endl; 
    x ^= x >> 8;
    return x;
}
int main() {
    unsigned short x;
    cin >> x;
    unsigned short y = f(x);
    cout << y <<endl;
    return 0;
}
