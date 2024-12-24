#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a = {};
    while (n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    vector<vector<ll>> dp(a.size(), vector<ll>(4));
    dp[0][0b00] = a[0] + 1;
    dp[0][0b10] = 10 - a[0] - 1;
    for (int y = 1; y < a.size(); y++) {
        dp[y][0b00] = dp[y - 1][0b00] * (a[y] + 1) + dp[y - 1][0b01] * a[y];
        dp[y][0b01] = dp[y - 1][0b10] * (a[y] + 1) + dp[y - 1][0b11] * a[y];
        dp[y][0b10] = dp[y - 1][0b00] * (9 - a[y]) + dp[y - 1][0b01] * (10 - a[y]);
        dp[y][0b11] = dp[y - 1][0b10] * (9 - a[y]) + dp[y - 1][0b11] * (10 - a[y]);
    }
    cout << dp[a.size() - 1][0] - 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}