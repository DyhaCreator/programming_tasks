#include <algorithm>
#include <iostream>
#include <vector>
#define F first
#define S second
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(vector<pair<ll, ll>> &a, vector<vector<ll>> &g, vector<ll> &used, int last, int index, vector<pair<ll, ll>> &dp) {
    used[index] = 1;
    for (auto &x : g[index])
        if (used[x] == 0) dfs(a, g, used, index, x, dp);
    for (auto &x : g[index]) {
        if (x != last) {
            dp[index].F += max(dp[x].F + abs(a[index].F - a[x].F), dp[x].S + abs(a[index].F - a[x].S));
            dp[index].S += max(dp[x].F + abs(a[index].S - a[x].F), dp[x].S + abs(a[index].S - a[x].S));
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n, {0, 0});
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
    vector<ll> used(n);
    vector<pair<ll, ll>> dp(n);
    dfs(a, g, used, -1, 0, dp);
    cout << max(dp[0].F, dp[0].S) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}