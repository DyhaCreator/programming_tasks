#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> c(n);
    for (ll i = 1; i < n - 1; i++)
        c[i] = max(max(a[i - 1] + 1LL - a[i], 0LL), max(a[i + 1] + 1LL - a[i], 0LL));
    vector<ll> dp(n);
    vector<ll> dplen(n);
    dp[1] = c[1];
    dplen[1] = 1;
    for (ll i = 2; i < n - 1; i++) {
        dp[i] = c[i] + dp[i - 2];
        dplen[i] = dplen[i - 2] + 1;
        if (i >= 3 && dplen[i - 3] + 1 >= (i + 1) / 2 && c[i] + dp[i - 3] < dp[i]) {
            dp[i] = dp[i - 3] + c[i];
            dplen[i] = dplen[i - 3] + 1;
        }
    }
    ll ans = dp[n - 2];
    if (dplen[n - 3] >= (n - 1) / 2 && n > 3)
        ans = min(ans, dp[n - 3]);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}