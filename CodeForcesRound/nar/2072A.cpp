#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    if ((abs(k) + p - 1) / p <= n) {
        cout << (abs(k) + p - 1) / p << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}