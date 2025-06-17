#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<vector<int>> &g, vector<int> &a, vector<int> &dp) {
    for (auto &x : g[v])
        dfs(x, g, a, dp);
    int mn = INF;
    for (auto &x : g[v])
        mn = min(mn, dp[x]);
    if (mn == INF) {
        dp[v] = a[v];
        return;
    }
    if (mn > a[v])
        dp[v] = (mn + a[v]) / 2;
    else
        dp[v] = mn;
    if (v == 0)
        dp[v] = mn + a[v];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> p(n - 1);
    for (auto &x : a)
        cin >> x;
    for (auto &x : p)
        cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
        g[p[i] - 1].push_back(i + 1);
    vector<int> dp(n);
    dfs(0, g, a, dp);
    cout << dp[0] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}