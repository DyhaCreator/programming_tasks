#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

int f(int n) {
    return ceil((sqrt(1 + 8 * n) - 1) / 2.0);
}

int main() {
    ll n = 2100000;
    vector<ll> dp(n);
    dp[1] = 1;
    for (ll i = 2; i <= 2023; i++) {
        for (ll j = 1; j <= i; j++) {
            if (j == 1) {
                dp[(i - 1) * i / 2 + j] = dp[(i - 2) * (i - 1) / 2 + j];
            } else if (j == i) {
                dp[(i - 1) * i / 2 + j] = dp[(i - 2) * (i - 1) / 2 + j - 1LL];
            } else {
                dp[(i - 1) * i / 2 + j] = dp[(i - 2) * (i - 1) / 2 + j - 1LL] + dp[(i - 2) * (i - 1) / 2 + j] - dp[(i - 3) * (i - 2) / 2 + j - 1LL];
            }
            dp[(i - 1) * i / 2 + j] += ((i - 1) * i / 2 + j) * ((i - 1) * i / 2 + j);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}