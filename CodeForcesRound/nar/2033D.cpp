#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> dp(n + 1);
    map<ll, pair<int, int>> mp;
    mp[0] = {0, 1};
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        dp[i + 1] = dp[i];
        if (mp[sum].S == 1) dp[i + 1] = max(dp[mp[sum].F] + 1, dp[i + 1]);
        mp[sum] = {i + 1, 1};
    }
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}