#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

const int INF = 1e9 + 7;

void solve() {
    ll a, b, n, s;
    cin >> a >> b >> n >> s;
    if (((a + b - 1) / b) * ((a + b - 1) / b) > n * s) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}