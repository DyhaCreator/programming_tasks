#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<vector<ll>>>dp = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(k, vector<ll>(2)));
    dp[0] = vector<vector<ll>>(k, vector<ll>(2, 1));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < j; l++) {
                dp[i][j][0] += dp[i - 1][l][1];
            }
            for (int l = j + 1; l < k; l++) {
                dp[i][j][1] += dp[i - 1][l][0];
            }
            //cout << dp[i][j][0] << " " << dp[i][j][1] << endl;
        }
        //cout << endl;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += dp[n - 1][i][0] + dp[n - 1][i][1];
    }
    if (n == 1) {
        cout << ans / 2 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}