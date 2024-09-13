#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(n + 1, vector<ll> (k + 1));
    for (int i = 1; i < 7; i++) dp[1][i] = 1;
    for (int y = 2; y <= n; y++) {
        ll sum = 0;
        for (int x = 1; x <= k; x++) {
            dp[y][x] = sum;
            sum += dp[y - 1][x];
            if (x >= 6) sum -= dp[y - 1][x - 6];
        }
    }
    for (auto &x : dp) {
        for (auto &y : x)
            cout << y << " ";
        cout << endl;
    }
    cout << (double)dp[n][k] << " " << (1.0 / ((double)(k * n))) << endl;
    return 0;
}