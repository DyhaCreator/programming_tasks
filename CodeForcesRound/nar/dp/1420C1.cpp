#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    reverse(a.begin(), a.end());
    vector<ll> dp(n);
    dp[0] = a[0];
    dp[1] = a[1];
    int mx = 0;
    int mn = 1;
    int j = 0;
    if (dp[j] < dp[1]) j = 1;
    for (int i = 2; i < n; i++) {
        dp[i] = max(a[i], a[i] - a[mn] + dp[mx]);
        if (dp[mx] - a[mn] < dp[j] - a[i]) {
            mx = j;
            mn = i;
        }
        if (dp[i] > dp[j]) j = i;
    }
    ll ans = 0;
    for (auto &x : dp)
        ans = max(ans, x);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}