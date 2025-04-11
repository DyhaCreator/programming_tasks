#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(ll v, ll p, vector<pair<ll, ll>> &a, vector<vector<ll>> &g, vector<pair<ll, ll>> &dp) {
    for (auto &x : g[v]) {
        if (x != p) {
            dfs(x, v, a, g, dp);
            // cout << dp[x].F + abs(a[v].F - a[x].F) << " " << dp[x].S + abs(a[v].F - a[x].S) << endl;
            dp[v].F += max(dp[x].F + abs(a[v].F - a[x].F), dp[x].S + abs(a[v].F - a[x].S));
            dp[v].S += max(dp[x].F + abs(a[v].S - a[x].F), dp[x].S + abs(a[v].S - a[x].S));
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    for (auto &x : a)
        cin >> x.F >> x.S;
    vector<vector<ll>> g(n);
    for (int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<ll, ll>> dp(n);
    dfs(0, -1, a, g, dp);
    cout << max(dp[0].F, dp[0].S) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}