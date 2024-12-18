#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    vector<ll> dp(n + 1);
    dp[n] = 0;
    dp[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        dp[i] = min(dp[i + 1] + a[i], dp[i + 1] + b[i + 1] - a[i + 1] + a[i]);
    ll ans = dp[0];
    for (int i = 0; i < m; i++) ans = min(ans, dp[i]);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}