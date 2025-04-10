#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1));
    for (int i = 1; i <= k; i++) {
        for (int j = i * m; j <= n; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + pref[j] - pref[j - m]);
        }
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << dp[k][n] << endl;
    return 0;
}