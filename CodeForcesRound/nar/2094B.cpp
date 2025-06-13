#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    cout << -min(-l, m) << " " << m - min(-l, m) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}