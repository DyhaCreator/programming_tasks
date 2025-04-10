#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void dfs(int v, vector<vector<int>> &g, vector<vector<int>> &g2, vector<vector<ll>> &dp) {
    dp[v][0] = 1;
    for (auto &x : g[v]) {
        if (dp[x][0] == 0) {
            dfs(x, g, g2, dp);
            for (int i = 1; i < dp[0].size(); i++)
                dp[v][i] += dp[x][i - 1];
            g2[v].push_back(x);
        } 
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<vector<int>> g2(n);
    vector<vector<ll>> dp(n, vector<ll>(k + 1));
    vector<int> cnt(n);
    dfs(0, g, g2, dp);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= (k - 2); j++) {
            ll sum = 0;
            for (auto &x : g2[i])
                sum += dp[x][j];
            ll sum2 = 0;
            for (auto &x : g2[i])
                sum2 += ((sum - (ll)dp[x][j]) * (ll)dp[x][k - 2 - j]);
            ans += sum2;
            // cout << sum2 / 2 << " " << sum << endl;
        }
    }
    ans /= 2;
    for (auto &x : dp)
        ans += x[k];
    cout << ans << endl;
    return 0;
}