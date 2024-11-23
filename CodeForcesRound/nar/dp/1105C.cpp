#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    l--;
    vector<ll> lr = {(r + 3) / 3 - (l + 3) / 3, (r + 2) / 3 - (l + 2) / 3, (r + 1) / 3 - (l + 1) / 3};
    vector<vector<ll>> dp(n + 1, vector<ll>(3));
    dp[1] = lr;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][0] * lr[0] + dp[i - 1][1] * lr[2] + dp[i - 1][2] * lr[1]) % 1000000007;
        dp[i][1] = (dp[i - 1][0] * lr[1] + dp[i - 1][1] * lr[0] + dp[i - 1][2] * lr[2]) % 1000000007;
        dp[i][2] = (dp[i - 1][0] * lr[2] + dp[i - 1][1] * lr[1] + dp[i - 1][2] * lr[0]) % 1000000007;
    }
    cout << dp[n][0] << endl;
    return 0;
}