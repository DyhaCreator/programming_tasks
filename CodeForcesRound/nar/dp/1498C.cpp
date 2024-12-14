#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k, vector<ll>(n + 1));
    for (auto &x : dp) x[0] = 1;
    dp[0] = vector<ll>(n + 1, 1);
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][n - j] + dp[i][j - 1]) % 1000000007;
        }
    }
    /*for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }*/
    cout << dp[k - 1][n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}