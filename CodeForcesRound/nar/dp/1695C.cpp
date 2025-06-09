#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &x : a)
        for (auto &y : x)
            cin >> y;
    if ((n + m) % 2 == 0) {
        cout << "NO" << endl;
        return;
    }
    vector<vector<set<int>>> dp(n + 1, vector<set<int>>(m + 1));
    dp[1][1].insert(a[0][0]);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (auto &z : dp[y][x + 1])
                dp[y + 1][x + 1].insert(z + a[y][x]);
            for (auto &z : dp[y + 1][x])
                dp[y + 1][x + 1].insert(z + a[y][x]);
        }
    }
    for (auto &x : dp) {
        for (auto &y : x) {
            for (auto &z : y) {
                cout << z << " ";
            }
            cout << "  ";
        }
        cout << endl;
    }
    int f = 0;
    for (auto &x : dp[n][m]) {
        if (x == 0) {
            f = 1;
            break;
        }
    }
    if (f) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}