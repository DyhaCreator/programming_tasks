#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    for (auto &x : map)
        for (auto &y : x)
            cin >> y;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mn = 0;
        for (int j = 0; j <= i; j++) {
            mn = min(mn, map[n - j - 1][i - j]);
        }
        ans += mn;
    }
    for (int i = 0; i < n - 1; i++) {
        int mn = 0;
        for (int j = 0; j <= i; j++) {
            mn = min(mn, map[j][n - (i - j) - 1]);
        }
        ans += mn;
    }
    cout << -ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}