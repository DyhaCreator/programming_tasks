#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int y = 0;
    while ((n & (1 << y)) == 0)
        y++;
    int x = 0;
    while ((n & (1 << x)) > 0)
        x++;
    int m = (1 << x) | (1 << y);
    if (n + m > (m ^ n) && n + (m ^ n) > m && (m ^ n) + m > n && m < n) {
        cout << m << endl;
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