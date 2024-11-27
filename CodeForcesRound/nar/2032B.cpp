#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    if (k == 1 || k == n) {
        cout << -1 << endl;
        return;
    }
    if (k <= (n + 1) / 2) {
        cout << 3 << endl;
        cout << 1 << " " << 2 << " " << k * 2 - 1 << endl;
    } else {
        cout << 3 << endl;
        cout << 1 << " " << (n - k) * 2 << " " << n << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}