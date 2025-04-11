#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;
vector<int> cnt(1001, INF);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    vector<int> c(n);
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    for (auto &x : b)
        x = cnt[x];
    k = min(k, n * 20);
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
        dp[0][i + 1] = dp[0][i];
        if (b[i] == 0)
            dp[0][i + 1] += c[i];
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (i >= b[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - b[j - 1]][j - 1] + c[j - 1]);
            }
        }
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << dp[k][n] << endl;
}

int main() {
    cnt[0] = 0;
    cnt[1] = 0;
    for (int i = 1; i < cnt.size(); i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j < cnt.size()) {
                cnt[i + i / j] = min(cnt[i + i / j], cnt[i] + 1);
            }
        }
    }
    /*for (auto &x : cnt)
        cout << x << " ";
    cout << endl;*/
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}