#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(z + 1, vector<int>(k + 1));
    dp[0][0] = a[0];
    for (int i = 1; i <= k; i++)
        dp[0][i] = dp[0][i - 1] + a[i];
    for (int i = 1; i <= z; i++) {
        for (int j = i * 2; j <= k; j++) {
            // cout << dp[i - 1][j - 2] << " " << a[j - i * 2 + 1] << " " << a[j - i * 2] << endl;
            // cout << dp[i][j - 1] << " " << a[j - 2] << endl;
            dp[i][j] = max(dp[i][j - 1] + a[j - i * 2], 
                            dp[i - 1][j - 2] + a[j - i * 2 + 1] + a[j - i * 2]);
        }
    }
    int ans = 0;
    for (auto &x : dp)
        ans = max(ans, x[k]);
    cout << ans << endl;
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}