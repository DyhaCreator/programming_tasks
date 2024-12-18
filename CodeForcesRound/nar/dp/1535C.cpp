#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int INF = 1e9 + 7;

void solve() {
    string a;
    cin >> a;
    int n = a.size();
    vector<ll> dp(n);
    vector<ll> dplen(n);
    dplen[0] = (a[0] == '?');
    dp[0] = 1;
    int num = 2;
    if (a[0] == '0') {
        num = 0;
    } else if (a[0] == '1') {
        num = 1;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == '?') {
            if (num == 1) {
                num = 0;
            } else if (num == 0) {
                num = 1;
            }
            dplen[i] = dplen[i - 1] + 1;
            dp[i] = dp[i - 1] + 1;
        } else if (a[i] == '0') {
            if (num == 1) {
                dp[i] = dp[i - 1] + 1;
                num = 0;
            } else if (num == 0) {
                dp[i] = dplen[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1] + 1;
                num = 0;
            }
        } else if (a[i] == '1') {
            if (num == 0) {
                dp[i] = dp[i - 1] + 1;
                num = 1;
            } else if (num == 1) {
                dp[i] = dplen[i - 1] + 1;
            } else {
                dp[i] = dp[i - 1] + 1;
                num = 1;
            }
        }
    }
    ll sum = 0;
    for (auto &x : dp)
        sum += x;
    cout << sum << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}