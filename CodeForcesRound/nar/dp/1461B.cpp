#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(m));
    for (int i = n - 1; i >= 0; i--) {
        if (a[i][0] == '*') dp[i][0] = 1;
        if (a[i][m - 1] == '*') dp[i][m - 1] = 1;
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] == '*')
                dp[i][j] = min(dp[i + 1][j - 1], min(dp[i + 1][j], dp[i + 1][j + 1])) + 1;
        }
    }
    int ans = 0;
    for (auto &x : dp)
        for (auto &y : x)
            ans += y;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}