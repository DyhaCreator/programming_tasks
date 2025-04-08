#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    vector<int> a = {};
    for (auto &x : s)
        a.push_back(x - '0');
    int n = a.size();
    int ans = 0;
    for (int f = 0; f < 10; f++) {
        for (int s = 0; s < 10; s++) {
            vector<vector<int>> dp(2, vector<int>(n + 1));
            for (int i = 0; i < n; i++) {
                dp[0][i + 1] = dp[0][i];
                dp[1][i + 1] = dp[1][i];
                if (a[i] == f) {
                    dp[0][i + 1] = max(dp[0][i + 1], dp[1][i] + 1);
                }
                if (a[i] == s) {
                    dp[1][i + 1] = max(dp[1][i + 1], dp[0][i] + 1);
                }
            }
            /*cout << f << " " << s << endl;
            for (auto &x : dp[0])
                cout << x << " ";
            cout << endl;
            for (auto &x : dp[1])
                cout << x << " ";
            cout << endl;*/
            if (f != s) {
                ans = max(ans, dp[1][n] - dp[1][n] % 2);
            } else {
                ans = max(ans, dp[1][n]);
            }
        }
    }
    cout << n - ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}