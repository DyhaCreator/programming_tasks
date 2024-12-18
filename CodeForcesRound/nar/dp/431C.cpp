#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<ll>> dp(n + 1, vector<ll>(k));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < min(k, i); j++) {
            ll sum = 0;
            for (int l = 0; l <= j; l++)
                sum += dp[i - j - 1][l];
            for (int l = i - j; l < i; l++)
                sum += dp[l][j];
            sum = sum % 1000000007;
            dp[i][j] = sum;
        }
    }
    ll ans = 0;
    for (int i = d - 1; i < k; i++)
        ans = (ans + dp[n][i]) % 1000000007;
    cout << ans << endl;
    return 0;
}