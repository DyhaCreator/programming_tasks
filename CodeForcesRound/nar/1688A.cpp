#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int x;
    cin >> x;
    int y = 1;
    while ((x & y) == 0)
        y = y << 1;
    if ((x ^ y) == 0) {
        int ans = 1;
        while ((ans ^ x) == 0)
            ans = ans << 1;
        cout << (ans | y) << endl;
    } else {
        cout << y << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}