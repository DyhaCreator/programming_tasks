#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<ll> m(n);
    for (auto &x : m)
        cin >> x;
    vector<vector<ll>> dp(n, vector<ll>(2));
    dp[0][0] = f - b;
    dp[0][1] = f - m[0] * a;
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0] - b, dp[i - 1][1] - b);
        dp[i][1] = max(dp[i - 1][1] - (m[i] - m[i - 1]) * a, dp[i - 1][0] - (m[i] - m[i - 1]) * a);
    }
    if (max(dp[n - 1][0], dp[n - 1][1]) > 0) {
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