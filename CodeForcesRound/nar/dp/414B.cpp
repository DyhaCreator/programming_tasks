#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> del(n + 1);
    for (int i = 1; i <= n; i++) {
        del[i] = {};
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) del[i].push_back(j);
        }
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto &x : del[j])
                dp[j][i] = (dp[j][i] + dp[x][i - 1]) % 1000000007;
        }
    }
    ll ans = 0;
    for (auto &x : dp)
        ans = (ans + x[k]) % 1000000007;
    cout << ans << endl;
    return 0;
}